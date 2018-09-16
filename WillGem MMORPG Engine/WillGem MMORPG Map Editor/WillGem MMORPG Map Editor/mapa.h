#pragma once
#include "SFML\Graphics.hpp""

using namespace sf;

class mapa {
public:
	mapa(RenderWindow &window);
	void iniciar();
	void renderizar(); //Dibujar el mapa (todos sus sprites y tiles)¿

private:
	Vector2u n_grillas; //Cantidad grillas en el mapa
	Vector2u dim_grillas; //Dimension de grillas en el mapa
	Uint16 capas = 4; //Cantidad de capas por grilla
	RenderWindow * ventana;
};