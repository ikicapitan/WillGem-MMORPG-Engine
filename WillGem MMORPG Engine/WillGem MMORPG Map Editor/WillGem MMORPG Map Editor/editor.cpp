#include "editor.h"

editor::editor()
{
	ventana = new RenderWindow(VideoMode(800, 600), "WillGem MMORPG Map Editor");
	iniciar();
	gameloop();
}

void editor::iniciar()
{
	reloj = new Clock();
	tiempo = new Time();
	map = new mapa(*ventana);
}

void editor::gameloop()
{
	while (!gameOver)
	{
		*tiempo = reloj->getElapsedTime(); //Obtengo tiempo transcurrido
		if (tiempo->asSeconds() > 1 / fps) //Si es mayor al fps ejecuto
		{
			ventana->clear(); //Limpio ventana

			map->llenar_mapa(Vector2i(0,0), 1, 0); //Llena el mapa con pasto (ejemplo)
			map->llenar_mapa(Vector2i(0, 8), 1, 1); //Llena el mapa con pasto (ejemplo)

			map->renderizar(); //Dibuja mapa, grillas, etc

			ventana->display(); //Muestro ventana
			reloj->restart(); //Reseteo reloj
		
		}
	}
}

