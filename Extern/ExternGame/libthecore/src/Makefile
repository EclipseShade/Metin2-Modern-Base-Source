CC      = g++
BIN_DIR  = ../lib
BIN      = $(BIN_DIR)/libthecore.a
INCLUDE  = ../include

CFLAGS   = -std=c++11 -Wall -O2 -pipe -g -I$(INCLUDE)

LIBS     = 

OBJFILES = socket.o fdwatch.o buffer.o signal.o log.o utils.o \
           kstbl.o hangul.o heart.o main.o tea.o des.o gost.o

default: $(BIN)

$(BIN): $(OBJFILES)
	mkdir -p $(BIN_DIR)
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

dep:
	$(CC) $(CFLAGS) -MM *.c > Depend

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

memcpy: utils.o log.o
	$(CC) $(CFLAGS) -c -D__MAIN__ memcpy.c
	$(CC) $(CFLAGS) -o memcpy utils.o log.o memcpy.o

sinclude Depend
