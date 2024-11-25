CC=gcc
CXX=g++

PLATFORM = $(shell file /bin/ls | cut -d' ' -f3 | cut -d'-' -f1)
BSD_VERSION = $(shell uname -v 2>&1 | cut -d' ' -f2 | cut -d'.' -f1)

default: libthecore libpoly libgame liblua libsql libserverkey lzo game db quest cryptopp
	@echo "--------------------------------------"
	@echo "Build Done"
	@echo "--------------------------------------"

libserverkey: .
	@touch ../ExternGame/libserverkey/Depend
	$(MAKE) -C ../ExternGame/libserverkey dep
	$(MAKE) -C ../ExternGame/libserverkey clean
	$(MAKE) -C ../ExternGame/libserverkey

liblua: .
	$(MAKE) -C ../ExternGame/liblua clean
	$(MAKE) -C ../ExternGame/liblua

libsql: .
	@touch ../ExternGame/libsql/Depend
	$(MAKE) -C ../ExternGame/libsql dep
	$(MAKE) -C ../ExternGame/libsql clean
	$(MAKE) -C ../ExternGame/libsql

libgame: .
	@touch ../ExternGame/libgame/src/Depend
	$(MAKE) -C ../ExternGame/libgame/src dep
	$(MAKE) -C ../ExternGame/libgame/src clean
	$(MAKE) -C ../ExternGame/libgame/src

libpoly: .
	@touch ../ExternGame/libpoly/Depend
	$(MAKE) -C ../ExternGame/libpoly dep
	$(MAKE) -C ../ExternGame/libpoly clean
	$(MAKE) -C ../ExternGame/libpoly

libthecore: .
	@touch ../ExternGame/libthecore/src/Depend
	$(MAKE) -C ../ExternGame/libthecore/src dep
	$(MAKE) -C ../ExternGame/libthecore/src clean
	$(MAKE) -C ../ExternGame/libthecore/src
	
lzo: .
	$(MAKE) -C ../ExternGame/lzo clean
	$(MAKE) -C ../ExternGame/lzo

cryptopp: .
	@touch ../ExternGame/cryptopp565/Depend
	$(MAKE) -C ../ExternGame/cryptopp565 dep
	$(MAKE) -C ../ExternGame/cryptopp565 clean
	$(MAKE) -C ../ExternGame/cryptopp565
	
game: .
	@touch game/Depend
	$(MAKE) -C game dep
	$(MAKE) -C game clean
	$(MAKE) -C game

db: .
	@touch db/Depend
	$(MAKE) -C db dep
	$(MAKE) -C db clean
	$(MAKE) -C db
	
quest: .
	@touch quest/Depend
	$(MAKE) -C quest clean
	$(MAKE) -C quest

clean:
	$(MAKE) -C ../ExternGame/libthecore/src clean
	$(MAKE) -C ../ExternGame/libgame/src clean
	$(MAKE) -C ../ExternGame/cryptopp565 clean
	$(MAKE) -C ../ExternGame/libpoly clean
	$(MAKE) -C ../ExternGame/liblua clean
	$(MAKE) -C ../ExternGame/libsql clean
	$(MAKE) -C ../ExternGame/lzo clean
	
	$(MAKE) -C db clean
	$(MAKE) -C game clean
	$(MAKE) -C quest clean

all: 
	@echo "--------------------------------------"
	@echo "Full Build Start"
	@echo "--------------------------------------"

	$(MAKE) -C ../ExternGame/liblua clean
	$(MAKE) -C ../ExternGame/liblua

	@touch ../ExternGame/libsql/Depend
	$(MAKE) -C ../ExternGame/libsql dep
	$(MAKE) -C ../ExternGame/libsql clean
	$(MAKE) -C ../ExternGame/libsql

	@touch ../ExternGame/libgame/src/Depend
	$(MAKE) -C ../ExternGame/libgame/src dep
	$(MAKE) -C ../ExternGame/libgame/src clean
	$(MAKE) -C ../ExternGame/libgame/src

	@touch ../ExternGame/libpoly/Depend
	$(MAKE) -C ../ExternGame/libpoly dep
	$(MAKE) -C ../ExternGame/libpoly clean
	$(MAKE) -C ../ExternGame/libpoly 

	@touch ../ExternGame/libthecore/src/Depend
	$(MAKE) -C ../ExternGame/libthecore/src dep
	$(MAKE) -C ../ExternGame/libthecore/src clean
	$(MAKE) -C ../ExternGame/libthecore/src

	$(MAKE) -C ../ExternGame/lzo clean
	$(MAKE) -C ../ExternGame/lzo

	@touch ../ExternGame/cryptopp565/Depend
	$(MAKE) -C ../ExternGame/cryptopp565 dep
	$(MAKE) -C ../ExternGame/cryptopp565 clean
	$(MAKE) -C ../ExternGame/cryptopp565
	
	@touch game/Depend
	$(MAKE) -C game dep
	$(MAKE) -C game clean
	$(MAKE) -C game

	@touch db/Depend
	$(MAKE) -C db dep
	$(MAKE) -C db clean
	$(MAKE) -C db
	
	@touch quest/Depend
	$(MAKE) -C quest clean
	$(MAKE) -C quest

	@echo "--------------------------------------"
	@echo "Full Build End"
	@echo "--------------------------------------"
