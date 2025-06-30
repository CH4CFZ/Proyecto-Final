#ifndef PROYECTO_H
#define PROYECTO_H

struct Enemigo {
    int id;
    char nombre[50];
    int ataque;
    int vidaActual;
    int vidaMaxima;
};


struct Enemigo crearEnemigo(int id, int dificultad);


void imprimirEnemigo(const struct Enemigo *e);
/*Funciones set y get en general
 *Nos permieten ingresar y modificar los miembros de los distintos structs creados
 *Para ello reciben como parametro la direccion a los mismo
 */

int getEnemigoId(const struct Enemigo *e);
const char* getEnemigoNombre(const struct Enemigo *e);
int getEnemigoAtaque(const struct Enemigo *e);
int getEnemigoVidaActual(const struct Enemigo *e);
int getEnemigoVidaMaxima(const struct Enemigo *e);


void setEnemigoId(struct Enemigo *e, int id);
void setEnemigoDificultad(struct Enemigo *e, int dificultad);

struct Arma {
    int id;
    char nombre[50];
    int ataque;
};

struct Arma crearArma(int id);

// Algoritmo sencillo para mostrar el arma que se tiene
void imprimirArma(const struct Arma *a);

//Cambia el arma segun el id de la misma
void setArmaId(struct Arma *a, int id);

/*Las siguientes funciones returnan las caracteristicas del arma que se tiene*/
int getArmaId(const struct Arma *a);
const char* getArmaNombre(const struct Arma *a);
int getArmaAtaque(const struct Arma *a);


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
struct Jugador crearJugador(const char *nombre, int vidaActual, int vidaMaxima, int dinero, struct Arma arma);

/*Funcion sencilla para imprimir
*Recibe como parametro el struct del jugador
*Mediante el struct accede a las caracteristicas para poder imprimirlas
*/
void imprimirJugador(const struct Jugador *j);

// 
void setJugadorNombre(struct Jugador *j, const char *nombre);
const char* getJugadorNombre(const struct Jugador *j);

void setVidaActual(struct Jugador *j, int v);
int getVidaActual(const struct Jugador *j);

void setVidaMaxima(struct Jugador *j, int v);
int getVidaMaxima(const struct Jugador *j);

void setDinero(struct Jugador *j, int d);
int getDinero(const struct Jugador *j);

void setArmaJugador(struct Jugador *j, struct Arma arma);
struct Arma getArmaJugador(const struct Jugador *j);




extern const char *avisoComabte;
extern const char *zombie;
extern const char *angel;
extern const char *portada;


void printCaballero(int, int);
void combate(struct Jugador*, int, char);
void combateJefe(struct Jugador*, int);
void apareceTienda(struct Jugador*);
void gameplay(struct Jugador*, int);
void inicio(void);


#endif
