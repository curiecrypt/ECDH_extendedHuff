####  Makefile for compilation on Unix-like operative systems  ####

CC=gcc

AR=ar rcs
RANLIB=ranlib

CFLAGS+= -std=gnu11 -g $(INCLUDES)

OBJECTS_HUFF= objshuff/ecfp.o

all: libhuff tests

objshuff/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@


libhuff: $(OBJECTS_HUFF)
	rm -rf libhuff exthuff
	mkdir libhuff exthuff
	$(AR) libhuff/libhuff.a $^
	$(RANLIB) libhuff/libhuff.a

tests: libhuff
	$(CC) $(CFLAGS) -L./libhuff -lhuff -o exthuff/test_HUFF

check: tests


.PHONY: clean

clean:
	rm -rf *.req *.o objshuff* objs libhuff* exthuff*
