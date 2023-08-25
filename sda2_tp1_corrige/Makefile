.PHONY: all clean archive cleanall
CFLAGS=-std=gnu11 -pedantic -O3 -march=native -Wall -Wextra -g
TARGETS=$(patsubst %.c,%,$(wildcard *_sort*.c))

all: $(TARGETS) Makefile

%: %.o main.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o $(TARGETS)

main.o: main.c time_helper.h custom_sort.h array.h Makefile
bubble_sort.o: bubble_sort.c custom_sort.h array.h Makefile
shaker_sort.o: shaker_sort.c custom_sort.h array.h Makefile
binary_sort.o: binary_sort.c custom_sort.h array.h Makefile
merge_sort.o: merge_sort.c custom_sort.h array.h Makefile
quick_sort.o: quick_sort.c custom_sort.h array.h Makefile

BN=$(shell basename $(shell pwd))
archive:
	tar -czf $(BN).tar.gz --transform="s,^,$(BN)/," *.c *.h sujet.pdf Makefile test

cleanall: clean
	rm -rf *.tar.gz
