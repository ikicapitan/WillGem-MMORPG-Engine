#pragma once
#include "SFML\Graphics.hpp"
#include "mapa.h"

using namespace sf;

class editor {

public:
	editor();
	void gameloop();
	void iniciar();


private:
	RenderWindow * ventana;
	bool gameOver = false;
	int fps = 60;
	Clock * reloj;
	Time * tiempo;
	mapa * map; //Mapa del Juego
};