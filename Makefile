#Variables basicas de compilacion
CC = gcc 
CFLAGS = -Wall -Wextra -Iincludes 

#Archivos necesarios para la construccion de reglas
SRCS = main.c src/proyectofinal.c 
INCLUDES = includes/proyectofinal.h
OBJS = $(SRCS:.c=.o)

TARGET = main
all: $(TARGET)

#Regla para crear el archivo ejecutable main dandole el nombre del target     	
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

#Reglas para generar los archivos objeto necesarios para tener el ejectubale final

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

src/proyectofinal.o: proyectofinal.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

#Regla para eliminar los archivos objeto que se puedan llegar a generar

clean:
	rm -f $(TARGET) $(OBJS)
