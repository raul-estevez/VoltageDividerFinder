CC = gcc
IDIR = src/include
CFLAGS = -I$(IDIR)

SOURCES = src/main.c src/include/algorithm.c src/include/cliargs.c src/include/read_file.c
OBJECTS = main.o algorithm.o cliargs.o read_file.o

all : vdf

install :  
	mkdir /opt/vdf
	cp vdf /opt/vdf
	ln -f -s /opt/vdf/vdf /usr/local/bin

uninstall :
	rm /usr/local/bin/vdf
	rm -r /opt/vdf

vdf: $(OBJECTS)
	$(CC) -o vdf $(CFLAGS) $^
	mkdir obj
	mv $(OBJECTS) obj 

$(OBJECTS) : $(SOURCES)
	$(CC) -c $^

.PHONY: clean

clean :
	rm -r obj 
	rm vdf
