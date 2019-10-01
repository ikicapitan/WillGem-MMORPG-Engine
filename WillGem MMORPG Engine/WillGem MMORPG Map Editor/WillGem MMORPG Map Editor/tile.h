#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class tile {
public:
	tile(Vector2i ngrilla, Vector2i ntile, unsigned short ntileset);
	Vector2i num_grilla; //En que numero de grilla se dibujara
	Vector2i num_tile; //Numero de tile XY en la plantilla seleccionada
	unsigned short num_tileset; //Numero de plantilla o archivo seleccionado
	bool operator == (tile t);
private:
};