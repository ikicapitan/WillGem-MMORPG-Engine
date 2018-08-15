#pragma once
#include "SFML\Graphics.hpp"
#include "sprite_a.h"

using namespace sf;

class player : public sprite_a
{
public:
	player(int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a);
	Sprite get_spr() { return *spr_player; } //Obtener el Sprite del Player
	Vector2f get_pos() { return posicion;  }
	void set_pos(Vector2f position) { posicion = position; spr_player->setPosition(posicion); }
	bool caminando = false;

private:
	Vector2f posicion;
	
};