CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = DLL.c Test_DLL.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c DLL.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY: clean run all

clean : 
	del $(TARGET) $(OBJS) $(DEPS)

run : all
	$(TARGET)

# main : Linked_List.o Test_LinkedList.o 
# 	gcc -o main Linked_List.o Test_LinkedList.o 

# Linked_List.o : Linked_List.c LinkedList.h
# 	gcc -c -g Linked_List.c

# Test_LinkedList.o : Test_LinkedList.c LinkedList.h
# 	gcc -c -g Test_LinkedList.c

# run : 
