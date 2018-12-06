#
# Makefile for Test
#

SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
OBJS 	= $(patsubst %.c, %.o, $(SOURCES))

#TOOL_PREFIX 	= arm-linux-gnueabihf-
#COMPILE_TOOLS	= $(TOOL_PREFIX)gcc
#AR 				= $(TOOL_PREFIX)ar
#RANLIB 			= $(TOOL_PREFIX)ranlib
COMPILE_TOOLS	= gcc
AR 				= ar
RANLIB 			= ranlib

IFLAG = -I. -I./include
CFLAGS 	= $(IFLAG) -g -Wall

BIN = test
$(BIN) : $(OBJS)
	$(COMPILE_TOOLS) -o $@ $(OBJS)
%.o:%.c
	$(COMPILE_TOOLS) $(CFLAGS) -c $^ -o $@ 

clean :
	rm -f src/*.o  $(BIN)	
