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
			map.set_data(Vector2i(m.get_spr().spr_player->getPosition().x / map.get_gdim().x, m.get_spr().spr_player->getPosition().y / map.get_gdim().y), Vector2i(0, 0), 1);
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