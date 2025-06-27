#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

struct Enemigo{
    int id;
    char nombre[50];
    int ataque;
    int vidaActual;
    int vidaMaxima;
   
};










struct Arma {
	int id;
	char nombre[50];
	int ataque;
};
/*Esta funcion usa el struct arma para crear un arma
 *Se implemento un case, ya que hay varios tipos de armas 
 *Cada una tiene su respectivo nombre y ataque, por lo que mientras mas potente es mas difcil es de conseguir
 */
struct Arma crearArma(int id) {
	struct Arma a;
	a.id = id;
	switch (id) {
	case 1:
		strcpy(a.nombre, "palo de madera");
		a.ataque = 5;
		break;
	case 2:
		strcpy(a.nombre, "cuchillo");
		a.ataque = 10;
		break;
	case 3:
		strcpy(a.nombre, "mazo");
		a.ataque = 15;
		break;
	case 4:
		strcpy(a.nombre, "cadenas de fuego");
		a.ataque = 20;
		break;
	case 5:
		strcpy(a.nombre, "espada de furia");
		a.ataque = 25;
		break;
	case 98:
		strcpy(a.nombre, "espada celestial");
		a.ataque = 100;
		break;
	default:
		strcpy(a.nombre, "desconocido");
		a.ataque = 0;
		break;
	}
	return a;
}
// Algoritmo sencillo para mostrar el arma que se tiene
void imprimirArma(const struct Arma *a) {
	printf("Arma {\"%s\", ataque: %d }\n",
	       a->nombre, a->ataque);
}

//Cambia el arma segun el id de la misma
void setArmaId(struct Arma *a, int id) {
	*a = crearArma(id);
}
/*Las siguientes funciones returnan las caracteristicas del arma que se tiene*/
int getArmaId(const struct Arma *a) {
	return a->id;
}

const char* getArmaNombre(const struct Arma *a) {
	return a->nombre;
}

int getArmaAtaque(const struct Arma *a) {
	return a->ataque;
}
/*Aqui se definen las cosas basicas de un jugador
 *Se usa el struct de arma para que a este se le pueda asignar una en medio del gameplay
 */
struct Jugador {
    char nombre[50];
    int vidaActual;
    int vidaMaxima;
    int dinero;
    struct Arma arma;
};
/*Funcion para crear jugador, recibe como parametos todas las caracteristicas que este debe tener
 *Define al jugador con el struct de antes
 *Toma los parametros y los pasa al struct que se definio
 */
struct Jugador crearJugador(const char *nombre, int vidaActual, int vidaMaxima, int dinero, struct Arma arma) {
    struct Jugador j;
    strncpy(j.nombre, nombre, sizeof(j.nombre) - 1);
    j.nombre[sizeof(j.nombre) - 1] = '\0';
    j.vidaActual = vidaActual;
    j.vidaMaxima = vidaMaxima;
    j.dinero     = dinero;
    j.arma       = arma;
    return j;
}
/*Funcion sencilla para imprimir
 *Recibe como parametro el struct del jugador
 *Mediante el struct accede a las caracteristicas para poder imprimirlas
 */
void imprimirJugador(const struct Jugador *j) {
    printf("**********          DATOS DEL JUGADOR           **********\n");
    printf("  nombre: \"%s\"\n",     j->nombre);
    printf("  vidaActual: %d\n",     j->vidaActual);
    printf("  vidaMaxima: %d\n",     j->vidaMaxima);
    printf("  dinero: %d\n",         j->dinero);
    printf("  ");
    imprimirArma(&j->arma); 
    printf("\n**********************************************************\n");
    
}
// setters y getters

void setJugadorNombre(struct Jugador *j, const char *nombre) {
    strncpy(j->nombre, nombre, sizeof(j->nombre) - 1);
    j->nombre[sizeof(j->nombre) - 1] = '\0';
}
const char* getJugadorNombre(const struct Jugador *j) {
    return j->nombre;
}

void setVidaActual(struct Jugador *j, int v) {
    j->vidaActual = v;
}
int getVidaActual(const struct Jugador *j) {
    return j->vidaActual;
}

void setVidaMaxima(struct Jugador *j, int v) {
    j->vidaMaxima = v;
}
int getVidaMaxima(const struct Jugador *j) {
    return j->vidaMaxima;
}

void setDinero(struct Jugador *j, int d) {
    j->dinero = d;
}
int getDinero(const struct Jugador *j) {
    return j->dinero;
}

void setArmaJugador(struct Jugador *j, struct Arma arma) {
    j->arma = arma;
}
struct Arma getArmaJugador(const struct Jugador *j) {
    return j->arma;
}




const char *portada =
    "....................................................................................................\n"
    "....................................................................................................\n"
    "........-%@@*.....:*@@%-..=%@@@@@:..*@@@...#@@:.:%@@@@@=..%@@@@@@@@@+-%@@@@@@@@.+@@@@@@@@*..........\n"
    "........-%@@@%=..=%@@@%-:*@%****@%=.*@@@%:.#@@::%@%***%@-.+***@@@**+-:%@@******.=@@%*+*#@@#.........\n"
    "........-%@@@@@==@@@@@%--@@#...:@@%.*@@@@%.#@@::%@*..........:@@@....-%@%:......=@@*...-%@#.........\n"
    "........-%@@*%@@@@%+%@%--@@#...:@@%.*@@%#@@@@@::*@@@@@=......:@@@....-%@@@@@@*..=@@%###%@%=.........\n"
    "........-%@%-:+@@=.:#@%--@@#...:@@%.+@@+.=@@@@:..::+##@%-....:@@@....:%@%-:::...=@@%##@@+:.........\n"
    "........-%@%-..-=..:#@%--@@#-::-@@%.+@@+..=@@@::%@-:::%@=....:@@@....:%@%=-:---.+@@*..+%@%-.........\n"
    "........-%@%-......:#@%-.:*@@@@@@=..+@@+...%@@::*@@@@@@#-....:@@@....-%@@@@@@@@.+@@*...*@@#.........\n"
    "..........:.........:::....::::::....::.....::...::::::.......:::.....:::::::::..::.....:::.........\n"
    "...................%%%%%%....#%%:..=%%+.#%%%%%%%+..%%%%%%+.*%%%%%%%%#....+%%%%+....-%%%%*...........\n"
    "................:*@%####@@+..%@@:..=@@+.%@@%####=:@@@####=.*%#%@@%##*...%@%##%@#:.#@%##%@@=.........\n"
    "................*@@*....#@@=.%@@:..=@@+.%@@......:@@#.........=@@*......%@*..*@%:.#@*..=@@=.........\n"
    "................*@@*....#@@=.%@@:..=@@+.%@@@@@@*..:%@@@@*:....=@@*......#@@@@@@%:.:*@@@@@-.........\n"
    "................*@@*.=**%@@=.%@@:..=@@+.%@@:........:--*@%-...=@@*.......:---#@%:.#@#..=@@=.........\n"
    "................+%@#--#@@@%-.*%@***#@%=.%@@#****=.*****%@%-...=@@*......*#+--#@%:.#@#--+@@=.........\n"
    ".................:-%@@@@@@%-...#@@@@*:..%@@@@@@@+.@@@@@%-.....=@@*.......*@@@@+....+@@@@%..........\n"
    ".........................=*%=.......................................................................\n"
    ".:::.................:..............................................................................\n"
    "..:-----::.............::::.......:-.................................................................\n"
    ".....::-----:...........:---:.....:-:.................-%#-............................................\n"
    ".........:-----::.........:----:...--:..................=%*:............................................\n"
    ".......:::--------:....::...:----------...................+%#.........................................\n"
    ".....:------::.--::.....:::..-------::---:.................:%%=........................................\n"
    "...:-----:....:--.........:--------::..:-::..................=##-......................................\n"
    ".:-----:.....:--.........:-----------..:----::.................+%*:....................................\n"
    "-----:..:--:.:-:.....::.:---::------------------.................+@*...................................\n"
    "---:...---:..--........:---...----:...::::---:--........-:........-#%-:=%+.............................\n"
    "--...-----.:---.......:---:.....---:..*=.....:-........*-...........-@%............:::...............\n"
    ":..:-----.::---.......:---........:-...-#%*+.......:+@=:...........-*-...........+%@@@#:.............\n"
    ".....---:.:----:.....:----.........:::....-#@%--.=@@@*.....--......-+........--.....:*%:.............\n"
    ".....---.:------:.....-----.........:-......=%@@%%@%=...*#%#:...........=%*...:.......%*:...........\n"
    "....---..:-------:....-----:.......::-::......=@@@@@@+*%*-.............=*%@%-.......................\n"
    "....-:....:--------:..------:................-@@@@@@@@#*=-:...........#+-*@@#...=%*::...............\n"
    "....:.......:---::----------::...............:@-=%%=%@:.::=+.........:#@@@@@#:...*@@%...............\n"
    ".............:--...----------:..............=++.:*%:.+%=..............=++-........:***..............\n"
    ".................::-----------:..................:#:...+:.....*###+...................................\n"
    "..............:---------------:...................:#:.......##@@@@*...................................\n"
    ".............:---------------:..........:---:..............:@@@@@@*....:.............................\n"
    "..........:---------:.:------:........:---:.::.............:@@@@@@*...=%*...........................\n"
    "........:---------:...-----:......:----:::-:...............:@@@@@@*..%@@%-..........................\n"
    "......------------...-----........----.....-:..............:@@@@@@+.@@@@+...........................\n"
    "...:--------------...:-----:................................=%@@@+:*@%+.............................\n"
    ".:------.:---------:...:::---:...............................+%#=:+%*:..............................\n"
    "-------....:-------:........:---.................................=*................:#-..............\n"
    "------:.....:-------:.........:--........................................:*@@@=.....+=:.............\n"
    "---:......::-------:.........:.:-.......................................=%@@@@@-......++............\n"
    ".........:----::............::::.................................=*....%@@@@@@@@%=....:=-.........\n"
    ".........:-:.....................................................=*...:%@@@@@@@@@#-:...-+:..........\n"
    "%%%%%%%%-.::.:%%%%%%+......-=====================================**...=++++++++++++=-....-==========\n"
    "@@@@@%+...:--:::.-#@@*.......::.:-============================-::.....:-===========-::.....:-=======\n"
    ".............:::.....................:======================-..................................:====\n"
    "--------------------------------------=======================-----------------------------------====\n"
    "====================================================================================================\n"
    "====================================================================================================\n";









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
/*Funcion encargada de la interfaz
 *Pide un 1 para ingresar a la interfaz donde se configuran los ajustes de la partida
 *Dentro del juego, se pide un 1 para comenzar partida o 2 para salir
 *Al comenzar se pide la dificultad y el nombre del jugador
 *Con un case se lleva control de la interfaz
 *
 */

void inicio() {

	int opcion;
	char nombreJugador[50];
	int dificultad;

	 printf("%s", portada);

	printf("Presione 1 para continuar");

	scanf("%d", &opcion);
	if (opcion == 1) {
		system("clear"); //Aqui se limpia la terminal para borrar la portada inpresa y tener la terminal limpia
		printf("Bienvenido a Monster Quest 98\n\n");
		printf("1. Comenzar partida\n");
		printf("2. Salir\n\n");
		printf("Seleccione una opciC3n: ");

		if (scanf("%d", &opcion) != 1) {
			opcion = 0;
			int c;
			while ((c = getchar()) != '\n' && c != EOF); // Linea auxiliar por si se coloca una opccion no valida
		}

		switch (opcion) {
		case 1:
			system("clear");
			printf("******      Elija la dificultad de la partida       ******\n\n");
			printf("1. dificil\n");
			printf("2. normal\n\n");
			printf("3. facil\n");

			if (scanf("%d", &dificultad) != 1) {
				dificultad = 0;
				int c;
				while ((c = getchar()) != '\n' && c != EOF); // Otra linea auxiliar
			}
                        /*Si la dificultad ingresada esta fuera del rango de opciones
			 * se entra en un while hasta que se ingrese una valida*/
			while (dificultad < 1 || dificultad > 3) {
				
			        system("clear");
				printf("Dificultad invC!lida. Intente de nuevo.\n\n");
				printf("******      Elija la dificultad de la partida       ******\n\n");
				printf("1. dificil\n");
				printf("2. normal\n\n");
				printf("3. facil\n");

				if (scanf("%d", &dificultad) != 1) {
					dificultad = 0;
					int c;
					while ((c = getchar()) != '\n' && c != EOF); // Otra linea auxiliar
				}
			}
			
			system("clear");
			//despues de escoger la dificultad se pide el nombre del jugador
			printf("******      Escriba el nombre de su personaje       ****** \n\n");
			scanf("%49s", nombreJugador);
			
			printf("Tu nombre es: %s\n", nombreJugador);

			
			//printf("%d",dificultad);


			break;
		//Si la opcion es 2 simplemente se termina la ejecucion, o sea se sale del juego
		case 2:
			printf("\nhasta luego\n");
			break;
		default:
			printf("\n intente de nuevo.\n");
			break;
		}


	}
}

/*Definicion de la funcion que llevara a cabo el gameplay
 *Recibe como parametetros la dificultad y el jugador para operar con estas caracteristicas
 *
 *
 *
 */
void gameplay(struct Jugador *jugador, int dificultad) {


    system("clear");
    printf ("Esto es el gameplay");
    /*Segun la dificultad seleccionada se condiciona el juego a que se complique por obviedad*/
    int filas, columnas, valor_maximo, max_libre;
    switch (dificultad) {
        case 1:
            filas = columnas = 8;
            valor_maximo = 25;
            max_libre    = 5;
            break;
        case 2:
            filas = columnas = 6;
            valor_maximo = 20;
            max_libre    = 4;
            break;
        case 3:
            filas = columnas = 4;
            valor_maximo = 10;
            max_libre    = 2;
            break;
        default:
            return;
    }

    /*Aqui se hace el llenado del tablero definifendo el tablero con un char para guardar 
     * lo que hay en cada casilla recorrida y un int visitado para ir verificando su ya una posicion del tablero se recorrio
     *
     */

    srand(time(NULL));
    char tablero[filas][columnas];
    int visitado[filas][columnas];

    for (int i = 0; i < filas; i++) {
        int pos_tienda = rand() % (columnas - 1); /*Se puede generar una tienda aleatoria en cualquier casilla menos la ultima*/
        for (int j = 0; j < columnas; j++) {
            visitado[i][j] = 0;
	    /**
	     *Aqui se definen los distintos eventos que pueden ocurrir en una casilla, la utltima esta reservada para
	     *una lucha con el jefe final, por lo que se le asiga la letra clave J, si hay tienda una T y las demas son espacios l
	     *libres en el tablero
	     */
            if (j == columnas - 1)       tablero[i][j] = 'j';
            else if (j == pos_tienda)    tablero[i][j] = 't';
            else {
                int v = rand() % valor_maximo + 1;
                tablero[i][j] = (v <= max_libre) ? 'l' : 'c';
            }
        }
    }

    int fila = 0, columna = 0, accion;
    visitado[0][0] = 1;
    /*Aqui el juego se empieza a ejecutar hasta que se cumpla alguna condicion que lo haga frenar, como la muerte del personaje
     */
    while (1) {
	
          system("clear");
          for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (i == fila && j == columna)       printf("| (ง •̀_•́)ง ");
                else if (visitado[i][j])             printf("|     *    ");
                else                                 printf("|          ");
            }
            printf("|\n");
        }

        /**A segun que se genero en la respectiva casilla se imprime un mensaje avisando esto*/
        char tipo = tablero[fila][columna];
        if      (tipo == 'c') printf("hay combate\n");
        else if (tipo == 't') printf("hay tienda\n");
        else if (tipo == 'j') printf("hay jefe\n");

   
        printf("avanzar? ");
        scanf("%d", &accion);
        /*Esta es la forma en la que el jugador avanza hasta llegar al final*/
        if (accion == 1) {
            columna++;
            if (columna == columnas) {
                columna = 0;
                fila++;
                if (fila == filas) {
                    printf("fin del juego\n");
                    break;
                }
            }
            visitado[fila][columna] = 1;
        }
    }
}
        


int main() {

	/**
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
    */
     
    inicio();
    return 0;
}
