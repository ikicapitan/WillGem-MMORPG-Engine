#include <iostream>
#include "SFML\Graphics.hpp"
#include "juego.h"

using namespace std;
using namespace sf;

int main(int argc, char * args[])
{
	juego * game = new juego(Vector2u(800, 600));

	return 0;
}