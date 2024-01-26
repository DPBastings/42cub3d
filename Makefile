NAME 		:= cub3d

SRC_FILES	:= main.c
OBJ_FILES	:= $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES	:= cub3d.h\
			cub3d_error.h
LIB_FILES	:= lib/libft/libft.a\
			lib/libmlx42_build/libmlx42.a

SRC_DIR		:= ./source/
SRC_SUBDIRS	:= map
OBJ_DIR		:= ./object/
OBJ_SUBDIRS := $(SRC_SUBDIRS)
HDR_DIR		:= ./include/

CC			:= gcc
CFLAGS		+= -Wall -Wextra -Werror -I$(HDR_DIR) -Ilib/libft/include/ -Ilib/libmlx42/include/
LIBFLAGS	:= -lglfw -L/usr/lib -ldl -pthread -lm
DEPFLAGS	:= -MMD $(@.o=.d) -MP
DEP_FILES	:= $(patsubst %.o,%.d,$(addprefix $(OBJ_DIR), $(OBJ_FILES)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJ_FILES)) $(LIB_FILES)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c # $(addprefix $(HDR_DIR),$(HDR_FILES))
	@mkdir -p $(addprefix $(OBJ_DIR),$(OBJ_SUBDIRS))
	@$(CC) $(CFLAGS) $(DEPFLAGS) -I$(SRC_DIR) $< -c -o $@

lib/libft/libft.a:
	$(MAKE) --directory=$(dir $@)

lib/libmlx42_build/libmlx42.a:
	cmake -S ./lib/libmlx42/ -B $(dir $@)
	cmake  --build $(dir $@)
	
clean:
	$(MAKE) --directory=./lib/libft/ clean
	cmake --build ./lib/libmlx42_build/ --target clean
	@rm -f $(addprefix $(OBJ_DIR),$(OBJ_FILES))\
		$(addprefix $(OBJ_DIR),$(patsubst %.o,%.d,$(OBJ_FILES)))

fclean: clean
	$(MAKE) --directory=./lib/libft/ fclean
	@rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
