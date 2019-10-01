#include "tile.h"

tile::tile(Vector2i ngrilla, Vector2i ntile, unsigned short ntileset)
{
	num_grilla = ngrilla;
	num_tile = ntile;
	num_tileset = ntileset;
}

bool tile::operator==(tile t)
{
	return num_grilla == t.num_grilla ;
}