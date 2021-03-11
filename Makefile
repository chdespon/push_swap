NAME = push_swap

NAME_2 = checker

cc = clang

INC_DIR = 	$(shell find includes -type d) \
			$(shell find libs/libft/includes -type d)
LIB_DIR =	libs/libf

SRC =

OBJ = $(SRC:%.s=%.o)

#Compilation flag
CFLAGS = -Wall -Wextra -Werror -no-pie -fsanitize=address -g3

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"

install:
				$(foreach dir, $(LIB_DIR), make -C $(dir) ; )

re-install:
				$(foreach dir, $(LIB_DIR), make -C $(dir) re ; )

$(NAME)
				@echo