
NAME	:=	Fract_ol

CC		:=	gcc
CFLAGS	:= -Wall -Wextra -Werror -g
LIBS	=	-Iincs -Lmlx -lmlx -framework OpenGL -framework AppKit

PATH_SRC		:=	./src
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

#BIN				:=	./$(NAME)
SRCS			:= $(PATH_SRC)/fractolutils.c \
					$(PATH_SRC)/color.c \
					$(PATH_SRC)/main.c \
					$(PATH_SRC)/mandelbrot.c \
					$(PATH_SRC)/events.c \


OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(NAME)
		@./$(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(LIBS) -o $(@) $^ -I$(PATH_INCLUDES)
		@printf "\033[44m[FRACT-OL BUILT!]\033[0m\n"

$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@$(CC) $(CFLAGS)  -c $(^) -o $@
		@printf "\033[36m[Building ${@F}]\033[0m\n"


$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS) 

clean:
		@printf "\033[38;5;1m[Cleaning objects!]\033[0m\n"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@printf "\033[38;5;1m[Cleaning Bin!]\033[0m\n"
		@rm -rf $(PATH_BUILD) $(NAME)

re: fclean all