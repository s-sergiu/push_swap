NAME= push_swap
CC= cc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/checkers.o \
	 obj/create_stack.o \
	 obj/instruction_set_a.o \
	 obj/instruction_set_b.o \
	 obj/instruction_set_c.o \
	 obj/gnl.o \
	 obj/sort.o \

LIBFT= obj/libft.o
GNL= obj/gnl.o
LIBFT_DIR= src/libft
GNL_DIR= src/gnl



all: $(NAME)
	
$(NAME): $(LIBFT) $(OBJ) $(GNL)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

obj/%.o: src/%.c
	$(CC) -c -o $@ $^

$(LIBFT): src/libft/*.c
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./obj/libft.o
	make fclean -C $(LIBFT_DIR)

$(GNL): $(GNL_DIR)/*c
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/gnl.a ./obj/gnl.o
	@make fclean -C $(GNL_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(GNL)

re: clean all

.PHONY: bonus all clean fclean re
