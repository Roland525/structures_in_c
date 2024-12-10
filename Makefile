CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c file_change.c student_add.c student_sorting.c student_change.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main
