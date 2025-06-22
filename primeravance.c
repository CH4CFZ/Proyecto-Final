#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//esta parte es para dar la posicion del caballero, si el caballero se encuentra en esa posicion aparece un * en la posicion i,j
void printCaballero(int posi, int posj) {
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            
            if(posi==i && posj==j){
                printf("[*]");
            }
            else{
            printf("[]");
            }
        }
        printf("\n"); 
    }
}



int main() {
    srand(time(NULL)); //esto para que cada vez que se inicie sea aleatoria la semilla

    int tablero[5][5]; // probamos con una matriz 5x5 pero el tamanno de la matriz al final debe ser aleatorio

    int posii = 0;
    int posjj = 0;
    int accion;
// usamos valores aleatorios de 0 y 1 para la matriz, si el valor es 1 entonces hay un combate, pero en la version final no solo sera 0 y 1 ya que tambien deben salir otras opciones 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tablero[i][j] = rand() % 2;
        }
    }

    while (1) {
//aqui vemos la posicion del caballero, y en caso de que la casilla tenga un 1 como se dijo anteriormente hay combate
        printCaballero(posii, posjj);
if(tablero[posii][posjj]==1){
               printf("Hay combate\n");
           }
        printf("Avanzar?\n"); // preguntamos si desea avanzar, si contesta con un 1 pues avanza
        scanf("%d", &accion);

        if (accion == 1) {
           
           posjj = posjj+1;
           
           
           // si logra llegar al final de la fila baja a la siguiente 
           if(posjj==4){
               posii = posii + 1;
               posjj=0;
           }
           
           
           
     
        }
        
     

    
        system("clear");
     
    }
    return 0;
}
