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
				procesar_logic();
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
		case Event::KeyPressed: //Procesamiento del teclado
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				teclas_j1[0] = true; //Habilito tecla izquierda
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				teclas_j1[1] = true;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				teclas_j1[2] = true;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				teclas_j1[3] = true;
			}
		break;

		//																SOLTAR TECLA
		//

		case Event::KeyReleased: //Procesamiento de soltar tecla

			if (evento->key.code == Keyboard::Left)
			{
				teclas_j1[0] = false; //Desactivo tecla izq
			}
			else if (evento->key.code == Keyboard::Right)
			{
				teclas_j1[1] = false;
			}
			else if (evento->key.code == Keyboard::Up)
			{
				teclas_j1[2] = false;
			}
			else if (evento->key.code == Keyboard::Down)
			{
				teclas_j1[3] = false;
			}
			break;
	}
}

void juego::procesar_logic()
{
	j1->caminando = false; //El jugador 1 no esta caminando

	//Chequear teclas

	if (teclas_j1[0])
	{
		j1->caminando = true; //El jugador 1 esta caminando
		if (teclas_j1[2])
		{
			j1->direccion = izq_arr;
		}
		else if (teclas_j1[3])
		{
			j1->direccion = izq_ab;
		}
		else
		{
			j1->direccion = izquierda;
		}
	}
	else if (teclas_j1[1])
	{
		j1->caminando = true;
		if (teclas_j1[2])
		{
			j1->direccion = der_arr;
		}
		else if (teclas_j1[3])
		{
			j1->direccion = der_ab;
		}
		else
		{
			j1->direccion = derecha;
		}
	}
	else if (teclas_j1[2])
	{
		j1->caminando = true;
		j1->direccion = arriba;
	}
	else if (teclas_j1[3])
	{
		j1->caminando = true;
		j1->direccion = abajo;
	}


	//Update de actores

	j1->update(); //Actualiza fisicas j1
}

void juego::renderizar()
{
	ventana->clear();
	ventana->draw(j1->get_spr());
	ventana->display(); //Mostrar ventana del juego
}