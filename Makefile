NAME= push_swap
BONUS = bonus

CC= cc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/push.o \
	 obj/swap.o \
	 obj/rotate.o \
	 obj/rev_rotate.o \
	 obj/input_checks.o \
	 obj/create_stack.o \
	 obj/sorting_algorithm.o \
	 obj/sorting_utils.o \
	 obj/indexing_utils.o \
	 obj/list_utils.o \
	 obj/loops.o

BONUS_OBJ= obj/bonus/checker.o \
		   obj/bonus/push.o \
		   obj/bonus/swap.o \
		   obj/bonus/rotate.o \
		   obj/bonus/rev_rotate.o \
		   obj/bonus/input_checks.o \
		   obj/bonus/create_stack.o 

LIBFT= obj/libft/libft.o
GNL= obj/gnl/gnl.o
BONUS_FILE=checker

LIBFT_DIR= src/libft
GNL_DIR= src/gnl
NAME_H= include/push_swap.h
BONUS_H= include/checker.h

all: $(NAME)
	
$(BONUS): $(BONUS_FILE)

$(BONUS_FILE): $(LIBFT) $(BONUS_OBJ) $(BONUS_H) $(GNL)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(GNL) -o checker

$(NAME): $(LIBFT) $(OBJ) $(NAME_H)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c -o $@ $^

$(GNL): $(GNL_DIR)/*.c
	make -C $(GNL_DIR)
	cp $(GNL_DIR)/gnl.a $(GNL)
	make fclean -C $(GNL_DIR)

$(LIBFT): $(LIBFT_DIR)/*.c
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIBFT)
	make fclean -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT) $(GNL)

fclean: clean
	$(RM) $(NAME) $(BONUS_FILE)

re: clean all

.PHONY: bonus all clean fclean re
