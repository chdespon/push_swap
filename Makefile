NAME1		= push_swap

NAME2		= checker

CC =		clang

SRCS_DIR = $(shell find srcs -type d)

PUSH_SWAP_SRC_DIR = $(shell find srcs/push_swap -type d)

CHECKER_SRC_DIR = 	$(shell find srcs/checker -type d)

INC_DIR =	$(shell find includes -type d) \
			$(shell find libft/includes -type d)\

LIB_DIR =	libft

PUSH_SWAP_OBJ_DIR = objs/push_swap_obj
CHECKER_OBJ_DIR = objs/checker_obj

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)


# List de toute les library a linker au projet (le nom - le lib et - le .a)
LIB = ft

# SRC = $(foreach dir, $(SRCS_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

CHECKER_SRC	=	checker.c quit.c parse_arg.c op_push.c op_swap.c op_rotate.c op_reverse.c \
				engine_constructeur.c set_stack_a.c read_output.c op_utils.c is_sort.c \
				print_stacks.c

PUSH_SWAP_SRC =	push_swap.c op_push.c op_swap.c op_rotate.c op_reverse.c engine_constructeur.c \
				quit.c set_stack_a.c parse_arg.c resolve_stack.c print_op.c sort_stack_a.c \
				resolve_5.c resolve_3.c resolve_100.c chunks.c resolve_500.c push_chunk_to_a.c \

# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_DIR)/, $(PUSH_SWAP_SRC:%.c=%.o))

CHECKER_OBJ = $(addprefix $(CHECKER_OBJ_DIR)/, $(CHECKER_SRC:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib))

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME1) $(NAME2)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(PUSH_SWAP_SRC) || $(CHECKER_SRC)$(_WHITE)"
				@echo "$(_BLUE)SRC_DIR :\n$(_YELLOW)$(PUSH_SWAP_SRC_DIR) || $(CHECKER_SRC_DIR)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(PUSH_SWAP_OBJ) || $(CHECKER_OBJ)$(_WHITE)"
				@echo "$(_BLUE)OBJ_DIR :\n$(_YELLOW)$(PUSH_SWAP_OBJ_DIR) || $(CHECKER_OBJ_DIR)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)INC_DIR :\n$(_YELLOW)$(INC_DIR)$(_WHITE)"

libft/libft.a:
				@echo -n "$(_CYAN)"
				$(foreach dir, $(LIB_DIR), make --no-print-directory -C $(dir) ; )
				@echo -n "$(_WHITE)"

re-install:
				@echo "$(_CYAN)"
				$(foreach dir, $(LIB_DIR), make --no-print-directory -C $(dir) re ; )
				@echo "$(_WHITE)"

$(PUSH_SWAP_OBJ_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(PUSH_SWAP_OBJ_DIR)
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(CHECKER_OBJ_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(CHECKER_OBJ_DIR)
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME1): 		libft/libft.a $(INC_DIR) $(PUSH_SWAP_OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LFLAGS) -o $(NAME1)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(NAME2): 		libft/libft.a $(INC_DIR) $(CHECKER_OBJ) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LFLAGS) -o $(NAME2)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

norme:
				norminette $(PUSH_SWAP_SRC_DIR) ; norminette $(CHECKER_SRC_DIR)

re:				fclean all

sort: 			$(NAME1)
				@echo "Launch Binary File $(_BLUE)$(NAME1)$(_WHITE)\n-----"
				@./$(NAME1) "$(ARGS)"
				@echo "-----\n$(_BLUE)$(NAME1) $(_GREEN)successfully end$(_WHITE)\n-----"

check:			$(NAME2)
				@echo "Launch Binary File $(_BLUE)$(NAME2)$(_WHITE)\n-----"
				@./$(NAME2) "$(ARGS)"
				@echo "-----\n$(_BLUE)$(NAME2) $(_GREEN)successfully end$(_WHITE)\n-----"

clean:
				@echo -n "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(PUSH_SWAP_OBJ_DIR)" \
				"$(_WHITE)and $(_YELLOW)$(CHECKER_OBJ_DIR)$(_WHITE) ... "
				@rm -rf $(PUSH_SWAP_OBJ_DIR) $(CHECKER_OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo -n "Deleting Binaries Files $(_YELLOW)$(NAME1)" \
				"$(_WHITE)& $(_YELLOW)$(NAME2)$(_WHITE) ... "
				@rm -f $(NAME1) $(NAME2)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show norme sort check re-install debug_mod