#include "mapa.h"
#include <iostream>
using namespace std;

mapa::mapa(RenderWindow &window)
{
	ventana = &window;
	iniciar();
}


void mapa::iniciar()
{
	n_grillas = Vector2u(25, 19); 
	dim_grillas = Vector2u(32, 32);
	tilemap = new list<tile>[capas]; //Creo el array de listas segun numero de capas
}

void mapa::renderizar()
{
	dibujar_tiles();
	dibujar_grids();

}

void mapa::dibujar_grids() //Dibujamos las grillas
{
	RectangleShape linea_vertical(Vector2f(1, n_grillas.x * dim_grillas.x)); //Linea vertical para dibujar grillas
	linea_vertical.setFillColor(Color::White); //Lineas blancas
	
	
	for (int i = 1; i <= n_grillas.x; i++)
	{
		linea_vertical.setPosition(i*dim_grillas.x, 0);
		ventana->draw(linea_vertical);		
	}

	
	linea_vertical.rotate(270);

	for (int i = 1; i <= n_grillas.y; i++)
	{
		linea_vertical.setPosition(0, i*dim_grillas.y);
		ventana->draw(linea_vertical);
	}


}

void mapa::llenar_mapa(Vector2i n_tile, unsigned short n_tileset, unsigned short n_capa)
{
	for (int i = 0; i < n_grillas.x; i++) //Filas y columnas recorro
	{
		for (int j = 0; j < n_grillas.y; j++)
		{
			tile newTile(Vector2i(i, j), n_tile, n_tileset); //Creo un nuevo tile
			tilemap[n_capa].push_back(newTile); //Lo agrego a la lista
		}
	}
}

void mapa::dibujar_tiles()
{
	for (int i = 0; i < capas; i++)
	{
		for each(tile t in tilemap[i]) //Recorro elementos de la lista uno por uno
		{
			spr_tile->set_sprite(t.num_tileset, 16, 16, t.num_tile); //Cargo cada elemento leyendo la lista y asignando el valor al Sprite creado
			spr_tile->spr_player->setPosition(t.num_grilla.x * dim_grillas.x, t.num_grilla.y * dim_grillas.y); //Posiciono en la grilla correspondiente para dibujar
			ventana->draw(*spr_tile->spr_player);
		}
	}
}