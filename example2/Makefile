CFLAGS = -ggdb -Wall -Wextra -pedantic -Wconversion -Wsign-conversion
DEFINES = -DDEBUGGA
INCLUDES = -I.. -I/opt/local/include/
LIBS = -lstdc++
EXAMPLE = dataplot.o
CC=g++

.cpp.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) $<

all:  dataplot

dataplot.o:	dataplot.cpp

dataplot: $(EXAMPLE)
	$(CC) -o $@ $(CFLAGS) $(EXAMPLE) $(LIBS)

clean: 
	rm -f $(EXAMPLE) dataplot
