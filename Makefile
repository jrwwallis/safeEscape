all: testLibSafeEscape

.PHONY: clean

CFLAGS = -Wall -Werror -fpic

SOURCES = testSafeEscape.c libSafeEscape.c


.depend: $(SOURCES)
	rm -f ./.depend
	gcc $(CFLAGS) -MM $^>>./.depend;
include .depend

%.so: libSafeEscape.o
	gcc -shared -o $@ $?

testLibSafeEscape: libSafeEscape.so testSafeEscape.o
	gcc -L. -Wl,-rpath=. -Wall -o testSafeEscape testSafeEscape.o -lSafeEscape

clean:
	rm -f .depend *.o *.so testSafeEscape *~
