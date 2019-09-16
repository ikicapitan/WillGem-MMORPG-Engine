#pragma once
#include "SFML\Graphics.hpp"
#include "sprite_a.h"
#include "tile.h"

using namespace sf;

class mouse
{
public:
	mouse();
	void renderizar(RenderWindow &ventana);
	void actualizar_pos(RenderWindow& ventana);
	sprite_a get_spr() { return *spr_mouse; }
private:
	sprite_a * spr_mouse = sprite_a::get_sprite();
	tile * tile_mouse;
};