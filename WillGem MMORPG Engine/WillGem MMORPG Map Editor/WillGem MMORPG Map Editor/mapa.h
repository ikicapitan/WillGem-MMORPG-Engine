#pragma once
#include "SFML\Graphics.hpp"
#include "tile.h"
#include "sprite_a.h"
#include <fstream>


using namespace sf;

class mapa {
public:
	mapa(RenderWindow &window, Vector2i n_map);
	void iniciar();
	void renderizar(); //Dibujar el mapa (todos sus sprites y tiles)
	void dibujar_grids();
	void dibujar_tiles();
	void llenar_mapa(Vector2i n_tile, unsigned short n_tileset, unsigned short n_capa);
	void load_mapa();
	void save_mapa();
	void reset_map();
	void remove_data(Vector2i num_grilla);
	void set_data(Vector2i num_grilla, Vector2i num_tile, unsigned short num_tileset);
	tile get_data(Vector2i num_grilla);
	std::map <std::pair<int, int>,tile>  tilemap; //Lista Grillas o Tiles en un Array de Capas
	Vector2u get_gdim() { return dim_grillas; }
	

private:
	Vector2u n_grillas; //Cantidad grillas en el mapa
	Vector2u dim_grillas; //Dimension de grillas en el mapa
	Vector2i n_mapa; //Numero de Mapa
	Uint16 capas = 4; //Cantidad de capas por grilla
	RenderWindow * ventana;
	sprite_a * spr_tile = sprite_a::get_sprite();
	
};