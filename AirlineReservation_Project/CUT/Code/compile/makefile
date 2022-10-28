SRCDIR = ../src
OBJDIR = ../obj
BINDIR = ../bin
INCDIR = ../include
CFLAGS = gcc -c -g -I${INCDIR}	
all: main.o admin.o menu_admin.o clear.o 
main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
admin.o:
	${CFLAGS} ${SRCDIR}/admin.c -o ${OBJDIR}/admin.o
menu_admin.o:
	${CFLAGS} ${SRCDIR}/menu_admin.c -o ${OBJDIR}/menu_admin.o
clear.o:
	${CFLAGS} ${SRCDIR}/clear.c -o ${OBJDIR}/clear.o


finalexe:
	gcc ${OBJDIR}/main.o ${OBJDIR}/admin.o ${OBJDIR}/menu_admin.o ${OBJDIR}/clear.o -o ${BINDIR}/main.exe 


