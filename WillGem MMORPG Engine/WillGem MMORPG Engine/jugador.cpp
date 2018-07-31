#include "jugador.h"

using namespace std;

player::player(int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a)
{
	spr_player = new sprite_a();
	spr_player->set_sprite(spr_clase, cant_x1, cant_y1, fr_a);
}

