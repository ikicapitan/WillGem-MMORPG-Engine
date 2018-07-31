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
	String path = "Sprites/" + to_string(spr_clase) + ".png"; //Texto que contiene el directorio o archivo a cargar (ruta)
	txt_player->loadFromFile(path); //Cargo el recurso desde la ruta o path
	spr_player = new Sprite(*txt_player); //Creo un nuevo Sprite a partir de dicha textura cargada
	frame_size = Vector2f(txt_player->getSize().x / cant_x, txt_player->getSize().y / cant_y); //Obtengo la dimension o tamaño de cada frame diviendo el tamaño del recurso por cantidad de frames
	frame_n = fr_a; //Frame actual
	seleccionar_frame();
}

void sprite_a::seleccionar_frame()
{
	IntRect rectangulo(frame_n.x * frame_size.x, frame_n.y * frame_size.y, frame_size.x, frame_size.y);
	spr_player->setTextureRect(rectangulo);
}