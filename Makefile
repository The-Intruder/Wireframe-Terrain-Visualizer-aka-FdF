NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

SRCS_DIR := ./srcs/
SRCS_LST := drawing_algo.c \
	drawing_instructions.c \
	event_handling_1st.c \
	event_handling_2nd.c \
	event_handling_3rd.c \
	matrix_allocation.c \
	matrix_initialization.c \
	sidebar_1st.c \
	sidebar_2nd.c \
	error_handling.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := ./objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror \
	-Ofast -march=native -fno-signed-zeros \
	-fno-trapping-math
CC_OPTS := -I /usr/local/include \
	-L/usr/local/lib/ -lmlx \
	-framework OpenGL -framework AppKit \
	./libs/get_next_line/get_next_line.c \
	./libs/get_next_line/get_next_line_utils.c \
	-L./libs/libft -lft \
	-L. -lfdf

NAME := libfdf.a
MAP := 42.fdf


.PHONY: all clean fclean re bonus compile execute exclean obj_dir

all: ${NAME}

${NAME}: $(OBJS_DIR) ${OBJS} ${SRCS_DIR}fdf.h
	@make -C ./libs/libft/
	@echo "\n${BLU}Creating ${GRA}${NAME} ${BLU}archive file ...${NC}"
	@ar -rcs ${NAME} ${OBJS}
	@echo "\n${GRN}Library created successfully ...\n${NC}"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${SRCS_DIR}fdf.h
	@echo "\n${MGN}Creating ${GRA}$@ ${MGN}file from ${GRA}$< ${MGN}file ...${NC}"
	@${CC} ${CC_FLAGS} -c $< -o $@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@echo "\n${RED}Cleaning up Object files ...\n${NC}"
	@rm -f ${OBJS_DIR}*.o ./libs/libft/*.o
	@echo "${RED}Removing ${NC}${GRA}objs/ ${NC}${RED}folder ...\n${NC}"
	@rm -rf objs

fclean: clean
	@echo "${RED}Cleaning up Archive files ...\n${NC}"
	@rm -f ${NAME} ./libs/libft/*.a

re: exclean all

bonus: ${OBJS} ${SRCS_DIR}fdf.h
	@echo "\n\n${BLU}Creating ${GRA}${NAME} ${BLU}archive file ...${NC}"
	@ar -rcs ${NAME} ${OBJS}
	@echo "\n${GRN}Library created successfully ...\n${NC}"

compile: re ${SRCS_DIR}fdf.h fdf_main_bonus.c
	@echo "\n${YEL}Compiling the ${GRA}fdf_main_bonus.c ${YEL}...\n${NC}"
	@${CC} ${CC_FLAGS} ${CC_OPTS} -o fdf fdf_main_bonus.c 
	@make fclean

execute: compile fdf
	@echo "\n${CYN}Loading X-Window ...${NC}\n"
	@time ./fdf ./test_maps/${MAP}

exclean: fclean
	@echo "${RED}Cleaning up the ${GRA}fdf${RED} executable file ...\n\n${NC}"
	@rm -f fdf
