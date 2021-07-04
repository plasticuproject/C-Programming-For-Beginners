# Makefile

NAME = Challenge
ODIR = Sources
SRC = ${ODIR}/main.c
OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -O2 -fPIE -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security
LDFLAGS= -Wl,-z,now -Wl,-z,relro

all: options ${NAME}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

$(ODIR)/.c.o:
	${CC} -c ${CFLAGS} $<

${NAME}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${NAME} ${OBJ}


.PHONY: all options ${NAME} clean
