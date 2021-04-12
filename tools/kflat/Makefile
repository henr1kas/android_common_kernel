all: flatcheck

main.o: main.cpp aot.h aot_replacements.h aot_log.h stringset.h
	clang++ -c -o main.o -Wall -ggdb3 -Wno-missing-declarations -Wno-gcc-compat main.cpp

rbtree.o: rbtree.c rbtree.h
	clang -c -o rbtree.o -Wall -ggdb3 rbtree.c
	
flatcheck: main.o rbtree.o
	clang++ -o flatcheck main.o rbtree.o -lm
clean:
	rm -f flatcheck main.o rbtree.o