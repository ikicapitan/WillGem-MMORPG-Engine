#include "mapa.h"


mapa::mapa(RenderWindow &window)
{
	ventana = &window;
}


void mapa::iniciar()
{
	n_grillas = Vector2u(10, 10); 
	dim_grillas = Vector2u(32, 32);
}

void mapa::renderizar()
{

}