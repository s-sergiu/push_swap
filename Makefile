NAME= push_swap
BONUS = bonus

CC= cc
FLAGS= -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/push.o \
	 obj/swap.o \
	 obj/rotate.o \
	 obj/rev_rotate.o \
	 obj/input_checks.o \
	 obj/create_stack.o \
	 obj/sort.o 

BONUS_OBJ= obj/checker.o \
		   obj/push.o \
		   obj/swap.o \
		   obj/rotate.o \
		   obj/rev_rotate.o \
		   obj/input_checks.o \
		   obj/create_stack.o \
		   obj/sort.o \
		   obj/gnl.o

LIBFT= obj/libft.o
GNL= obj/gnl.o

LIBFT_DIR= src/libft
GNL_DIR= src/gnl

all: $(NAME)
	
$(BONUS): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o checker

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c -o $@ $^

$(GNL): src/libft/*.c
	make -C $(GNL_DIR)
	cp $(GNL_DIR)/gnl.a ./obj/gnl.o
	make fclean -C $(GNL_DIR)

$(LIBFT): src/libft/*.c
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./obj/libft.o
	make fclean -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: clean all

.PHONY: bonus all clean fclean re
