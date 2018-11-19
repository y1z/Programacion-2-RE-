#include "stdafx.h"
#include "Entidad.h"


Entidad::Entidad()
{
}


Entidad::~Entidad()
{
}

// esta funcion me deja conseguir la escala
void Entidad::getEscala(ALLEGRO_DISPLAY *display,char AnchuraDeMatriz, char AlturaDeMatriz)
{
	M_EscalaHorizontal = al_get_display_width(display) / AnchuraDeMatriz;
	M_EscalaVertical = al_get_display_height(display) / AlturaDeMatriz;
}
