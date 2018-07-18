#include "jugador.h"

player::player()
{
	txt_player = new Texture();
	txt_player->loadFromFile("Sprites/IKI2.png");
	spr_player = new Sprite(*txt_player);
}