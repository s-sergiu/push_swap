NAME= push_swap
CC= gcc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/input_parser.o \
	 obj/instructions.o \

LIBFT= obj/libft.o
LIBFT_DIR= src/libft



all: $(NAME)
	
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

obj/%.o: src/%.c
	$(CC) -c -o $@ $^

$(LIBFT): src/libft/*.c
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./obj/libft.o
	make fclean -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: clean all

.PHONY: bonus all clean fclean re
