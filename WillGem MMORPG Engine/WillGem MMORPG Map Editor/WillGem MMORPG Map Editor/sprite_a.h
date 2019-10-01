#pragma once
#include "SFML\Graphics.hpp"
#include "tempresources.h"
#include <vector>

using namespace sf;

class sprite_a
{
public:
	static sprite_a *get_sprite();
	void set_sprite(int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a);
	void set_sprite(String path);
	void seleccionar_frame(); //Carga el frame actual (por si fue cambiado)
	void set_frame_x(int frame); //Modifica el frame actual a otro
	void set_frame_y(int frame);
	void animar_frame(); //Animacion
	Sprite * spr_player; //Creo un Sprite para el Player
	Texture * txt_player; //Textura para Sprite del Player
	int spr_actual;
	int cant_x;
	int cant_y;
	Vector2i frame_n; //Frame actual
	Vector2f frame_size;

private:
	sprite_a();
	tempresources* tr = tempresources::get_res();
};