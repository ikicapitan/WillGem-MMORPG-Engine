#include "eventos.h"

eventos::eventos()
{
	evento = new Event;
}

eventos *eventos::get_event()
{
	static eventos ev;
	return &ev;
}

void eventos::procesar_eventos()
{

}