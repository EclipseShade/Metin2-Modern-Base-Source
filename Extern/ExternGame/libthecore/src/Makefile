# Compiler and Directories
CC      = g++
BIN_DIR  = ../lib
BIN      = $(BIN_DIR)/libthecore.a
INCLUDE  = ../include

# Compiler Flags
CFLAGS   = -std=c++11 -Wall -O2 -pipe -g -I$(INCLUDE)

# Libraries (if any)
LIBS     = 

# Source Files and Object Files
SRCFILES = socket.c fdwatch.c buffer.c signal.c log.c utils.c \
           kstbl.c hangul.c heart.c main.c tea.c des.c gost.c
OBJFILES = $(SRCFILES:.c=.o)

# Default target
default: $(BIN)

# Library target
$(BIN): $(OBJFILES)
	mkdir -p $(BIN_DIR)
	ar cru $@ $^ $(LIBS)
	ranlib $@
	chmod 700 $@

# Clean target
clean:
	rm -f $(OBJFILES) $(BIN)

# Dependency generation
dep:
	$(CC) $(CFLAGS) -MM $(SRCFILES) > Depend

# Object file compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Special target for memcpy
memcpy: utils.o log.o
	$(CC) $(CFLAGS) -D__MAIN__ -o $@ utils.o log.o

# Include dependencies
sinclude Depend

.PHONY: default clean dep memcpy
