#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class player
{
public:
	player();
	Sprite get_spr() { return *spr_player; } //Obtener el Sprite del Player
	Vector2f get_pos() { return posicion;  }
	void set_pos(Vector2f position) { posicion = position; spr_player->setPosition(posicion); }
private:
	Sprite * spr_player; //Creo un Sprite para el Player
	Texture * txt_player; //Textura para Sprite del Player
	Vector2f posicion;

};