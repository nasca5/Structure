CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = LLS.c Test_LLS.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c LLS.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY : run all clean

clean :
	del $(OBJS) $(DEPS) $(TARGET)

run : all
	$(TARGET)
