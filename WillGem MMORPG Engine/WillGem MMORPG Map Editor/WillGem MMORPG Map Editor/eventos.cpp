#include "eventos.h"

eventos::eventos()
{
	evento = new Event;
}

eventos* eventos::get_event()
{
	static eventos ev;
	return &ev;
}

void eventos::procesar_eventos(RenderWindow& ventana, View& cam, mapa &map, mouse &m)
{

	
	switch (evento->type)
	{
	case Event::KeyPressed:
		//Zoom In
		if (Keyboard::isKeyPressed(Keyboard::Add)) //++
		{

		}
		else if (Keyboard::isKeyPressed(Keyboard::Subtract)) //-- Zoom out
		{

		}

		//Zoom Out
		break;

	case Event::MouseButtonReleased:
		if (evento->mouseButton.button == Mouse::Left) //Boton izquierdo del mouse
		{
			switch (est_pan)
			{
			case 0:
				map.set_data(Vector2i(m.get_spr().spr_player->getPosition().x / map.get_gdim().x, m.get_spr().spr_player->getPosition().y / map.get_gdim().y), m.get_tmouse().num_tile, m.get_tmouse().num_tileset);
				break;

			case 1:
				m.set_tmouse(map.get_data(Vector2i(m.get_spr().spr_player->getPosition().x / map.get_gdim().x, m.get_spr().spr_player->getPosition().y / map.get_gdim().y)));
				break;

			case 2:
				map.reset_map();
				map.llenar_mapa(Vector2i(0, 0), 1, 0);
				break;

			}
			
		}
		else if(evento->mouseButton.button == Mouse::Right)
		{
			map.remove_data(Vector2i(m.get_spr().spr_player->getPosition().x / map.get_gdim().x, m.get_spr().spr_player->getPosition().y / map.get_gdim().y));
		}
	break;

	case Event::MouseWheelMoved: //Zoom in zoom out
		cam.zoom(1.f + evento->mouseWheel.delta * 0.1f);
		break;

	case Event::Closed:
		exit(1);
		break;
	}

	
}

void eventos::check_camera(RenderWindow & ventana, View & cam)
{
	if (ventana.hasFocus())
	{
		if (Mouse::getPosition(ventana).x < ventana.getSize().x && Mouse::getPosition(ventana).x >(ventana.getSize().x - 20))
		{
			cam.move(vel_desp_cam, 0);
		}
		else if (Mouse::getPosition(ventana).x > 0 && Mouse::getPosition(ventana).x < 20)
		{
			cam.move(-vel_desp_cam, 0);
		}

		if (Mouse::getPosition(ventana).y < ventana.getSize().y && Mouse::getPosition(ventana).y >(ventana.getSize().y - 20))
		{
			cam.move(0, vel_desp_cam);
		}
		else if (Mouse::getPosition(ventana).y > 0 && Mouse::getPosition(ventana).y < 20)
		{
			cam.move(0, -vel_desp_cam);
		}
			
	}
}

void eventos::procesar_editor(RenderWindow& ventana, mouse& m, std::vector <boton> r, mapa &map)
{

	
	if (ventana.hasFocus())
	{
		
		switch (evento->type)
		{
			
		case Event::KeyPressed:
			
			if (Keyboard::isKeyPressed(Keyboard::Add)) //+
			{
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Subtract)) //
			{

			}

			//Zoom Out
			break;

		case Event::MouseButtonReleased:
			
			if (evento->mouseButton.button == Mouse::Left) //Boton izquierdo del mouse
			{
				Vector2i posicion_mouse;
				posicion_mouse = Mouse::getPosition(ventana);
				
				for each(boton button in r)
				{
					
					if (button.get_rect().getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y))
					{
						if (button.get_id() == "insertar")
						{
							est_pan = estados_panel::insertar;
						}
						else if (button.get_id() == "copiar")
						{
							est_pan = estados_panel::copiar;
						}
						else if (button.get_id() == "llenar")
						{
							est_pan = estados_panel::llenar;
						}
						else if (button.get_id() == "flip")
						{
							est_pan = estados_panel::flip;
						}
						else if (button.get_id() == "vaciar")
						{
							map.reset_map();
						}
						else if (button.get_id() == "guardar")
						{
							est_pan = estados_panel::guardar;
						}
					}
				}
			}
			else if (evento->mouseButton.button == Mouse::Right)
			{
				
			}
			break;


		case Event::Closed:
			exit(1);
			break;
		}
	}
}