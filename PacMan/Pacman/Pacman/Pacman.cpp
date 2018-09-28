// Pacman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<allegro5/allegro.h>


int main(int args, char** argv)
{
	// para crear la Ventana 
	ALLEGRO_DISPLAY * Ventana = NULL;


	if (al_init() == false) {
		std::cout << "fracaso de iniciar el Programa " << std::endl;
		return -1;
	}

	Ventana = al_create_display(640, 480);

	// verifica si la ventana se logro a crear
	if (!Ventana) {
		std::cout << "Fracaso de crear la ventana ";
		return -1;
	}
	//
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_rest(10);


	al_destroy_display(Ventana);
    return 0;
}

