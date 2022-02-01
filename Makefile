NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := -I /usr/local/include \
	-L/usr/local/lib/ -lmlx \
	-framework OpenGL -framework AppKit \
	./assets/get_next_line/get_next_line.c \
	./assets/get_next_line/get_next_line_utils.c \
	-L./assets/libft -lft \
	-L. -lfdf

SRCS := fdf_alloc_matrix.c fdf_fill_matrix.c \
	fdf_draw_set_instruct.c \
	fdf_draw_line.c \
	fdf_handle_events.c \
	fdf_handle_event_translation.c \
	fdf_handle_event_matrix_rotation.c \
	fdf_handle_err.c
OBJS := $(SRCS:%.c=%.o)

NAME := libfdf.a
MAP := elem2.fdf


all: $(NAME)

$(NAME): $(OBJS) fdf.h
	@echo "\n$(BLU)Creating $(GRA)$(NAME) $(BLU)archive file ...$(NC)"
	@ar -rcs $(NAME) $(OBJS)
	@echo "\n$(GRN)Library created successfully ...\n$(NC)"

%.o: %.c
	@echo "\n$(MGN)Creating Object file from $(GRA)$< $(MGN)file ...\n$(NC)"
	@$(CC) $(CC_FLAGS) -o $@ -c $<

compile: re fdf.h
	@echo "\n$(YEL)Compiling the $(GRA)fdf_main.c $(YEL)...\n\n$(NC)"
	@$(CC) ${CC_FLAGS} $(CC_OPTS) -o fdf fdf_main.c
	@make fclean

execute: compile fdf
	@echo "$(CYN)Loading X-Window ...$(NC)\n"
	@time ./fdf ./assets/test_maps/$(MAP)

clean:
	@echo "\n$(RED)Cleaning up Object files ...\n\n$(NC)"
	@rm -f *.o ./fdf_draw/*.o ./fdf_handle_events/*.o

fclean: clean
	@echo "$(RED)Cleaning up the $(GRA)$(NAME)$(RED) archive file ...\n\n$(NC)"
	@rm -f $(NAME)

exclean: fclean
	@echo "$(RED)Cleaning up the $(GRA)fdf$(RED) executable file ...\n\n$(NC)"
	@rm -f fdf

re: exclean all

bonus: re

.PHONY: all clean fclean re compile execute exclean bonus