#include "mouse.h"

mouse::mouse()
{
	spr_mouse->set_sprite("Resources/Gui/cursor_1.png");
	tile_mouse = new tile(Vector2i(0, 0), Vector2i(0, 0), 1);
}

void mouse::renderizar(RenderWindow &ventana)
{
	actualizar_pos(ventana);
	ventana.draw(*spr_mouse->spr_player);
}

void mouse::actualizar_pos(RenderWindow& ventana)
{
	spr_mouse->spr_player->setPosition(ventana.mapPixelToCoords(Mouse::getPosition(ventana)));
}