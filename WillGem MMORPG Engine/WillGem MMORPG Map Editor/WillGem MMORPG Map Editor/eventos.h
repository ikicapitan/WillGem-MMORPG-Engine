#pragma once
#include "SFML\Graphics.hpp"
#include "mapa.h"
#include "mouse.h"
#include "boton.h"

using namespace sf;

enum estados_panel { insertar, copiar, llenar, flip, vaciar, guardar };


class eventos
{

public:
	static eventos *get_event();
	void procesar_eventos(RenderWindow & ventana, View &cam, mapa &map, mouse &m);
	void procesar_editor(RenderWindow& ventana, mouse &m, std::vector <boton> r, mapa &map);
	void check_camera(RenderWindow& ventana, View &cam);
	Event * evento;

private:
	eventos();
	const float vel_desp_cam = 0.5f;
	estados_panel est_pan = estados_panel::insertar;
	
};