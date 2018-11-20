#pragma once
#include "SFML\Graphics.hpp"
#include "tile.h"
#include "sprite_a.h"
#include <list>

using namespace sf;

class mapa {
public:
	mapa(RenderWindow &window);
	void iniciar();
	void renderizar(); //Dibujar el mapa (todos sus sprites y tiles)
	void dibujar_grids();
	void dibujar_tiles();
	void llenar_mapa(Vector2i n_tile, unsigned short n_tileset, unsigned short n_capa);
	std::list <tile> * tilemap; //Lista Grillas o Tiles en un Array de Capas
	

private:
	Vector2u n_grillas; //Cantidad grillas en el mapa
	Vector2u dim_grillas; //Dimension de grillas en el mapa
	Uint16 capas = 4; //Cantidad de capas por grilla
	RenderWindow * ventana;
	sprite_a * spr_tile = sprite_a::get_sprite();
	
};