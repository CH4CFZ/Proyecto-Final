#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 

/*EStructurar de enemigo
 *Guarda las caracteristicas basicas que necesita el mismo
 */

struct Enemigo{
    int id;
    char nombre[50];
    int ataque;
    int vidaActual;
    int vidaMaxima;
   
};
/*Funcion para crear enemigo
 *segun el id asigna el tipo de enemigo que es
 *segun el id asigna las caracteristicas de combate
 *
 */
struct Enemigo crearEnemigo(int id, int dificultad) {
    struct Enemigo e;
    e.id = id;
    switch (id) {
        case 1: strcpy(e.nombre, "zombie");   break;
        case 2: strcpy(e.nombre, "bruja");    break;
        case 3: strcpy(e.nombre, "diablo");   break;
        case 4: strcpy(e.nombre, "fantasma"); break;
        case 5: strcpy(e.nombre, "vampiro");  break;
        case 6: strcpy(e.nombre, "jefe");     break;
        default: strcpy(e.nombre, "desconocido"); break;
    }

    int vidaBase, ataqueBase;
    switch (id) {
        case 1: vidaBase = 50;  ataqueBase =  5;  break;
        case 2: vidaBase = 40;  ataqueBase =  8;  break;
        case 3: vidaBase =100;  ataqueBase = 15;  break;
        case 4: vidaBase = 30;  ataqueBase = 10;  break;
        case 5: vidaBase = 80;  ataqueBase = 12;  break;
        case 6: vidaBase =200;  ataqueBase = 25;  break;
        default: vidaBase = 10; ataqueBase =  1;  break;
    }
    /*Aqui segun las dificultades de la partida se le hace un buff 
     * a los enemigos
     */
    if (dificultad == 1) {         // difícil
        e.vidaMaxima = vidaBase * 2;
        e.ataque     = ataqueBase * 2;
    } else if (dificultad == 2) {  // normal
        e.vidaMaxima = vidaBase;
        e.ataque     = ataqueBase;
    } else {                       // bts
        e.vidaMaxima = vidaBase / 2;
        e.ataque     = ataqueBase / 2;
    }
    e.vidaActual = e.vidaMaxima;
    return e;
}

//Funcion sencilla como todas las demas de impresion que recorre las caracteristicas del enemigo
void imprimirEnemigo(const struct Enemigo *e) {
    printf("enemigo { id: %d, nombre: \"%s\", ataque: %d, vidaActual: %d, vidaMaxima: %d }\n",
           e->id, e->nombre, e->ataque, e->vidaActual, e->vidaMaxima);
}

/*Funciones sencillas las cuales tienen como funcion
 *acceder al obejto que en este caso es el enemigo para 
 *acceder y modificar lo que estos son mas que todo con el ID
 *
 */

int getEnemigoId(const struct Enemigo *e)         {
       	return e->id; 
}
const char* getEnemigoNombre(const struct Enemigo *e) {
       	return e->nombre; 
}
int getEnemigoAtaque(const struct Enemigo *e)     {
       	return e->ataque; 
}
int getEnemigoVidaActual(const struct Enemigo *e){
       	return e->vidaActual; 
}
int getEnemigoVidaMaxima(const struct Enemigo *e){
       	return e->vidaMaxima; 
}

void setEnemigoId(struct Enemigo *e, int id) {
    int dif = 2; // por defecto normal
    *e = crearEnemigo(id, dif);
}

void setEnemigoDificultad(struct Enemigo *e, int dificultad) {
    *e = crearEnemigo(e->id, dificultad);
}
//representacion visual del zombie
const char *zombie =
    ".......ZOMBIE.......\n"
    "...ASCII ART...\n";

const char *angel =
"...............................................................................\n"
"...............................................................................\n"
"...............................................................................\n"
"...............................:--+@@@@@@%%@=::................................\n"
".............................:*%@**+:......=+*@%+:.............................\n"
".............................-@*-.............@@@-.............................\n"
".............................-@@%%+.........+%@#:..............................\n"
"..............................:*@@@@@@@@@@@@@@:................................\n"
"...........:@@@@@@@@.......................................%@@@@@@@=...........\n"
"..........@@@@@@@@@@.......................................%@@@@@@@@@..........\n"
"........#@@@@@@@@@@@@+...........%@@@@@@@@@@@@:..........=@@@@@@@@@@@@#........\n"
"......:@@@@@@@@@@@@@@*:.......:*@@@@@@@@@@@@@@@#-........+@@@@@@@@@@@@@@-......\n"
"......:@@@@@@@@@@@@@@@@-.....-@@@@@@@@@@@@@@@@@@@-......@@@@@@@@@@@@@@@@-......\n"
".....*#@@@@@@@@@@@@@@@@#*....-@@@@@@@@@@@@@@@@@@@-....=#@@@@@@@@@@@@@@@@#*.....\n"
".....%@@@@@@@@@@@@@@@@@@%....-@@@@@@@@@@@@@@@@@@@-....#@@@@@@@@@@@@@@@@@@@.....\n"
".....%@@@@@@@@@@@@@@@@@@@%=..-@@@@@@@@@@@@@@@@@@@-..-%@@@@@@@@@@@@@@@@@@@@.....\n"
".....%@@@@@@@@@@@@@@@@@@@@@@:-@@@:..#@@@@@%...%@@-:@@@@@@@@@@@@@@@@@@@@@@@.....\n"
".....%@@@@@@@@@@@@@@@@@@@@@@:-@@@:..#@@@@@%...%@@-:@@@@@@@@@@@@@@@@@@@@@@@.....\n"
".....%@@@@@@@@@@@@@@@@@@@@@@@#.*@@@@@@@@@@@@@@@#.*@@@@@@@@@@@@@@@@@@@@@@@@.....\n"
".....%@@@@@*.%@@@@@%@@@@@@@@@@@-.%@@@%:::%@@@%.:@@@@@@@@@@@%@@@@@@.+@@@@@@.....\n"
".....%@@@@@*.%@@@@::@@@@@@@@#*----+#########+----*#@@@@@@@@::@@@@@.+@@@@@@.....\n"
".....%@@@@@*.%@@@@::@@@@@@%#=+@@@@%+++++++++%@@@@*=*%@@@@@@::@@@@@.+@@@@@@.....\n"
".....@@@@@@*.%@@@@::@@@@@@+.%@@@@@@@@@@@@@@@@@@@@@@.=@@@@@@::@@@@@.+@@@@@@.....\n"
".....@@@@@@*.%@@@@::@@@@@=+#@@@@@@@@@@@@@@@@@@@@@@@@*=%@@@@::@@@@@.+@@@@@@.....\n"
".....@@@@@@*.%@@@@:.@@@@%.*@@@@=:@@@@@@@@@@@@@:=@@@@#.#@@@@::@@@@%.+@@@@@@.....\n"
".....@@@@@@*.%@@@@:.@@@:..*@@@@=.@@@@@@@@@@@@@:=@@@@#..:@@@::@@@@%.+@@@@@@.....\n"
".....@@@@@@*.%@@@@:.@=....*@@@@=.@@@@@@@@@@@@@:=@@@@#....=@::@@@@%.+@@@@@@.....\n"
".....@@@@@@*.%@@@@:.......*@@@@=.@@@@@@@@@@@@@:=@@@@*.......:@@@@%.+@@@@@@.....\n"
".....@@@@@@*.%@@@%:.......*@@@@=.@@@@@@@@@@@@@:=@@@@*.......:%@@@@.+@@@@@@.....\n"
".....%@@@@@*.%@@*.........*@@@@=.@@@@@@@@@@@@@:-@@@@*.........+@@@.+@@@@@@.....\n"
".....%@@@@@#.%@#=.........*@@@@=.@@@@@@@@@@@@@:-@@@@*.........-*@@.+@@@@@@.....\n"
".....%@@@@@#.%@...........*@@%-..@@@@@=--%@@@@:.-%@@*...........@%.+@@@@@@.....\n"
"......=@@@@#..............*@@#...@@@@%...%@@@@:..#@@*...........:..+@@@@+......\n"
"......-@@@@#.....................@@@@%...#@@@@:....................+@@@@=......\n"
"......-@@@@#.....................@@@@%...#@@@@:....................*@@@@=......\n"
"........#@@#.....................@@@@%...#@@@@:....................*@@%........\n"
"........*@@#.....................@@@@%...#@@@@:....................+@@#........\n"
"..........%*.....................@@@@%...#@@@@:....................+%:.........\n"
".................................@@@@%...#@@@@:................................\n"
"...............................=#@@@@%...#@@@@#*...............................\n"
"...............................................................................\n"
"...............................................................................\n"
"...............................................................................\n";



// funcion combate
void combateJefe(struct Jugador *jugador, int dificultad);
void combate(struct Jugador *jugador, int dificultad, char enemigo){
    int p;
    scanf("%d",&p);






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
			struct Jugador jugador = crearJugador(nombreJugador, 100, 100, 10, crearArma(1));
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

    srand(time(NULL));
    char tablero[filas][columnas];
    int visitado[filas][columnas];
    
    for (int i = 0; i < filas; i++) {
        int pos_tienda = rand() % (columnas - 1);
        for (int j = 0; j < columnas; j++) {
            visitado[i][j] = 0;
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

    while (1) {
        system("clear");
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) { 
                if (i == fila && j == columna)       printf("| (ง •̀_•́)ง ");
                else if (visitado[i][j])             printf("|     *    ");
                else                                 printf("|          ");
            }
            printf("|
");
        }

        char tipo = tablero[fila][columna];
        if(tipo == 'c'){
            
            
            printf("hay combate
");
            sleep(1);
            system("clear");
            printf("%s", avisoComabte);
            sleep(3);
            printf("Entrando
");
            combate(jugador, dificultad, 'c');
        } 
        else if (tipo == 't'){ 
            printf("hay tienda
");
            sleep(1);
            system("clear");
            apareceTienda(jugador);
            
        }
        else if (tipo == 'j'){ 
            printf("aparece un jefe");
            sleep(1);
            system("clear");
            printf("%s", avisoComabte);
            sleep(3);
            printf("Entrando
");
            combateJefe(jugador, dificultad);
            
        }

// esto es el menu de opciones

        printf("avanzar? ");
        scanf("%d", &accion);

        if (accion == 1) {
            columna++;
            if (columna == columnas) {
                columna = 0;
                fila++;
                if (fila == filas) {
                    printf("fin del juego
");
                    break;
                }
            }
            visitado[fila][columna] = 1;
        }
    }
}

   
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
        




void combateJefe(struct Jugador *jugador, int dificultad);


void combate(struct Jugador *jugador, int dificultad, char enemigo) {
    
    system("clear");
    int idEnemigo = 1;
    idEnemigo = rand() % 5 + 1; 
   
    struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

   
    int probJugador, probEnemigo;
    switch (dificultad) {
        case 1: probJugador = 50;  probEnemigo = 33;  break;
        case 2: probJugador = 75;  probEnemigo = 25;  break;
        case 3: probJugador = 90;  probEnemigo = 10;  break;
        default: probJugador = 50; probEnemigo = 33;  break;
    }

    printf("Comienza el combate contra %s!\n", getEnemigoNombre(&e));
    printf("%s: %d/%d  VS  %s: %d/%d\n\n",
           getJugadorNombre(jugador), getVidaActual(jugador), getVidaMaxima(jugador),
           getEnemigoNombre(&e), getEnemigoVidaActual(&e), getEnemigoVidaMaxima(&e));

    while (jugador->vidaActual > 0 && e.vidaActual > 0) {
        
      //  printf("%s\n", zombie);
       
    
        // el jugador
        if (rand() % 100 < probJugador) {
            e.vidaActual -= jugador->arma.ataque;
            printf("%s golpea y causa %d de daño. Vida %s: %d/%d\n",
                   jugador->nombre, jugador->arma.ataque,
                   e.nombre, e.vidaActual < 0 ? 0 : e.vidaActual, e.vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", jugador->nombre);
        }
        if (e.vidaActual <= 0) break;

        // el enemigo 
        if (rand() % 100 < probEnemigo) {
            jugador->vidaActual -= e.ataque;
            printf("%s ataca y causa %d de daño. Vida %s: %d/%d\n",
                   e.nombre, e.ataque,
                   jugador->nombre, jugador->vidaActual < 0 ? 0 : jugador->vidaActual, jugador->vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", e.nombre);
        }
        
        sleep(2);
        system("clear");
        printf("%s\n", zombie);
        printf("%s: %d/%d  VS  %s: %d/%d\n\n",
               jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
               e.nombre,           e.vidaActual,   e.vidaMaxima);
    }

    
    if (jugador->vidaActual > 0)
        printf("Chaito papi %s!\n", e.nombre);
    else
        printf("Fin del jogo %s...\n", e.nombre);
}



void apareceTienda(struct Jugador *jugador);


void combate(struct Jugador *jugador, int dificultad, char enemigo) {
    
    system("clear");
    int idEnemigo = 1;
    idEnemigo = rand() % 5 + 1; 
   
    struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

   
    int probJugador, probEnemigo;
    switch (dificultad) {
        case 1: probJugador = 50;  probEnemigo = 33;  break;
        case 2: probJugador = 75;  probEnemigo = 25;  break;
        case 3: probJugador = 90;  probEnemigo = 10;  break;
        default: probJugador = 50; probEnemigo = 33;  break;
    }

    printf("Comienza el combate contra %s!\n", getEnemigoNombre(&e));
    printf("%s: %d/%d  VS  %s: %d/%d\n\n",
           getJugadorNombre(jugador), getVidaActual(jugador), getVidaMaxima(jugador),
           getEnemigoNombre(&e), getEnemigoVidaActual(&e), getEnemigoVidaMaxima(&e));

    while (jugador->vidaActual > 0 && e.vidaActual > 0) {
        
      //  printf("%s\n", zombie);
       
    
        // el jugador
        if (rand() % 100 < probJugador) {
            e.vidaActual -= jugador->arma.ataque;
            printf("%s golpea y causa %d de daño. Vida %s: %d/%d\n",
                   jugador->nombre, jugador->arma.ataque,
                   e.nombre, e.vidaActual < 0 ? 0 : e.vidaActual, e.vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", jugador->nombre);
        }
        if (e.vidaActual <= 0) break;

        // el enemigo 
        if (rand() % 100 < probEnemigo) {
            jugador->vidaActual -= e.ataque;
            printf("%s ataca y causa %d de daño. Vida %s: %d/%d\n",
                   e.nombre, e.ataque,
                   jugador->nombre, jugador->vidaActual < 0 ? 0 : jugador->vidaActual, jugador->vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", e.nombre);
        }
        
        sleep(2);
        system("clear");
        printf("%s\n", zombie);
        printf("%s: %d/%d  VS  %s: %d/%d\n\n",
               jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
               e.nombre,           e.vidaActual,   e.vidaMaxima);
    }

    
    if (jugador->vidaActual > 0)
        printf("Chaito papi %s!\n", e.nombre);
    else
        printf("Fin del jogo %s...\n", e.nombre);
}

void combateJefe(struct Jugador *jugador, int dificultad);
void apareceTienda(struct Jugador *jugador);


void combate(struct Jugador *jugador, int dificultad, char enemigo) {
    
    system("clear");
    int idEnemigo = 1;
    idEnemigo = rand() % 5 + 1; 
   
    struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

   
    int probJugador, probEnemigo;
    switch (dificultad) {
        case 1: probJugador = 50;  probEnemigo = 33;  break;
        case 2: probJugador = 75;  probEnemigo = 25;  break;
        case 3: probJugador = 90;  probEnemigo = 10;  break;
        default: probJugador = 50; probEnemigo = 33;  break;
    }

    printf("Comienza el combate contra %s!\n", getEnemigoNombre(&e));
    printf("%s: %d/%d  VS  %s: %d/%d\n\n",
           getJugadorNombre(jugador), getVidaActual(jugador), getVidaMaxima(jugador),
           getEnemigoNombre(&e), getEnemigoVidaActual(&e), getEnemigoVidaMaxima(&e));

    while (jugador->vidaActual > 0 && e.vidaActual > 0) {
        
      //  printf("%s\n", zombie);
       
    
        // el jugador
        if (rand() % 100 < probJugador) {
            e.vidaActual -= jugador->arma.ataque;
            printf("%s golpea y causa %d de daño. Vida %s: %d/%d\n",
                   jugador->nombre, jugador->arma.ataque,
                   e.nombre, e.vidaActual < 0 ? 0 : e.vidaActual, e.vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", jugador->nombre);
        }
        if (e.vidaActual <= 0) break;

        // el enemigo 
        if (rand() % 100 < probEnemigo) {
            jugador->vidaActual -= e.ataque;
            printf("%s ataca y causa %d de daño. Vida %s: %d/%d\n",
                   e.nombre, e.ataque,
                   jugador->nombre, jugador->vidaActual < 0 ? 0 : jugador->vidaActual, jugador->vidaMaxima);
        } else {
            printf("%s falla el ataque.\n", e.nombre);
        }
        
        sleep(2);
        system("clear");
        printf("%s\n", zombie);
        printf("%s: %d/%d  VS  %s: %d/%d\n\n",
               jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
               e.nombre,           e.vidaActual,   e.vidaMaxima);
    }

    
    if (jugador->vidaActual > 0)
        printf("Chaito papi %s!\n", e.nombre);
    else
        printf("Fin del jogo %s...\n", e.nombre);
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
