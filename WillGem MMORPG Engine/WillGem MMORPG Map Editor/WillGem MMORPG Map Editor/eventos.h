#pragma once
#include "SFML\Graphics.hpp"
#include "mapa.h"
#include "mouse.h"

using namespace sf;

class eventos
{

public:
	static eventos *get_event();
	void procesar_eventos(RenderWindow & ventana, View &cam, mapa &map, mouse &m);
	void check_camera(RenderWindow& ventana, View &cam);
	Event * evento;

private:
	eventos();
	const float vel_desp_cam = 0.5f;

};