#include "teclado.h"

teclado::teclado()
{
	evento = new Event;
}

teclado *teclado::get_teclado()
{
	static teclado t1;
	return &t1;
}

void teclado::procesar_eventos()
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