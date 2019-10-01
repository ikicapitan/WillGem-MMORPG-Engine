#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>


using namespace sf;

class tempresources
{
public:
	static tempresources* get_res();
	Texture & get_tt(int elemento) { return temp_tiles[elemento]; } //Devuelve temp tiles
private:
	tempresources();
	std::map <int,Texture> temp_tiles; //Tiles archivos precargados
};