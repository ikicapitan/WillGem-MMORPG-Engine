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
	map = new mapa(*ventana,Vector2i(0,0));
	ventana->setMouseCursorVisible(false);
	camara1 = View(FloatRect(0, 0, 800, 600));
}

void editor::gameloop()
{
	while (!gameOver)
	{
		*tiempo = reloj->getElapsedTime(); //Obtengo tiempo transcurrido
		if (tiempo->asSeconds() > 1 / fps) //Si es mayor al fps ejecuto
		{
			procesar_logic(); //Procesamos logicas, eventos y demas

			ventana->clear(); //Limpio ventana

			//map->llenar_mapa(Vector2i(0,0), 1, 0); //Llena el mapa con pasto (ejemplo)
			//map->llenar_mapa(Vector2i(0, 8), 1, 1); //Llena el mapa con pasto (ejemplo)
			

			map->renderizar(); //Dibuja mapa, grillas, etc

			cursor.renderizar(*ventana);

			ventana->setView(camara1);

			ventana->display(); //Muestro ventana
			
			reloj->restart(); //Reseteo reloj
			
		}
	}
}

void editor::procesar_eventos()
{
	while (ventana->pollEvent(*evento->evento))
	{
		evento->procesar_eventos(*ventana, camara1, *map, cursor);
	}

	evento->check_camera(*ventana, camara1);
}


void editor::procesar_logic()
{
	procesar_eventos();

}

