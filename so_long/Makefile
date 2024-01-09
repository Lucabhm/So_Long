NAME = so_long
NAMEB = so_long_bonus
CFLAGS = -Wall -Werror -Wextra
SRCS = src/so_long.c \
		src/createmap.c \
		src/checkmap.c \
		src/checkmap2.c \
		src/helper.c \
		src/graphics.c \
		src/move.c \
		src/error.c
SRCSB = src_bonus/so_long_bonus.c \
		src_bonus/endscreen_bonus.c \
		src_bonus/catchp_bonus.c \
		src_bonus/enemy_bonus.c \
		src_bonus/banner_bonus.c \
		src_bonus/helper_bonus.c \
		src_bonus/graphics_bonus.c \
		src_bonus/move_bonus.c \
		src_bonus/checkmap_bonus.c \
		src_bonus/checkmap2_bonus.c \
		src_bonus/error_bonus.c \
		src_bonus/createmap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
LIBFT = lib/libft
PRINTF = lib/printf
GET_NEXT = lib/get_next_line
MLX = lib/mlx
INSO_LONG = -I ../includes/so_long.h
INSO_LONGB = -I ../includes/so_long_bonus.h
INLIBFT = -L $(LIBFT) -lft
INPRINF = -L $(PRINTF) -lftprintf
INGET_NEXT = -L $(GET_NEXT) -lftget_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -L /opt/homebrew/Cellar/glfw/3.3.8/lib/ -lglfw -pthread -lm

$(NAME):		$(OBJS)
				make -C $(LIBFT)
				make -C $(PRINTF)
				make -C $(GET_NEXT)
				cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				cc $(OBJS) $(INLIBFT) $(INPRINF) $(INGET_NEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME) $(CFLAGS) $(INSO_LONG)

$(NAMEB):		$(OBJSB)
				make -C $(LIBFT)
				make -C $(PRINTF)
				make -C $(GET_NEXT)
				cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				cc $(OBJSB) $(INLIBFT) $(INPRINF) $(INGET_NEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAMEB) $(CFLAGS) $(INSO_LONGB)

all:			$(NAME)

bonus:			$(NAMEB)

%.o:%.c
				cc $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJS)
				rm -f $(OBJSB)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean
				@cd $(GET_NEXT) && $(MAKE) clean
				@rm -rf $(MLX)/build

fclean:			clean
				rm -f $(NAME)
				rm -f $(NAMEB)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean
				@cd $(GET_NEXT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus re_b