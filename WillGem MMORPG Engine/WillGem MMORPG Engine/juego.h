#pragma once
#include "SFML\Graphics.hpp"
#include "jugador.h"

using namespace sf;

class juego
{
public:
	juego(Vector2u resolucion);
	void iniciar(); //Inicializacion de variables y diferentes aspectos importantes
	void renderizar(); //Dibujando en pantalla de los elementos del juego
	void procesar_logic(); //Procesa logicas del juego
	void procesar_networking();
	void gameloop();

private:
	player * j1; //Jugador 1
	RenderWindow * ventana;
	bool gameover = false;
	
	int fps;
	Clock * reloj1;
	Time * cronometro1;
};