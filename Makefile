
# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME    	:= cub3D
BNUS_NAME	:= cub3D_bonus

MKFL		:= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_CLR		:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

INC_DIR	:= inc/
SRC_DIR	:= srcs/
TUL_DIR	:= tools/
UTL_DIR	:= utils/

MAP_DIR	:= $(TUL_DIR)map_read/
PRS_DIR	:= $(TUL_DIR)map_parser/

BIN_DIR	:= bin/

OBJ_DIR	:= .objs/
DEP_DIR	:= .deps/

LIBS	= library/
LIB_DIR	= $(LIBS)clift/
LFT_DIR	= $(LIB_DIR)libft/
OUT_DIR	= $(LIB_DIR)liboutput/
MLX_DIR	= $(LIBS)minilibx/

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS		= -Wall -Wextra -Werror -W
XFLAGS		= #-fsanitize=address -g
LFLAGS		= #-fsanitize=leak
DFLAGS		= -MT $@ -MMD -MP
FRAMEWORK	= -framework OpenGL -framework AppKit
LNX_MLX		= -ldl -lglfw3 -pthread -lm

AR		= ar -rcs
RM		= rm -f
MK		= mkdir -p
CP		= cp -f

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBRARY	= $(LIB_DIR)libft.a $(LIB_DIR)liboutput.a
MLX_LIB	= $(MLX_DIR)libmlx.a
INCLUDE	= -I$(INC_DIR) -I$(MLX_DIR) \
		-I$(LFT_DIR)$(INC_DIR) -I$(OUT_DIR)$(INC_DIR)

CUB_SRC	= cub3d.c

SRCS	+= $(addprefix $(SRC_DIR), $(CUB_SRC))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))


# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))

all:
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

run:
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)
	@./$(NAME) tests/cpeset-c.cub

$(NAME):: $(OBJS)
	@$(MK) $(BIN_DIR)
	@$(CC) $(CFLAGS) $(XFLAGS) $(FRAMEWORK) $(OBJS) $(LIBRARY) $(MLX_LIB) $(LFLAGS) -o $(BIN_DIR)$(NAME);
	@printf "\n\t$(WHITE)Program \033[1;31mFDF $(WHITE)has been compiled!$(DEF_COLOR)\n"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mFDF$(DEF_COLOR)\n"

-include $(DEPS)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)	FDF object and dependencies files cleaned.$(DEF_COLOR)"

fclean: 
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) $(BIN_DIR)
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "$(GREEN)	Cleaned and rebuilt everything for fdf project.$(DEF_COLOR)"

norm:
	@norminette $(INC_DIR) $(SRC_DIR) $(TUL_DIR) $(UTL_DIR) $(LIB_DIR)

.PHONY: all clean fclean re norm
