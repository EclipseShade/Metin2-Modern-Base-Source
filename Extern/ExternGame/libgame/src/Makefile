CXX     = g++
BIN_DIR = ../lib
BIN     = $(BIN_DIR)/libgame.a

CFLAGS  = -std=c++11 -Wall -O2 -pipe -fno-exceptions -I../include
LIBS    =

# Specify the source files corresponding to the object files
SRCFILES = grid.cc attribute.cc targa.cc
OBJFILES = $(SRCFILES:.cc=.o)

default: $(BIN)

$(BIN): $(OBJFILES)
	if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dep:
	touch Depend
	$(CXX) $(CFLAGS) -MM $(SRCFILES) > Depend

%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@

sinclude Depend
