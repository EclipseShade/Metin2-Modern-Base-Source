CXX	= g++

BIN     = ./libserverkey.a
 
CFLAGS  = -std=c++11 -Wall -O2 -pipe -D_THREAD_SAFE -fno-exceptions 

LIBS =

OBJFILES = base64_ssl.o RSACrypto.o

default:
	$(MAKE) $(BIN)

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

$(OBJFILES):
	$(CXX) $(CFLAGS) -c $<

sinclude Depend
