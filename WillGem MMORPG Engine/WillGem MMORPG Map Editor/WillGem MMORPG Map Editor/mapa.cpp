#include "mapa.h"
#include <iostream>
using namespace std;

mapa::mapa(RenderWindow &window, Vector2i n_map)
{
	ventana = &window;
	n_mapa = n_map;
	iniciar();
}


void mapa::iniciar()
{
	n_grillas = Vector2u(25, 19); 
	dim_grillas = Vector2u(32, 32);
	//tilemap = new vector<tile>[capas]; //Creo el array de listas segun numero de capas
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
			tilemap.insert(std::make_pair(std::make_pair(i,j), newTile)); //Lo agrego a la lista
		}
	}
}

void mapa::dibujar_tiles()
{
	//for (int i = 0; i < capas; i++)
	//{
	for (std::map <std::pair<int,int>, tile>::iterator t = tilemap.begin(); t != tilemap.end(); t++) //Recorro elementos de la lista uno por uno
		{
			spr_tile->set_sprite(t->second.num_tileset, 16, 16, t->second.num_tile); //Cargo cada elemento leyendo la lista y asignando el valor al Sprite creado
			spr_tile->spr_player->setPosition(t->second.num_grilla.x * dim_grillas.x, t->second.num_grilla.y * dim_grillas.y); //Posiciono en la grilla correspondiente para dibujar
			ventana->draw(*spr_tile->spr_player);
		}
	//}
}


void mapa::load_mapa()
{
	string nombre_archivo;
	nombre_archivo = "Resources/Mapas/" + to_string(n_mapa.x) + "-" + to_string(n_mapa.y) + ".dat";

	ifstream map(nombre_archivo.c_str(), ios::binary); //Abrimos archivo para escritura en cifrado binario

	if (map.fail()) //Si fallo al abrir
		reset_map();
	else
	{
		//for (int i = 0; i < capas; i++)
		//{
		
			for (std::map <std::pair<int, int>, tile>::iterator t = tilemap.begin(); t != tilemap.end(); t++) //Recorro elementos de la lista uno por uno
			{
				map.read(reinterpret_cast<char*>(&t->second.num_grilla), sizeof(unsigned short)); //Escribimos datos en orden
				map.read(reinterpret_cast<char*>(&t->second.num_tile), sizeof(unsigned short));
				map.read(reinterpret_cast<char*>(&t->second.num_tileset), sizeof(unsigned short));
			}
		//}
	}
}


void mapa::reset_map()
{
	//for (int i = 0; i < capas; i++)
	//{
		tilemap.clear(); //Vaciamos elementos de la lista de tiles en cada capa
	//}
}

void mapa::save_mapa()
{
	string nombre_archivo;
	nombre_archivo = "Resources/Mapas/" + to_string(n_mapa.x) + "-" + to_string(n_mapa.y) + ".dat";

	ofstream map(nombre_archivo.c_str(), ios::binary); //Abrimos archivo para escritura en cifrado binario

	//for (int i = 0; i < capas; i++) //Recorremos las capas
	//{
	
		for (std::map <std::pair<int, int>, tile>::iterator t = tilemap.begin(); t != tilemap.end(); t++) //Recorro elementos de la lista uno por uno
		{
			map.write(reinterpret_cast<const char*>(&t->second.num_grilla), sizeof(unsigned short)); //Escribimos datos en orden
			map.write(reinterpret_cast<const char*>(&t->second.num_tile), sizeof(unsigned short));
			map.write(reinterpret_cast<const char*>(&t->second.num_tileset), sizeof(unsigned short));
		}
		
	//}

	map.close();
}

void mapa::set_data(Vector2i num_grilla, Vector2i num_tile, unsigned short num_tileset)
{
	tile t = tile(num_grilla, num_tile, num_tileset);
	tilemap.insert(std::make_pair(std::make_pair(num_grilla.x, num_grilla.y), t));
}

void mapa::remove_data(Vector2i num_grilla)
{
	tilemap.erase(std::make_pair(num_grilla.x,num_grilla.y)); //Esta linea parece ser el error ¿?
}

tile mapa::get_data(Vector2i num_grilla)
{
	//for (int i = 0; i < tilemap->size(); i++)
	//{
		//if (tilemap->at(i).num_grilla == num_grilla)
		//{
		
			return tilemap.at(std::make_pair(num_grilla.x,num_grilla.y));
		//}
	//}
}