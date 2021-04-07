print("Detecting kernel flatten image function pointers (gdb {})".format(gdb.VERSION))
import struct
with open(imgpath,"rb") as f:
	hdr = f.read(64)
memory_size, ptr_count, fptr_count, root_addr_count, this_addr, fnsize, magic = struct.unpack('QQQQQQQ', hdr[8:64])
assert magic==5065495511331851776, "Invalid magic in flattened image"
print("Flatten magic: OK")
try:
	s = gdb.execute("info address flatten_base_function_address",False,True)
except Exception as e:
	print(e)
	sys.exit(0)
vmlinux_fdi_addr = int(s.split()[-1].strip(".").strip()[2:],16)
kernel_load_addr = this_addr - vmlinux_fdi_addr
print("Kernel load address: %lx"%(kernel_load_addr))
print("Found %d function pointers"%(fptr_count))
fptrMap = {}
with open(imgpath, "rb") as f:
	f.seek(64+root_addr_count*8+ptr_count*8)
	u = list(struct.unpack('%dQ'%(fptr_count), f.read(fptr_count*8)))
	f.seek(64+root_addr_count*8+ptr_count*8+fptr_count*8)
	img = f.read(memory_size)
	vmlinux_fptrs = [struct.unpack('Q',img[i:i+8])[0]-kernel_load_addr for i in u]
	import re
	smre = re.compile("(\w+)\sin\ssection\s.text$")
	for vp in vmlinux_fptrs:
		try:
			s = gdb.execute("info symbol 0x%lx"%(vp),False,True).strip()
			m = smre.match(s)
			if m:
				fsym = m.groups()[0]
				fsL = gdb.execute("info fun %s"%(fsym),False,True).strip().split("\n\n")[1:]
				for fs in fsL:
					kfn = fs.split(":")[0].split("File ")[1]
					sdi = gdb.execute("p '%s'::%s"%(kfn,fsym),False,True).strip()
					addr = int(sdi.split()[-2][2:],16)
					if (addr==vp):
						print("Successfully matched function pointer 0x%lx to function %s::%s"%(vp,kfn,fsym))
						fptrMap[addr+kernel_load_addr] = "%s::%s"%(kfn,fsym)
						break
				else:
					print("Couldn't match symbol at vmlinux address 0x%lx: %s\n",vp,str(fsL))
			else:
				print("Couldn't match symbol at vmlinux address 0x%lx: [%s]\n",vp,s)
		except Exception as e:
			print("Couldn't find symbol at vmlinux address: 0x%lx\n",vp)
			print(e)
			print("Skipping...")
print("# Summary:")
print("Matched %d/%d function pointers"%(len(fptrMap),fptr_count))
if len(fptrMap)!=fptr_count:
	print("WARNING: some function pointers were not matched and will not be replaced")
fptrmapsz = 8+len(fptrMap)*8*2+sum([len(x) for x in fptrMap.values()])
with open(imgpath, "r+b") as f:
	#f.seek(0,2)
	f.seek(64+root_addr_count*8+ptr_count*8+fptr_count*8+memory_size)
	f.write(struct.pack("Q",len(fptrMap))) # Number of elements
	for k,v in fptrMap.items():
		f.write(struct.pack("Q",k)) # function pointer address
		f.write(struct.pack("Q",len(v))) # length of the file::function_name string
		f.write(struct.pack("%ds"%(len(v)),str.encode(v))) # actual string
	f.seek(48)
	f.write(struct.pack("Q",fptrmapsz))