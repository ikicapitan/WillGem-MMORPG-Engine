#include "juego.h"

juego::juego(Vector2u resolucion)
{
	ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "WillGEM MMORPG Engine 2D"); //Creo una ventana
	iniciar(); 
	gameloop();

}

void juego::iniciar()
{
	j1 = new player(2,4,4,Vector2i(3,2));
	evento = new Event();
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
			while (ventana->pollEvent(*evento))
			{
				procesar_eventos();
			}

			if (j1->caminando)
			{
				j1->animar_frame();
			}
			renderizar();
			reloj1->restart(); //Reinicio el reloj
		}
		
	}
}

void juego::procesar_eventos()
{
	switch (evento->type)
	{
		case Event::Closed:
			exit(1);
			break;

		//																		PRESIONAR TECLA
		//
		//
		//


		case Event::KeyPressed: //Procesamiento del teclado
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down))
				{

				}
				else
				{

				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{

				}
				else if (Keyboard::isKeyPressed(Keyboard::Down))
				{

				}
				else
				{

				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{

				}
				else if (Keyboard::isKeyPressed(Keyboard::Right))
				{

				}
				else
				{
					j1->caminando = true;
					//j1->set_pos(Vector2f(j1->get_pos().x, j1->get_pos().y - 20));
				}
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{

				}
				else if (Keyboard::isKeyPressed(Keyboard::Right))
				{

				}
				else
				{

				}
			}
		break;

		//																SOLTAR TECLA
		//
		//
		//
		//

		case Event::KeyReleased: //Procesamiento de soltar tecla

			if (evento->key.code == Keyboard::Left)
			{
				if (evento->key.code == Keyboard::Up)
				{

				}
				else if (evento->key.code == Keyboard::Down)
				{

				}
				else
				{

				}
			}
			else if (evento->key.code == Keyboard::Right)
			{
				if (evento->key.code == Keyboard::Up)
				{

				}
				else if (evento->key.code == Keyboard::Down)
				{

				}
				else
				{

				}
			}
			else if (evento->key.code == Keyboard::Up)
			{
				if (evento->key.code == Keyboard::Left)
				{

				}
				else if (evento->key.code == Keyboard::Right)
				{

				}
				else
				{
					j1->caminando = false;
					//j1->set_pos(Vector2f(j1->get_pos().x, j1->get_pos().y - 20));
				}
			}
			else if (evento->key.code == Keyboard::Down)
			{
				if (evento->key.code == Keyboard::Left)
				{

				}
				else if (evento->key.code == Keyboard::Right)
				{

				}
				else
				{

				}
			}
			break;
	}
}

void juego::procesar_logic()
{

}

void juego::renderizar()
{
	ventana->clear();
	ventana->draw(j1->get_spr());
	ventana->display(); //Mostrar ventana del juego
}