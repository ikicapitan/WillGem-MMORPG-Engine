#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class boton
{
public:
	boton(String identidad, RectangleShape rect) { id = identidad; r = rect; }
	RectangleShape get_rect() { return r; }
	String get_id() { return id; }
private:
	RectangleShape r;
	String id;
};