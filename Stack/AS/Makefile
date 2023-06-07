CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = AS.c Test_AS.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c AS.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY: clean run all

clean : 
	del $(TARGET) $(OBJS) $(DEPS)

run : all
	$(TARGET)
