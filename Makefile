
NAME	:=	Fract_ol

CC		:=	gcc
CFLAGS	:= -03 -Wall -Wextra -Werror -lmx -framework
LIBS	=	-lm -L./$(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit

PATH_SRC		:=	./src
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

BIN				:=	./$(NAME)
SRCS			:= $(PATH_SRC)/fractol.c \


OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(BIN)

$(BIN): $(OBJ)
		@$(CC) $(CFLAGS) -o $(@) $^ -I$(PATH_INCLUDES)
		@printf "\033[44m[FRACT-OL BUILT!]\033[0m\n"




$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@$(CC) $(CFLAGS) $(LIBS) -c $(^) -o $@
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