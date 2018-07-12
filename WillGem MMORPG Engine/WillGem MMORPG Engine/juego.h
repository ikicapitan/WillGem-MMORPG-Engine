#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class juego
{
public:
	juego(Vector2u resolucion);
	void iniciar(); //Inicializacion de variables y diferentes aspectos importantes
	void renderizar(); //Dibujando en pantalla de los elementos del juego
	void procesar_logic(); //Procesa logicas del juego
	void procesar_eventos(); //Procesa perifericos, teclado, mouse, etc
	void procesar_networking();

private:
	Event * evento;
	RenderWindow * ventana;
	bool gameover = false;
};