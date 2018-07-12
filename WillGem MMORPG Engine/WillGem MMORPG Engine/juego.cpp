#include "juego.h"

juego::juego(Vector2u resolucion)
{
	ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "WillGEM MMORPG Engine 2D"); //Creo una ventana
	iniciar(); 

	while (!gameover) //Mientras game over sea falso, ejecuta el juego constantemente
	{
		procesar_eventos(); 
		renderizar();
	}
}

void juego::iniciar()
{

}

void juego::procesar_eventos()
{

}

void juego::procesar_logic()
{

}

void juego::renderizar()
{
	ventana->display(); //Mostrar ventana del juego
}