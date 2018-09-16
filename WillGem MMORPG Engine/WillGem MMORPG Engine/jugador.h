#pragma once
#include "SFML\Graphics.hpp"
#include "sprite_a.h"
#include "teclado.h"

using namespace sf;

enum estados {idle, walking, running, death};
enum direcciones {arriba, izq_arr, der_arr, abajo, izq_ab, der_ab, derecha, izquierda};

class player : public sprite_a
{
public:
	player(RenderWindow &ventana, int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a);
	Sprite get_spr() { return *spr_player; } //Obtener el Sprite del Player
	Vector2f get_pos() { return posicion;  }
	void update();
	void set_pos(Vector2f position) { posicion = position; spr_player->setPosition(posicion); }
	void set_translation(Vector2f translation) { posicion += translation; spr_player->setPosition(posicion); }
	void set_velocidad(Vector2f vel) { Velocidad = vel; }
	void seleccionar_velocidad();
	void procesar_eventos();
	bool caminando = false;
	float vel_walk; //Velocidad Caminar
	float vel_run; //Velocidar Correr
	direcciones direccion = derecha; //Direccion a la que mira el player

private:
	Vector2f posicion;
	Vector2f Velocidad; //Velocidad Actual
	teclado * keyboard = teclado::get_teclado();
	RenderWindow *window;
};