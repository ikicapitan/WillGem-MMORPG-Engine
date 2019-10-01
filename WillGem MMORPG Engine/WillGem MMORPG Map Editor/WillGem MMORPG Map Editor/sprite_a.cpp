#include "sprite_a.h"

using namespace std;

sprite_a::sprite_a()
{
	
}

void sprite_a::set_sprite(int spr_clase, int cant_x1, int cant_y1, Vector2i fr_a)
{
	
	cant_x = cant_x1; //Cantidad grillas o casilleros o frames en X
	cant_y = cant_y1; //Idem pero en Y
	spr_actual = spr_clase; //Numero de Sprite a cargar
	txt_player = new Texture(); //Textura o Recurso de Imagen
	txt_player = &tr->get_tt(spr_clase);
	spr_player = new Sprite(*txt_player); //Creo un nuevo Sprite a partir de dicha textura cargada
	frame_size = Vector2f(txt_player->getSize().x / cant_x, txt_player->getSize().y / cant_y); //Obtengo la dimension o tamaño de cada frame diviendo el tamaño del recurso por cantidad de frames
	frame_n = fr_a; //Frame actual
	seleccionar_frame();
	
}

void sprite_a::set_sprite(String path)
{
	txt_player = new Texture();
	txt_player->loadFromFile(path);
	spr_player = new Sprite(*txt_player);

}

void sprite_a::seleccionar_frame()
{
	IntRect rectangulo(frame_n.x * frame_size.x, frame_n.y * frame_size.y, frame_size.x, frame_size.y);
	spr_player->setTextureRect(rectangulo);
}

void sprite_a::animar_frame()
{
	if (frame_n.x != cant_x - 1) //Si aun no alcancé el ultimo frame
	{
		frame_n.x += 1; //Incremento un frame
	}
	else
	{
		frame_n.x = 0; //Reseteo a frame 0 (vuelve al principio)
	}
	
	seleccionar_frame(); //Selecciono el rectangulo correspondiente al frame
}

void sprite_a::set_frame_x(int frame)
{
	frame_n.x = frame;
	seleccionar_frame();
}

void sprite_a::set_frame_y(int frame)
{
	frame_n.y = frame;
	seleccionar_frame();
}

sprite_a *sprite_a::get_sprite()
{
	static sprite_a spr;
	return &spr;
}