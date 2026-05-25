CC = gcc
SRCS = main.c joc.c
OUT = 3T
PKG_CONFIG ?= pkg-config
PKG_CFLAGS := $(shell $(PKG_CONFIG) --cflags raylib 2>/dev/null || echo "")
PKG_LDFLAGS := $(shell $(PKG_CONFIG) --libs raylib 2>/dev/null || echo "-lraylib -lGL -lm -lpthread -ldl -lrt -lX11")

CFLAGS = $(PKG_CFLAGS) -Wall -g
LDFLAGS = $(PKG_LDFLAGS)

.PHONY: all clean

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(SRCS) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)
