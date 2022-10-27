NAME= push_swap
BONUS = bonus


CYAN=\033[0;36m
GREEN=\033[0;32m
MAGENTA=\033[0;35m
ENDCOLOR=\033[0m

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
	 obj/free_utils.o \
	 obj/error_handling.o \
	 obj/loops.o

BONUS_OBJ= obj/bonus/checker.o \
		   obj/bonus/push.o \
		   obj/bonus/swap.o \
		   obj/bonus/rotate.o \
		   obj/bonus/rev_rotate.o \
		   obj/bonus/input_checks.o \
		   obj/bonus/create_stack.o \
		   obj/bonus/free_utils.o

LIBFT= obj/libft/libft.o
GNL= obj/gnl/gnl.o
BONUS_FILE=checker

LIBFT_DIR= src/libft
GNL_DIR= src/gnl
NAME_H= include/push_swap.h
BONUS_H= include/checker.h

all: $(NAME)
	
$(BONUS): $(BONUS_FILE)

$(BONUS_FILE): $(LIBFT) $(BONUS_OBJ) $(GNL) $(BONUS_H)
	@echo "$(GREEN)Building $@ $(ENDCOLOR)"
	@$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) $(GNL) -o checker

$(NAME): $(LIBFT) $(OBJ) $(NAME_H) 
	@echo "$(GREEN)Building $@ $(ENDCOLOR)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

obj/%.o: src/%.c 
	@echo "$(CYAN)Creating $@ $(ENDCOLOR)"
	@if  [ ! -d obj/bonus ]; then \
		mkdir obj/bonus; \
	fi
	@if  [ ! -d obj ]; then \
		mkdir obj/; \
	fi
	@$(CC) $(FLAGS) -c -o $@ $^

$(GNL): $(GNL_DIR)/*.c
	@if  [ ! -d obj/gnl ]; then \
		mkdir -p obj/gnl; \
	fi
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/gnl.a $(GNL)
	@make fclean -C $(GNL_DIR)

$(LIBFT): $(LIBFT_DIR)/*.c 
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT) $(GNL)

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS_FILE)

re: clean all

.PHONY: bonus all clean fclean re


