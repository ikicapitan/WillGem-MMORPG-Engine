#include "jugador.h"
#include <iostream>

using namespace std;

player::player(int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a)
{
	set_sprite(spr_clase, cant_x1, cant_y1, fr_a);
	vel_walk = 3.0f;
	vel_run = 64;
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

