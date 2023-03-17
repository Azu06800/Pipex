RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[34m
YEL		=	\033[33m
EOC		=	\033[0m

NAME 			= pipex

SOURCES			=	./sources
OBJECTS			=	./bin

SRCS			=	pipex.c child.c \
					$(addprefix parsing/, check_arg.c check_arg2.c get_cmd.c) \
					$(addprefix print/, error_print.c) \
					$(addprefix utils/, pipex_utils.c pipex_utils2.c ft_split.c)

OBJS			=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CFLAGS			=	-Wall -Wextra -Werror -Iincludes -arch x86_64 -g -fsanitize=address

CC				=	gcc
CINCLUDES		=	-I ./includes

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@printf "\r\033[K⏳ Compilation de ""$(YEL)${notdir $<}$(EOC). ⏳"
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS}
	@clear
	@echo "✅ $(GRE)Compilation terminée.$(EOC) ✅"
	@${CC} ${CFLAGS} ${LINK} -o ${NAME} ${OBJS}

clean:
	@echo "🗑  $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
