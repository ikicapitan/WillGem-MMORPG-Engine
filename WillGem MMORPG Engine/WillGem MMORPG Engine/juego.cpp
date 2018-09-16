#include "juego.h"

juego::juego(Vector2u resolucion)
{
	ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "WillGEM MMORPG Engine 2D"); //Creo una ventana
	iniciar(); 
	gameloop();

}

void juego::iniciar()
{
	j1 = new player(*ventana,2,4,4,Vector2i(3,2));
	fps = 60; //60 frames por segundo
	reloj1 = new Clock();
	cronometro1 = new Time();
}

void juego::gameloop()
{
	while (!gameover) //Mientras game over sea falso, ejecuta el juego constantemente
	{
		*cronometro1 = reloj1->getElapsedTime(); //Obtenemos tiempo transcurrido
		if (cronometro1->asSeconds() > 1 / fps) //Comparamos si el tiempo transcurrido supera 1 fps (de ser así ejecutamos un instante)
		{
			procesar_logic();

			if (j1->caminando)
			{
				j1->animar_frame();
			}
			
			
			renderizar();
			reloj1->restart(); //Reinicio el reloj
		}
	}
}


void juego::procesar_logic()
{
	j1->procesar_eventos();

}

void juego::renderizar()
{
	ventana->clear();
	ventana->draw(j1->get_spr());
	ventana->display(); //Mostrar ventana del juego
}