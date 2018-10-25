// Pacman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <array>

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include "Entidad.h";

// usare este arreglo para dibujar el 
// maze
char Laberiento[6][5]{
	{ 1,0,0,0,1},
	{ 0,0,1,0,0 },
	{ 0,1,1,1,0 },
	{ 0,0,1,0,0 },
	{ 1,0,0,0,1 },
	{ 1,1,0,1,1}
};
const float FPS = 60.0f;

void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap , ALLEGRO_DISPLAY *Display) {
	// son para controlar donde va a 
	//dibujar la imagen 
	int PosX = 0; 
	int PosY = 0;
	//esto es para dibujar la imagen 
	int AnchuraBitmap = al_get_bitmap_width(Bitmap);
	int AlturaBitmap = al_get_bitmap_height(Bitmap);
	
	/* esto es por si quiero dividir la pantalla en 20 pueda hacer eso*/

	float AnchuraDePantalla = al_get_display_width(Display);
	float AlturaDePantalla = al_get_display_height(Display);
		
	for (int i = 0; i < 6; ++i) {
		for(int j = 0; j<5 ;++j)
		{
			
			if (Laberiento[i][j] == 1)
			{
				al_draw_scaled_bitmap(Bitmap, 0.0f, 0.0f, AnchuraBitmap, AlturaBitmap, PosX + (AnchuraDePantalla / 12), PosY, AnchuraDePantalla / 6, AlturaDePantalla / 6, 0);
			}
		
			PosX += AnchuraDePantalla / 6;
			al_flip_display();
	
		}
		PosX = 0;
		PosY += AlturaDePantalla / 6;
	
	}


}


int main(int args, char** argv)
{
	// para crear la Ventana 
	ALLEGRO_DISPLAY *Ventana = NULL;
	ALLEGRO_BITMAP *I_Maze = NULL;
	ALLEGRO_EVENT_QUEUE	*Evento = NULL;
	ALLEGRO_TIMER *Timer = NULL;

	
	if (al_init() == false) {
		fprintf(stderr, "Fracaso de iniciar allgro ");
		return -1;
	}

	Ventana = al_create_display(1280, 720);

	// verifica si la ventana se logro a crear
	// el display
	if (!Ventana) {
		fprintf(stderr, "Fracaso de crear la ventana ");
		return -1;
	}
	// para tener la habilidad de usar imagenes 
	if(!al_init_image_addon())
	{
		fprintf(stderr, "Fracaso de cargar los Image addon");
		al_destroy_display(Ventana);
		return -1;
	
	}
	
	I_Maze = al_load_bitmap("Cobbles-Yuma-Cobble.jpg");
// para  crear el timer y decidir la frecuencia de los 
	// eventos 
	Timer = al_create_timer(1.0/FPS);

	// si no inicio el timer printra un mesaje de error 
	if (!Timer) {
		fprintf(stderr, "Error El timer no fue iniciado");
		al_destroy_display(Ventana);
		return -1;

	}

	if(!I_Maze){
		fprintf(stderr, "Fracaso de cargar la imagen ");
		al_destroy_display(Ventana);
		return -1;
	}
	// para iniciar los eventos 
	Evento = al_create_event_queue();

	if (!Evento) {
		fprintf(stderr, "Error los ALLEGRO_EVENT_QUEUE NO INICIARON");
		al_destroy_display(Ventana);
		al_destroy_bitmap(I_Maze);
		return -1;
	}

	al_register_event_source(Evento, al_get_display_event_source(Ventana));
	al_register_event_source(Evento, al_get_timer_event_source(Timer));


	ALLEGRO_EVENT OtroEvento;

	int Posicion = 0;
	// para comenzar el timer 
	al_start_timer(Timer);
	// para cambiar el color de la pantalla 
	al_clear_to_color(al_map_rgb(0, 0, 0));
	// para Dibujar El Laberiento del juego 
	DibujarLaberiento(I_Maze, Ventana);

	while(1)
	{


		al_wait_for_event(Evento, &OtroEvento);

			// verifica si el clicamos a la 'x' de la parte derecha 
			//	superior de la ventan


			if( OtroEvento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				break;
			}
				//este evento es para que algo occura cada cierta 
			// cantidad de tiempo 
			else if( OtroEvento.type == ALLEGRO_EVENT_TIMER)
			{
				//para cambiar el color de la pantalla 
		


				// para dibujar la imagen y dictar donde va

		/*			int Anchura = al_get_bitmap_width(I_Maze);
				int Altura = al_get_bitmap_height(I_Maze);*/

				// esto escala la imagen y puede crear multiples de la 
				//misma 
		/*		al_draw_scaled_bitmap(I_Maze, 0.0f, 0.0f, Anchura, Altura, 0, 0, 50, 50, 0);
				al_draw_scaled_bitmap(I_Maze, 0.0f, 0.0f, Anchura, Altura, Posicion, 50, 50, 50, 0);*/

				(Posicion < 200) ? Posicion += 10 : Posicion = 0;

				al_flip_display();
			}
	
	
	}

	//para cambiar el color de la pantalla 
	al_clear_to_color(al_map_rgb(0, 0, 0));


	// para dibujar la imagen y dictar donde va

	int Anchura = al_get_bitmap_width(I_Maze);
	int Altura = al_get_bitmap_height(I_Maze);

	// esto escala la imagen y puede crear multiples de la 
	//misma 
	al_draw_scaled_bitmap(I_Maze, 0.0f, 0.0f, Anchura, Altura, 0, 0, 50, 50, 0);
	al_draw_scaled_bitmap(I_Maze, 0.0f, 0.0f, Anchura, Altura, 50, 50, 50, 50, 0);

	// para demostrar lo que esta en el buffer
	al_flip_display();

	//al_rest(10);


	al_destroy_display(Ventana);
	al_destroy_bitmap(I_Maze);
	al_destroy_event_queue(Evento);
	al_destroy_timer(Timer);
    return 0;
}

