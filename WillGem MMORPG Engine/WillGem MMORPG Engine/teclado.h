#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class teclado
{
private:
	teclado();

public:
	static teclado* get_teclado();
	bool teclas_j1[4]; //Izquierda, derecha, arriba y abajo
	Event * evento;
	void procesar_eventos();
	
};