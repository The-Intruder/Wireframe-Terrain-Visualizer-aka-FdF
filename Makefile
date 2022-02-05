NC := \033[31;0m
RED := \033[0;31;1m
YEL := \033[0;33;1m
GRA := \033[0;37;1m
CYN := \033[0;36;1m
GRN := \033[0;32;1m
MGN := \033[0;35;1m
BLU := \033[0;34;1m

SRCS_M_DIR := ./srcs_m/
SRCS_M_LST := drawing_algo.c \
	drawing_instructions.c \
	event_handling_1st.c \
	event_handling_2nd.c \
	event_handling_3rd.c \
	matrix_allocation.c \
	matrix_initialization.c \
	sidebar_1st.c \
	sidebar_2nd.c \
	error_handling.c
SRCS_M := ${addprefix ${SRCS_B_DIR}, ${SRCS_B_LST}}

SRCS_B_DIR := ./srcs_b/
SRCS_B_LST := drawing_algo_bonus.c \
	drawing_instructions_bonus.c \
	event_handling_1st_bonus.c \
	event_handling_2nd_bonus.c \
	event_handling_3rd_bonus.c \
	matrix_allocation_bonus.c \
	matrix_initialization_bonus.c \
	sidebar_1st_bonus.c \
	sidebar_2nd_bonus.c \
	error_handling_bonus.c
SRCS_B := ${addprefix ${SRCS_B_DIR}, ${SRCS_B_LST}}


OBJS_DIR := ./objs/
OBJS_M_LST := ${patsubst %.c, %.o, ${SRCS_M_LST}}
OBJS_M := ${addprefix ${OBJS_DIR}, ${OBJS_M_LST}}
OBJS_B_LST := ${patsubst %.c, %.o, ${SRCS_B_LST}}
OBJS_B := ${addprefix ${OBJS_DIR}, ${OBJS_B_LST}}

CC := gcc
CC_FLAGS := -Wall -Wextra -Werror
CC_OPTS := -I /usr/local/include \
	-L/usr/local/lib/ -lmlx \
	-framework OpenGL -framework AppKit \
	./libs/get_next_line/get_next_line.c \
	./libs/get_next_line/get_next_line_utils.c \
	-L./libs/libft -lft \
	-L. -lfdf

NAME := libfdf.a
MAP := pyramide.fdf

IS_BONUS := false

all: fclean ${NAME}

${NAME}: ${OBJS_M} ${SRCS_M_DIR}fdf.h
	@echo "\n${BLU}Creating ${GRA}${NAME} ${BLU}archive file ...${NC}"
	@ar -rcs ${NAME} ${OBJS_B}
	@echo "\n${GRN}Library created successfully ...\n${NC}"

${OBJS_DIR}%.o: ${SRCS_B_DIR}%.c
	@echo "${MGN}Creating ${GRA}$@ ${MGN}file from ${GRA}$< ${MGN}file ...${NC}\n"
	@${CC} ${CC_FLAGS} -c $< -o $@

clean:
	@echo "\n${RED}Cleaning up Object files ...\n${NC}"
	@rm -f ${OBJS_DIR}*.o

fclean: clean
	@echo "${RED}Cleaning up the ${GRA}${NAME}${RED} archive file ...\n${NC}"
	@rm -f ${NAME}

re: exclean all

bonus: ${OBJS_B}

# DESTROY WIN & IMG BEFORE PROGRAM EXIT

# compile: re ${SRCS_B_DIR}fdf.h ${SRCS_B_DIR}fdf.c
# 	@echo "\n${YEL}Compiling the ${GRA}${SRCS_B_DIR}fdf.c ${YEL}...\n${NC}"
# 	@${CC} ${CC_FLAGS} ${CC_OPTS} -o fdf ${SRCS_B_DIR}fdf.c
# 	@make fclean

# execute: compile fdf
# 	@echo "\n${CYN}Loading X-Window ...${NC}\n"
# 	@time ./fdf ./test_maps/${MAP}

# exclean: fclean
# 	@echo "${RED}Cleaning up the ${GRA}fdf${RED} executable file ...\n\n${NC}"
# 	@rm -f fdf

.PHONY: all clean fclean re bonus
# compile execute exclean


