#include "proyectofinal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

const char *avisoComabte =
" _ _ _   _____       _                       _                    \n"
"(_|_|_) | ____|_ __ | |_ _ __ __ _ _ __   __| | ___     ___ _ __  \n"
"| | | | |  _| | '_ \\| __| '__/ _` | '_ \\ / _` |/ _ \\   / _ \\ '_ \\ \n"
"| | | | | |___| | | | |_| | | (_| | | | | (_| | (_) | |  __/ | | |\n"
"|_|_|_| |_____|_| |_|\\__|_|  \\__,_|_| |_|\\__,_|\\___/   \\___|_| |_|\n"
"  ___ ___  _ __ ___ | |__   __ _| |_ ___  | | | |                 \n"
" / __/ _ \\| '_ ` _ \\| '_ \\ / _` | __/ _ \\ | | | |                 \n"
"| (_| (_) | | | | | | |_) | (_| | ||  __/ |_|_|_|                 \n"
" \\___\\___/|_| |_| |_|_.__/ \\__,_|\\__\\___| (_|_|_)                 \n";


const char *zombie =
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@..........@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++............@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@--+++=.............@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++......++.........@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++......++.........@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++++++++++..=====@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@++=+@@@@++@@@@@@@@++@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@+=@=+@@@++@@....@@++@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@+=@%#@@@++@@....@@..@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@==+=@@++++@@....@@..@@....@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@+=@@++++++@@@@++....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++....++............@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++++..@@@@@@@@@@@+@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++..@@@@++@@++@@@@@@@@@@@.........@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++........:=@@@@@@@@@@@..........#@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++..........@@@@@@@@@@@....++.....@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++++++++++@@@@@++....++++..@@@@@..@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@....@@@@@@@@@@@@@@@@@@@@++++++++++=@@++..@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@..................@@@@@@@@@++++++@@@@@@..@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@++++++++..++........@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@++++++++++....+*....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@++++++++++....++....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++..@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@##########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@#######@#######@@@@######@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@###########@@@@@@######....@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@#####===-##@@@@@@@@######..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@#######===.@@@@@@@@@@@@####..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@#######===+@@@@@@@@@@@@######@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@@@######==@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@####@@###@@@@@@@@@@@@@@##@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@%%%%%%%@@@@@@@@@@@@@@@@@@%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";



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



/*

        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************
        **************************************************      AQUI ESTAN lAS REPRESENTACIONES DE LOS ENEMIGOS       ***********************************************


*/


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
    "..:-----::.............::::.......:-.................................................................\n";

/*Funcion para crear el enemigo 
 *Recibe como parametro el id para selecionar cual es segun este con el case
 *Y la dificultada, para mejorarlos segun ella
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

        if (dificultad == 1) {
        	e.vidaMaxima = vidaBase * 2;
        	e.ataque     = ataqueBase * 2;
        } else if (dificultad == 2) {
        	e.vidaMaxima = vidaBase;
        	e.ataque     = ataqueBase;
        } else {
        	e.vidaMaxima = vidaBase / 2;
        	e.ataque     = ataqueBase / 2;
        }
        e.vidaActual = e.vidaMaxima;
        return e;
}

void imprimirEnemigo(const struct Enemigo *e) {
	
    	printf("enemigo { id: %d, nombre: \"%s\", ataque: %d, vidaActual: %d, vidaMaxima: %d }\n",
           	e->id, e->nombre, e->ataque, e->vidaActual, e->vidaMaxima);
}
/*Funciones get y set: Encargadas de acceder a los miembros de los structs, al ser mmuchas esta es la unica que va a ser comentada
 *ya que seu logica es general.
 *EStas reciben como la direccion del struct al que desean accerder, para crear o modificar lo que sea necesario
 *Por esto es que toman un puntero, sin embargo depende de la misma, ya que pueden o no recibir mas parametros segun la estructura
 *y lo que se quiera hacer.
 */
int getEnemigoId(const struct Enemigo *e)         { return e->id; }
const char* getEnemigoNombre(const struct Enemigo *e) { return e->nombre; }
int getEnemigoAtaque(const struct Enemigo *e)     { return e->ataque; }
int getEnemigoVidaActual(const struct Enemigo *e){ return e->vidaActual; }
int getEnemigoVidaMaxima(const struct Enemigo *e){ return e->vidaMaxima; }

void setEnemigoId(struct Enemigo *e, int id) {
    	*e = crearEnemigo(id, 2);
}

void setEnemigoDificultad(struct Enemigo *e, int dificultad) {
    	*e = crearEnemigo(e->id, dificultad);
}



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

// Mas funciones set y get

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

   //esta parte es para dar la posicion del caballero, si el caballero se encuentra en esa posicion aparece un * en la posicion i,j
void printCaballero(int posi, int posj) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if(posi==i && posj==j) {
				printf("[*]");
			}
			else {
				printf("[]");
			}
		}
		printf("\n");
	}
}

void gameplay(struct Jugador *jugador, int dificultad);
void combateJefe(struct Jugador *jugador, int dificultad);
void apareceTienda(struct Jugador *jugador);

// funcion combate
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
        
        if (jugador->vidaActual <= 0) {
            printf("Fin del juego %s...\n", e.nombre);
            exit(0);
        }
        
        sleep(2);
        system("clear");
        printf("%s\n", zombie);
        printf("%s: %d/%d  VS  %s: %d/%d\n\n",
               jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
               e.nombre,           e.vidaActual,   e.vidaMaxima);
    }

    
    if (jugador->vidaActual > 0)
        printf("Has acabado con %s!\n", e.nombre);
    else
        printf("Fin del juego %s...\n", e.nombre);
}




///////////////////////////////////////////


/*

    ARRIBA ES COMBATE NORMALLALALALALLALALAL      
     ARRIBA ES COMBATE NORMALLALALALALLALALAL   
      ARRIBA ES COMBATE NORMALLALALALALLALALAL   
       ARRIBA ES COMBATE NORMALLALALALALLALALAL   
        ARRIBA ES COMBATE NORMALLALALALALLALALAL   
         ARRIBA ES COMBATE NORMALLALALALALLALALAL   
          ARRIBA ES COMBATE NORMALLALALALALLALALAL   
           ARRIBA ES COMBATE NORMALLALALALALLALALAL   
           void ARRIBA ES COMBATE NORMALLALALALALLALALAL    
           void ARRIBA ES COMBATE NORMALLALALALALLALALAL   
         
*/


void apareceTienda(struct Jugador *jugador) {
    system("clear");
    printf("1) dormir  2) salir\n");
    int opc;
    scanf("%d",&opc);
    if(opc==1){
        printf("durmiendo\n");
        sleep(3);
        setVidaActual(jugador,getVidaMaxima(jugador));
        printf("te has curado completamente\n");
    } else if(opc==2){
        printf("saliendo\n");
    }
}

void combateJefe(struct Jugador *jugador, int dificultad){
    
    
    system("clear");
    // Siempre jefe (id = 6)
    int idEnemigo = 6;
    struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

    // Probabilidades según dificultad
    int probJugador, probEnemigo;
    switch (dificultad) {
        case 1: probJugador = 50; probEnemigo = 33; break;
        case 2: probJugador = 75; probEnemigo = 25; break;
        case 3: probJugador = 90; probEnemigo = 10; break;
        default: probJugador = 50; probEnemigo = 33; break;
    }

    // Mostrar ASCII guardado en 'angel' y datos iniciales
    printf("%s\n", angel);
    printf("¡Comienza el combate contra %s!\n\n", e.nombre);
    printf("%s: %d/%d  VS  %s: %d/%d\n\n",
           jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
           e.nombre,           e.vidaActual,   e.vidaMaxima);

    while (jugador->vidaActual > 0 && e.vidaActual > 0) {
        
    
       

        if (rand() % 100 < probJugador) {
            e.vidaActual -= jugador->arma.ataque;
            printf("%s golpea y causa %d de daño.\n",
                   jugador->nombre, jugador->arma.ataque);
        } else {
            printf("%s falla el ataque.\n", jugador->nombre);
        }
        if (e.vidaActual <= 0) break;

        // Turno del jefe
        if (rand() % 100 < probEnemigo) {
            jugador->vidaActual -= e.ataque;
            printf("%s ataca y causa %d de daño.\n",
                   e.nombre, e.ataque);
        } else {
            printf("%s falla el ataque.\n", e.nombre);
        }

        sleep(2);
        system("clear");
        printf("%s\n", angel);
        printf("%s: %d/%d  VS  %s: %d/%d\n\n",
               jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
               e.nombre,           e.vidaActual,   e.vidaMaxima);
    }

    if (jugador->vidaActual > 0)
        printf("Has acabado con %s!\n", e.nombre);
    else
        printf("Fin del juego %s...\n", e.nombre);
    
    
    
}


void inicio() {
    int opcion = 0;
    char nombreJugador[50];
    int dificultad = 0;

    printf("%s", portada);

    /* sigue pidiendo hasta que ingrese 1 */
    do {
        system("clear");
        printf("%s", portada);
        printf("Presione 1 para continuar: ");
        if (scanf("%d", &opcion) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcion = 0;
        }
    } while (opcion != 1);

    system("clear");
    printf("Bienvenido a Monster Quest 98\n\n");

    /* menú principal */
   do {
       system("clear");
    printf("1. Comenzar partida\n");
    printf("2. Salir\n\n");
    printf("Seleccione una opcion: ");
    if (scanf("%d", &opcion) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        opcion = 0;
    }
} while (opcion != 1 && opcion != 2);


    switch (opcion) {
        case 1:
            system("clear");
            /* elige dificultad */
            do {
                system("clear");
                printf("****** Elija la dificultad ******\n");
                printf("1. dificil\n2. normal\n3. facil\n");
                printf("Opcion: ");
                if (scanf("%d", &dificultad) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        dificultad = 0;
    }
            } while (dificultad < 1 || dificultad > 3);


            system("clear");
            printf("Escriba el nombre de su personaje: ");
            scanf("%49s", nombreJugador);

            {
                struct Jugador jugador = crearJugador(nombreJugador, 100, 100, 10, crearArma(1));
                if (dificultad == 1) {
                    setVidaMaxima(&jugador, 1000);
                    setVidaActual(&jugador, 1000);
                } else if (dificultad == 2) {
                    setVidaMaxima(&jugador, 250);
                    setVidaActual(&jugador, 250);
                } else {
                    setVidaMaxima(&jugador, 100);
                    setVidaActual(&jugador, 100);
                }
                gameplay(&jugador, dificultad);
            }
            break;

        case 2:
            printf("\nhasta luego\n");
            break;

        default:
            /* puede repetir o salir según preferencia */
            break;
    }
}





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
            printf("|\n");
        }

        char tipo = tablero[fila][columna];
        if(tipo == 'c'){
            
            
            printf("hay combate\n");
            sleep(1);
            system("clear");
            printf("%s", avisoComabte);
            sleep(3);
            printf("Entrando\n");
            combate(jugador, dificultad, 'c');
        } 
        else if (tipo == 't'){ 
            printf("hay tienda\n");
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
            printf("Entrando\n");
            combateJefe(jugador, dificultad);
            
        }

// esto es el menu de opciones

        do {
            printf("1. avanzar? ");
        if (scanf("%d", &accion) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        accion = 0;
         }
         } while (accion != 1);


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


