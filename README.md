# Titulo del proyecto: Videojuego Monster Quest 98

## Descripción
***
**Monster Quest 98** Surge como respuesta al proyecto de programación bajo plataformas abiertas de la universidad de Costa Rica. Este es un videojuego del género roguelike, es decir, caracterizado por una muerte permanente y una jugabilidad basada en algoritmos de exploración llenos de azar.  En este repositorio se implementa esto con un personaje que recorre un tablero en el cual puede encontrarse con combates, tiendas o simplemente un espacio vacío en el cual, al final de cada fila, se enfrenta a un jefe final, el cual, con su derrota, permite el ingreso a la siguiente fila, esto para llegar hasta el final del tablero y completar el juego.

## Instalación
***
Como el proyecto se desarrolló en el lenguaje de programación C, como mínimo se requiere una terminal donde ejecutar comandos, esto porque el archivo Makefile encargado de compilar usa el comando gcc en sus reglas de compilación, proveniente de la Colección de compiladores GNU,  por lo cual se debe instalar está para poder ejecutar el videojuego. 
Si se cuenta con una distribución de Linux (Ubuntu), se puede descargar con el siguiente comando:
sudo apt install gcc
Para compilar este proyecto basta tener la versión  11.4.0, ya que con esta versión se realizaron las pruebas.
 




## Pasos para la ejecución
***
**Se enunciarán los pasos a seguir en orden numérico.**

1. En la parte inicial del repositorio, tocar el botón "<> code"
2. A partir del paso anterior, copiar el link HTTPS
3. Clonar el repositorio en su terminal donde ejecuta programas normalmente, usando el comando git clone "URL del paso anterior"
4. Entrar desde la terminal al directorio "Proyecto-Final"
5. Dentro del directorio de la parte 4, ejecutar el comando make
6. Una vez ejecutado el paso 5, para iniciar el videojuego, ejecute el comando ./main 
