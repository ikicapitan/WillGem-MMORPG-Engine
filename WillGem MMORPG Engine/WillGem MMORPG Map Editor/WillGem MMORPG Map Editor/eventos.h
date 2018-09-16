#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class eventos
{

public:
	static eventos *get_event();
	void procesar_eventos();
	Event * evento;

private:
	eventos();


};