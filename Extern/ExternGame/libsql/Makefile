CXX     = g++

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
