CXX = g++

GCC_VERSION = $(shell $(CXX) --version 2>&1 | grep "(GCC)" | cut -d' ' -f3  | cut -d'.' -f1)

BIN = ./libpoly.a

CFLAGS = -Wall -O2 -pipe -fno-exceptions -fno-rtti

LIBS =

OBJFILES = Base.o Poly.o SymTable.o Symbol.o

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
	$(CXX) $(CFLAGS) -MM *.cc > Depend

# Pattern rule for compiling .cc files to .o files
%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@

sinclude Depend
