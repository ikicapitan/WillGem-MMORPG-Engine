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
}

void juego::gameloop()
{
	while (!gameover) //Mientras game over sea falso, ejecuta el juego constantemente
	{
		while (ventana->pollEvent(*evento))
		{
			procesar_eventos();
		}
		
		renderizar();
	}
}

void juego::procesar_eventos()
{
	switch (evento->type)
	{
		case Event::Closed:
			exit(1);
			break;

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
					j1->set_pos(Vector2f(j1->get_pos().x, j1->get_pos().y - 20));
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