#include "tempresources.h"

tempresources::tempresources()
{
	
	bool chequeando = true;
	int contador = 1;

	while (chequeando)
	{
		Texture t;
		String path = "Resources/Tileset/" + std::to_string(contador) + ".png"; //Texto que contiene el directorio o archivo a cargar (ruta)
		if (t.loadFromFile(path)) //Cargo el recurso desde la ruta o path
		{
			temp_tiles.insert(std::make_pair(contador, t));
			contador++;
		}
		else
		{
			chequeando = false;
		}
	}
}


tempresources* tempresources::get_res()
{
	static tempresources t;
	return &t;
}