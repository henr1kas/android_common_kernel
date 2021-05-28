import re
import os
import json

def normalize_loc(loc):
	loc = os.path.normpath(loc.split(":")[0])
	if os.path.isabs(loc):
		return loc[len(kroot)+1:]
	return loc

with open(dbpath,"r") as f:
	db = json.loads(f.read())
G = db["globals"]
gL = [(x["name"],normalize_loc(x["location"]),x["linkage"],x["hash"]) for x in G]
for i,g in enumerate(gL):
	gvname = g[0]
	gvpath = ""
	hsh = g[3]
	if g[2]=="internal":
		gvpath = g[1]
	try:
		addr = 0
		sym = ""
		if gvpath!="":
			s = gdb.execute("p &'%s'::%s"%(gvpath,gvname),False,True).strip()
			addrre = re.compile("0x[0-9abcdef]+")
			sval = s.split()
			for i in range(3):
				if addrre.match(sval[-1-i]):
					addr = int(sval[-1-i][2:],16)
					sym = "'%s'::%s"%(gvpath,gvname)
					break
			else:
				raise Exception("Couldn't extract symbol address: \"%s\""%(s))
		else:
			s = gdb.execute("info address %s"%(gvname),False,True).strip()
			if "is static storage at address" in s:
				addr = int(s.split("at address")[1].strip()[:-1][2:],16)
				sym = gvname
			elif "in a file compiled without debugging" in s:
				addr = int(s.split("is at")[1].split()[0][2:],16)
				sym = gvname
			else:
				raise Exception("Couldn't parse gdb output: \"%s\""%(s))
		if addr<0xffffffff00000000:
			continue
		print("0x%lx : %s : %s"%(addr,sym,hsh))
		print
	except Exception as e:
		#print("***** Couldn't find address of global variable %s\n"%(gvname))
		#print(e)
		pass