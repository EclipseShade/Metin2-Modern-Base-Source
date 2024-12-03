CXX     = g++

PLATFORM = $(shell file /bin/ls | cut -d' ' -f3 | cut -d'-' -f1)

GCC_VERSION = $(shell $(CXX) --version 2>&1 | grep "(GCC)" | cut -d' ' -f3  | cut -d'.' -f1)
BSD_VERSION = $(shell uname -v 2>&1 | cut -d' ' -f2 | cut -d'.' -f1)
SVN_VERSION = $(shell svnversion -n -c . | cut -d':' -f2)

BIN     = ./libsql.a

CFLAGS  = -Wall -O2 -pipe -D_THREAD_SAFE -fno-exceptions 

LIBS =

OBJFILES = AsyncSQL.o Semaphore.o Tellwait.o Statement.o

default: $(BIN)

$(BIN): $(OBJFILES)
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dep:
	touch Depend
	$(CXX) $(CFLAGS) -MM *.cpp > Depend

# Pattern rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

sinclude Depend
