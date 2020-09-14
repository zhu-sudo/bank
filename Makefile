CC=gcc
STD=-std=gnu99
FLAG=-Wall -Werror
LIBS=
LIB_PATH=
INCLUDE=
BIN=server open destory login unlock save take transfer query modify client

all:$(BIN)

%:%.c msg_queue.h tools.h zbank.h
	$(CC) $(STD) $(FLAG) $< msg_queue.c tools.c -o $@

clean:
	rm -rf $(BIN) *.o *.h.gch
