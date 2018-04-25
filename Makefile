IDIR = inc
SDIR = src
ODIR = obj
TDIR = test

CC = gcc
CFLAGS = -I$(IDIR)

_DEPS = sasTrace.h sasTraceInit.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

sasTrace: $(SDIR)/sasTrace.c $(DEPS)
	gcc -c -o $(ODIR)/sasTrace.o $(SDIR)/sasTrace.c $(CFLAGS)

sasTraceTest: $(TDIR)/sasTraceTest.c $(DEPS)
	gcc -c -o $(ODIR)/sasTraceTest.o $(TDIR)/sasTraceTest.c $(CFLAGS)

main: sasTraceTest sasTrace $(DEPS)
	gcc -o main $(ODIR)/sasTraceTest.o $(ODIR)/sasTrace.o $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
