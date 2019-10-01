#include "editor.h"

editor::editor()
{
	ventana = new RenderWindow(VideoMode(800, 600), "WillGem MMORPG Map Editor");
	panel_editor = new RenderWindow(VideoMode(220, 300), "Menu Editor");
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
	fuente = new Font;

	fuente->loadFromFile("Resources/Fonts/Karate.ttf");


	for (int i = 0; i < 6; i++)
	{
		String id = "";
		RectangleShape* r = new RectangleShape({ 60,16 });
		r->setFillColor(Color::Blue);
		switch(i)
		{
		case 0:
			r->setPosition({ 35,170 });
			id = "insertar";
			break;

		case 1:
			r->setPosition({ 115,170 });
			id = "copiar";
			break;

		case 2:
			r->setPosition({ 35,210 });
			id = "llenar";
			break;

		case 3:
			r->setPosition({ 115,210 });
			id = "flip";
			break;

		case 4:
			r->setPosition({ 35,250 });
			id = "vaciar";
			break;

		case 5:
			r->setPosition({ 115,250 });
			id = "guardar";
			break;
		}

		opciones_panel.push_back(boton(id,*r));
		txt_btn_editor[i] = new Text("", *fuente);
		txt_btn_editor[i]->setCharacterSize(10);
	}


	

	txt_btn_editor[0]->setPosition({ 39,171 });
	txt_btn_editor[1]->setPosition({ 125,171 });
	txt_btn_editor[2]->setPosition({ 43,211 });
	txt_btn_editor[3]->setPosition({ 132,211 });
	txt_btn_editor[4]->setPosition({ 44,251 });
	txt_btn_editor[5]->setPosition({ 120,251 });

	txt_btn_editor[0]->setString("INSERTAR");
	txt_btn_editor[1]->setString("COPIAR");
	txt_btn_editor[2]->setString("LLENAR");
	txt_btn_editor[3]->setString("FLIP");
	txt_btn_editor[4]->setString("VACIAR");
	txt_btn_editor[5]->setString("GUARDAR");

	int contador = 0;



	
	
	
	
	
	

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

			panel_editor->clear();

			//map->llenar_mapa(Vector2i(0,0), 1, 0); //Llena el mapa con pasto (ejemplo)
			//map->llenar_mapa(Vector2i(0, 8), 1, 1); //Llena el mapa con pasto (ejemplo)

			map->renderizar(); //Dibuja mapa, grillas, etc

			cursor.renderizar(*ventana);

			ventana->setView(camara1);

			ventana->display(); //Muestro ventana
			
			render_panel(); //Muestro el Panel Editor

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

	while (panel_editor->pollEvent(*evento->evento))
	{
		evento->procesar_editor(*panel_editor, cursor, opciones_panel, *map);
	}

	evento->check_camera(*ventana, camara1);
}


void editor::procesar_logic()
{
	procesar_eventos();

}

void editor::render_panel()
{
	
	panel_editor->clear();

	for each (boton button in opciones_panel)
	{
		panel_editor->draw(button.get_rect());
	}

	for (int i = 0; i < 6; i++)
	{
		
		panel_editor->draw(*txt_btn_editor[i]);
	}

	
	if(panel_editor->hasFocus())
		cursor.renderizar(*panel_editor);
	
	panel_editor->display();
	
}