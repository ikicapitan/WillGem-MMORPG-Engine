#include "jugador.h"
#include <iostream>

using namespace std;

player::player(RenderWindow &ventana, int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a)
{
	set_sprite(spr_clase, cant_x1, cant_y1, fr_a);
	vel_walk = 0.3f;
	vel_run = 64;
	window = &ventana;
}

void player::update() //Actualiza fisicas del player
{
	if (caminando)
	{
		seleccionar_velocidad();
		set_translation(Velocidad);
	}
	
}

void player::seleccionar_velocidad()
{
	switch (direccion) //Segun direccion en la que voy me asigna una velocidad
	{
	case arriba:
		Velocidad = Vector2f(0,-vel_walk) ;
		set_frame_y(3);
		break;

	case abajo:
		Velocidad = Vector2f(0,vel_walk);
		set_frame_y(0);
		break;

	case izquierda:
		Velocidad = Vector2f(-vel_walk,0);
		set_frame_y(1);
		break;

	case derecha:
		Velocidad = Vector2f(vel_walk, 0);
		set_frame_y(2);
		break;

	case izq_arr:
		Velocidad = Vector2f(-vel_walk, -vel_walk);
		set_frame_y(3);
		break;

	case izq_ab:
		Velocidad = Vector2f(-vel_walk, vel_walk);
		set_frame_y(0);
		break;

	case der_arr:
		Velocidad = Vector2f(vel_walk, -vel_walk);
		set_frame_y(3);
		break;

	case der_ab:
		Velocidad = Vector2f(vel_walk, vel_walk);
		set_frame_y(0);
		break;
	}
}

void player::procesar_eventos()
{

	while (window->pollEvent(*keyboard->evento))
	{
		keyboard->procesar_eventos();
	}


	caminando = false; //El jugador 1 no esta caminando

	//Chequear teclas

	if (keyboard->teclas_j1[0])
	{
		caminando = true; //El jugador 1 esta caminando
		if (keyboard->teclas_j1[2])
		{
			direccion = izq_arr;
		}
		else if (keyboard->teclas_j1[3])
		{
			direccion = izq_ab;
		}
		else
		{
			direccion = izquierda;
		}
	}
	else if (keyboard->teclas_j1[1])
	{
		caminando = true;
		if (keyboard->teclas_j1[2])
		{
			direccion = der_arr;
		}
		else if (keyboard->teclas_j1[3])
		{
			direccion = der_ab;
		}
		else
		{
			direccion = derecha;
		}
	}
	else if (keyboard->teclas_j1[2])
	{
		caminando = true;
		direccion = arriba;
	}
	else if (keyboard->teclas_j1[3])
	{
		caminando = true;
		direccion = abajo;
	}


	//Update de actores

	update(); //Actualiza fisicas j1
}

