##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for mysh
##

NAME = asm

CC = gcc

FLAGS =  -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
			-Wno-unused-parameter -I./include

SRC = $(shell find src/ -type f -name "*.c")

OBJ = $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME):	$(OBJ)
			 $(CC) $(FLAGS) -o $(NAME) $(OBJ) -g

obj/%.o: src/%.c
		@mkdir -p $(dir $@)
		@$(CC) -c -o $@ $< $(FLAGS) -g

clean:
		@rm -rf obj

fclean: clean
		@rm -f $(NAME)

re: fclean all
