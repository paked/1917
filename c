export CLFAGS="-Wall -Werror -O"
export CC=gcc

$CC $CFLAGS $EFLAGS -o $1.o $1.c
