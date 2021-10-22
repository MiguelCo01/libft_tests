CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ../libft
RUNNER_DIR = ../test_runner
run:
	@ ${CC} ${FLAGS} -I${SRC_DIR} -I${RUNNER_DIR} *.c ${SRC_DIR}/*.c ${RUNNER_DIR}/*.c && ./a.out
	@ rm -rf ./a.out a.out.dSYM
