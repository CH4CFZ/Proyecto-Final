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
	        /*Se usa la biblioteca string.h para coipar los nombres en la estructura creada*/	
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

        if (dificultad == 1) { /*Segun la dificultad se bufean o nerfean las estadisticas del enemigo*/
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

/*Esta estructura crea un arma aleatioria por medio de un id aleatorio, mientras mas potente
 * sea esta mas dificil es que toque
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

// Mas funciones set y get que cumplen con lo mismo que se menciono antes en la estructura del enemigo

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

   /*esta parte es para dar la posicion del caballero, si el caballero se encuentra en esa posicion aparece un * en la posicion i,j*/
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
/*Declaracion de funciones importantes para la jugabilidad*/
void gameplay(struct Jugador *jugador, int dificultad);
void combateJefe(struct Jugador *jugador, int dificultad);
void apareceTienda(struct Jugador *jugador);

/*FUNCION PARA LOS COMBATES
 *Recibe como parametros la direccion de la estructtura del jugador creado y la dificultad
 *--La direccion se toma para ir modificando los miembros del struct jugador, ya que
 *--al ser combates se pierde vida, entonces asi se puede realizar 
 *El parametro dificultad es necesario para incrementar el nivel en los combates
 */
void combate(struct Jugador *jugador, int dificultad) {
	
    	system("clear");
    	int idEnemigo = 1;
    	idEnemigo = rand() % 5 + 1; /*Aqui se genra un ID aleatotio para el enemigo */
   
    	struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

        /*Con estas variables y la estructura case se controla la probabilidad que se tendra en el algoritmo para acertar el ataque*/
    	int probJugador, probEnemigo;
    	switch (dificultad) {

        	case 1: probJugador = 50;  probEnemigo = 33;  break;
        	case 2: probJugador = 75;  probEnemigo = 25;  break;
        	case 3: probJugador = 90;  probEnemigo = 10;  break;
        	default: probJugador = 50; probEnemigo = 33;  break;
        }
        /*Aqui se imprime las estadisticas del jugador y el enemigo para tener en cuenta a la hora del arranque*/
    	printf("Comienza el combate contra %s!\n", getEnemigoNombre(&e));
    	printf("%s: %d/%d  VS  %s: %d/%d\n\n",
          	 getJugadorNombre(jugador), getVidaActual(jugador), getVidaMaxima(jugador),
           	getEnemigoNombre(&e), getEnemigoVidaActual(&e), getEnemigoVidaMaxima(&e));

    	while (jugador->vidaActual > 0 && e.vidaActual > 0) { /*Arranque del combate hasta que uno muera*/
     
      //  printf("%s\n", zombie);
       
    
          /*Aqui este mecanismo que toma la probabilidad que se tenia segun la dificultad escoge si se golpea a un enemigo*/
        	if (rand() % 100 < probJugador) { 

            		e.vidaActual -= jugador->arma.ataque;
            		printf("%s golpea y causa %d de daño. Vida %s: %d/%d\n",
                   	jugador->nombre, jugador->arma.ataque,
                   	e.nombre, e.vidaActual < 0 ? 0 : e.vidaActual, e.vidaMaxima);

        	} else {
            		printf("%s falla el ataque.\n", jugador->nombre);
        	}
       	 	if (e.vidaActual <= 0) break;

           /*Mismo mecanismmo de antes, pero para el ataque del enemigo*/
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

        /*Mensajes cuando se vence al enemigo*/
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

/*FUNCION PARA LA TIENDA
 *Recibe como parametro la direccion del jugador creado
 *Con ella si este duerme se restaura toda su vida 
 *A futuro se busca implmentar la opcion para ventas
 */
void apareceTienda(struct Jugador *jugador) {
    	system("clear");
    	printf("Bienvenido a la tienda\n");
    	printf("1) Dormir  2) Salir\n");
    	int opc;
    	scanf("%d",&opc);
    	if(opc==1){
        	printf("Durmiendo...\n");
        	sleep(3);
        	setVidaActual(jugador,getVidaMaxima(jugador));
        	printf("Felicidades, te has curado completamente\n");
    	} else if(opc==2){
        	printf("Volviendo a la aventura...\n");
    	}
}

void combateJefe(struct Jugador *jugador, int dificultad){
    
    
    system("clear");
    int idEnemigo = 6; /*El jefe tiene el ID fijo en 6*/
    struct Enemigo e = crearEnemigo(idEnemigo, dificultad);

    /*Nuevamente probabilidades de ataque segun la dificultad*/
    int probJugador, probEnemigo;
    switch (dificultad) {
        	case 1: probJugador = 50; probEnemigo = 33; break;
        	case 2: probJugador = 75; probEnemigo = 25; break;
        	case 3: probJugador = 90; probEnemigo = 10; break;
        	default: probJugador = 50; probEnemigo = 33; break;
    }

    /* Mostrar ASCII guardado en 'angel' y datos iniciales*/
    printf("%s\n", angel);
    printf("¡Comienza el combate contra %s!\n\n", e.nombre);
    printf("%s: %d/%d  VS  %s: %d/%d\n\n",
           jugador->nombre, jugador->vidaActual, jugador->vidaMaxima,
           e.nombre,           e.vidaActual,   e.vidaMaxima);

    while (jugador->vidaActual > 0 && e.vidaActual > 0) {
    /*Para el combate con el jefe se desarrolla la misma 
     *implementacion que se uso para los enemigos normales
     */
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

/*FUNCION INICIO
 *Esta funcion es la encargada de hacer que se inicie el juego invocando la portada
 *el menu para escoger si se desea comenzar la partida, el nombre del jugador y la 
 *dificultad de la partida.
 *Para las opciones se usan ciclos do-while, ya que asi se evita que alguien escoja un opcion invalida
 */
void inicio() {
	
    	int opcion = 0;
    	char nombreJugador[50];
    	int dificultad = 0;

    	printf("%s", portada);

    /*En este bloque se verifica que lo unico que pueda ser ingresado es un uno y hasta qu esto sea asi se ingresa al menu*/
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

        /*Aqui ya se ingreso al menu de videojuego donde se piden las opciones de salir o comenzar*/
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
               /*Si la opcion es 1, se escoge la dificultad del juego y se mantene ahi hasta ingresar algo valido*/
            			do {
                			system("clear");
                			printf("****** Elija la dificultad ******\n");
                			printf("1. Dificil\n2. Normal\n3. Facil\n");
                			printf("Opcion: ");
                			if (scanf("%d", &dificultad) != 1) {
        					int c;
        					while ((c = getchar()) != '\n' && c != EOF);
        					dificultad = 0;
    					}
            			} while (dificultad < 1 || dificultad > 3);

                                /*Cuando se tiene esto, se hace limpieza de la pantalla y se pide el nombre del jugador*/
            			system("clear");
            			printf("Escriba el nombre de su personaje: ");
            			scanf("%49s", nombreJugador);

            			{ /*A segun la dificultad se le asina una vida superior o inferior al jugador*/
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
            			printf("\nHasta luego\n");
            			break;

        		default:
            /* puede repetir o salir según preferencia */
            			break;
    }
}

/*FUNCION PARA EL GAMEPLAY
 *Recibe como parametro la direccion del jugador creado y la dificultad
 *Dependiedno de la dificultad genera un tablero de distintas dimensiones
 */
void gameplay(struct Jugador *jugador, int dificultad) {

	
    	system("clear");
    	int filas, columnas, valor_maximo, max_libre;
    	switch (dificultad) { /*Definicion segun la dificultad mencionada arriba*/
	   
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
        	int pos_tienda = rand() % (columnas - 1); /*Algoritmo de azar para generar tiendas en el tablero*/
        	for (int j = 0; j < columnas; j++) {
            		visitado[i][j] = 0;
            		if (j == columnas - 1)       tablero[i][j] = 'j'; /*Si llega al final de la fila, aparece un jefe*/
            		else if (j == pos_tienda)    tablero[i][j] = 't'; /*Si se esta en el algoritmo de arriab se esta en tienda*/
            		else {
                		int v = rand() % valor_maximo + 1; /*variable para ver si la casilla esta libre o hay combate*/
                		tablero[i][j] = (v <= max_libre) ? 'l' : 'c';
            		}
        	}
   	 }

    	int fila = 0, columna = 0, accion;
    	visitado[0][0] = 1;
        /*Recorrido de la la matriz presentado donde esta el personaje*/
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
        /*Las apariciones se dan con letras clave para saber cuando ocurre cada evento */
        char tipo = tablero[fila][columna];
        if(tipo == 'c') {
           
            	printf("Tendras un combate\n");
            	sleep(1);
            	system("clear");
            	printf("%s", avisoComabte);
            	sleep(3);
            	printf("Entrando\n");
            	combate(jugador, dificultad);
        } 
        else if (tipo == 't'){ 
            	printf("Has encontrado una tienda en el camino\n");
            	sleep(1);
            	system("clear");
            	apareceTienda(jugador);
            
        }
        else if (tipo == 'j'){ 
            	printf("Ha aparecido un jefe, derrotalo para continuar.");
            	sleep(1);
            	system("clear");
            	printf("%s", avisoComabte);
            	sleep(3);
            	printf("Entrando\n");
            	combateJefe(jugador, dificultad);
            
        }

       /*Aqui se define el mesnsaje que se muetras para avanzar y si no se coloca lo que se pide
	* se pide hasta que sea ingresado*/

        do {
            	printf("1. Presione 1 para avanzar ");
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
                    		printf("Fin del juego\n");
                    		break;
                	}
            	}
            	visitado[fila][columna] = 1;
        }
    }
}


