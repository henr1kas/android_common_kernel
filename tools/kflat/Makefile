all: flatcheck
	
flatcheck: main.c aot.h aot_replacements.h aot_log.h stringset.h
	clang -o flatcheck -Wall main.c rbtree.c -lm -ggdb3 -Wno-missing-declarations -Wno-gcc-compat
clean:
	rm -f flatcheck