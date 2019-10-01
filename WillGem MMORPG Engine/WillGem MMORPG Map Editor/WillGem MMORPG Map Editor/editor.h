#pragma once
#include "SFML\Graphics.hpp"
#include "mapa.h"
#include "eventos.h"
#include "mouse.h"
#include "boton.h"

using namespace sf;

class editor {

public:
	editor();
	void gameloop();
	void procesar_eventos();
	void procesar_logic();
	void iniciar();
	void render_panel();


private:
	RenderWindow * ventana;
	RenderWindow* panel_editor;
	std::vector <boton> opciones_panel;
	bool gameOver = false;
	int fps = 60;
	Clock * reloj;
	Time * tiempo;
	mapa * map; //Mapa del Juego
	eventos * evento = eventos::get_event();
	mouse cursor;
	View camara1;

	Font* fuente;
	Text* txt_btn_editor[6];
};