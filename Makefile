NAME = libasm.a

SRC = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_read.s ft_write.s ft_strdup.s

OBJS = $(SRC:.s=.o)

NASM = nasm -f elf64

CC = gcc -Wall -Wextra -Werror

%.o: %.s
	$(NASM) $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf mine
	rm -rf real

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

run: crun all
	$(CC) -no-pie main.c -L. -lasm
	./a.out

crun: fclean
	rm -rf a.out

.PHONY: all run clean fclean re crun
