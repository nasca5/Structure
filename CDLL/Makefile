CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = CDLL.c Test_CDLL.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c CDLL.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY: clean run all

clean : 
	del $(TARGET) $(OBJS) $(DEPS)

run : all
	$(TARGET)
