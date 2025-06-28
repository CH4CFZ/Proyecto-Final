#Variables basicas de compilacion
CC = gcc 
CFLAGS = -Wall -Wextra -Iinclude 

#Archivos necesarios para la construccion de reglas
SRCS = main.c src/proyectofinal.c 
INCLUDES = include/proyectofinal.h
OBJS = $(SRCS:.c=.o)
