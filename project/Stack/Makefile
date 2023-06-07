CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = LLS.c Calculator.c Test_Calculator.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c Calculator.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY : run all clean

clean :
	del $(OBJS) $(DEPS) $(TARGET).exe

run : all
	$(TARGET)
