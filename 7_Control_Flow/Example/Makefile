# Makefile

NAME = Example
ODIR = Sources
SRC = ${ODIR}/main.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -g

all: options ${NAME}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "CC       = ${CC}"

$(ODIR)/.c.o:
	${CC} -c ${CFLAGS} $<

${NAME}: ${OBJ}
	${CC} -o $@ ${OBJ}

clean:
	rm -f ${NAME} ${OBJ}


.PHONY: all options ${NAME} clean
