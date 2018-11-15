// Pacman.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Entidad.h"
#include "LOG.h"
#include "Pacman.h"


short AlturaDeLaberinto = 0;
short AnchuraDeLaberinto = 0;

PacMan pac_man;

std::fstream file;

LOG logger;

/* con este vector de vectores podemos crear el
Laberinto */
std::vector<std::vector<char>> Laberinto;

const float FPS = 60.0f;

//void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap, ALLEGRO_DISPLAY *Display);

void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap, ALLEGRO_BITMAP *BlackScreen, ALLEGRO_DISPLAY *Display);

void DrawPacMan(ALLEGRO_BITMAP *PacMan, ALLEGRO_DISPLAY *Display, float PoX, float PoY, int slecion);

void DefinirMaze();

int main(int args, char** argv)
{
	DefinirMaze();

	// para crear la Ventana 
	ALLEGRO_DISPLAY *Ventana = NULL;
	//para dibujar images 
	ALLEGRO_BITMAP *I_Maze = NULL;
	ALLEGRO_BITMAP *I_BlackSpace = NULL;
	ALLEGRO_BITMAP *I_Pacman = NULL;
	// para crear y controlar eventos 
	ALLEGRO_EVENT_QUEUE	*EventoQueue = NULL;

	ALLEGRO_TIMER *Timer = NULL;

	if (al_init() == false) {
		fprintf(stderr, "Fracaso de iniciar allgro ");
		return -1;
	}


	Ventana = al_create_display(800, 600);

	// verifica si la ventana se logro a crear
	// el display
	if (!Ventana) {
		fprintf(stderr, "Fracaso de crear la ventana ");
		return -1;
	}
	// para tener la habilidad de usar imagenes 
	if (!al_init_image_addon())
	{
		fprintf(stderr, "Fracaso de cargar los Image addon");
		al_destroy_display(Ventana);
		return -1;
	}

	// para  crear el timer y decidir la frecuencia de los 
	// eventos 
	Timer = al_create_timer(1.0 / FPS);

	I_Maze = al_load_bitmap("Cobbles-Yuma-Cobble.jpg");

	I_Pacman = al_load_bitmap("Pac-Man Sprite.jpg");

	I_BlackSpace = al_load_bitmap("Black Screen.jpg");

	// si no inicio el timer printra un mesaje de error 
	if (!Timer) {
		fprintf(stderr, "Error El timer no fue iniciado");
		al_destroy_display(Ventana);
		return -1;
	}

	if (!I_Maze) {
		fprintf(stderr, "Fracaso de cargar la imagen ");
		al_destroy_display(Ventana);
		return -1;
	}

	if (!I_Pacman) {
		fprintf(stderr, "Fracaso de cargar la imagen pac-man ");
		al_destroy_display(Ventana);
		return -1;
	}

	if (!I_BlackSpace)
	{
		fprintf(stderr, "Fracaso de cargar la imagen BlackSpace");
		al_destroy_display(Ventana);
		return -1;
	}

	// para iniciar los eventos de cola 
	EventoQueue = al_create_event_queue();

	if (!EventoQueue) {
		fprintf(stderr, "Error los ALLEGRO_EVENT_QUEUE NO INICIARON");
		al_destroy_display(Ventana);
		al_destroy_bitmap(I_Maze);
		al_destroy_bitmap(I_BlackSpace);
		return -1;
	}

	al_register_event_source(EventoQueue, al_get_display_event_source(Ventana));
	al_register_event_source(EventoQueue, al_get_timer_event_source(Timer));

	ALLEGRO_EVENT OtroEvento;

	// para comenzar el timer 
	al_start_timer(Timer);
	// para cambiar el color de la pantalla 
	al_clear_to_color(al_map_rgb(0, 0, 0));
	// para Dibujar El Laberiento del juego 
	//DibujarLaberiento(I_Maze, Ventana);

	pac_man.M_PosicionX = 0.0f;
	pac_man.M_PosicionY = 0.0f;

	pac_man.Frame = 0;


	while (true)
	{
		al_wait_for_event(EventoQueue, &OtroEvento);

		// verifica si el clicamos a la 'x' de la parte derecha 
		//	superior de la ventan

		if (OtroEvento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		//este evento es para que algo occura cada cierta 
		// cantidad de tiempo 
		else if (OtroEvento.type == ALLEGRO_EVENT_TIMER)
		{

			// para Dibujar El Laberiento del juego 
			DibujarLaberiento(I_Maze, I_BlackSpace, Ventana);

			pac_man.Frame++;
			pac_man.Move();
			DrawPacMan(I_Pacman, Ventana, pac_man.M_PosicionX, pac_man.M_PosicionY, pac_man.Frame);

			if (pac_man.Frame == 3) {
				pac_man.Frame = 0;
			}

			al_flip_display();
		}
	}


	al_destroy_display(Ventana);
	al_destroy_bitmap(I_Maze);
	al_destroy_bitmap(I_BlackSpace);
	al_destroy_bitmap(I_Pacman);
	al_destroy_event_queue(EventoQueue);
	al_destroy_timer(Timer);
	return 0;
}



void DrawPacMan(ALLEGRO_BITMAP *PacMan, ALLEGRO_DISPLAY *Display, float PoX, float PoY, int selecion)
{
	int AnchuraBitmap = al_get_bitmap_width(PacMan);
	int AlturaBitmap = al_get_bitmap_height(PacMan);

	float AnchuraDePantalla = al_get_display_width(Display);
	float AlturaDePantalla = al_get_display_height(Display);

	switch (selecion) {
	case(1):
		al_draw_scaled_bitmap(PacMan, 36, 1, 13, 13, PoX, PoY,
			AnchuraDePantalla / AnchuraDeLaberinto,
			AlturaDePantalla / AlturaDeLaberinto, 0);
		break;
	case(2):
		al_draw_scaled_bitmap(PacMan, 4, 1, 13, 13, PoX, PoY,
			AnchuraDePantalla / AnchuraDeLaberinto,
			AlturaDePantalla / AlturaDeLaberinto, 0);
		break;
	case(3):
		al_draw_scaled_bitmap(PacMan, 20, 1, 13, 13, PoX, PoY,
			AnchuraDePantalla / AnchuraDeLaberinto,
			AlturaDePantalla / AlturaDeLaberinto, 0);
		break;
	}



}


void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap, ALLEGRO_BITMAP *BlackScreen, ALLEGRO_DISPLAY *Display) {
	// son para controlar donde va a 
	//dibujar la imagen 
	float PosX = 0;
	float PosY = 0;
	//esto es para dibujar la imagen 
	int AnchuraBitmap = al_get_bitmap_width(Bitmap);
	int AlturaBitmap = al_get_bitmap_height(Bitmap);

	int AnchuraBlack = al_get_bitmap_width(BlackScreen);
	int AlturaBlack= al_get_bitmap_height(BlackScreen);

	// esto es par tener la habilidad de divir la pantalla 
	// en 'x' cantidad 
	float AnchuraDePantalla = al_get_display_width(Display);
	float AlturaDePantalla = al_get_display_height(Display);


	// Dibujo el laberiento
	for (int i = 0; i < AlturaDeLaberinto; ++i) {
		for (int j = 0; j < AnchuraDeLaberinto; ++j)
		{
			/*todo lo que hace esto es dibjar
			la image que tengo seleccionan sobre
			la pantalla */
			if (Laberinto[i][j] == '1')
			{
				al_draw_scaled_bitmap(Bitmap,// image que dibuja 
					0.0f,
					0.0f,
					AnchuraBitmap,
					AlturaBitmap,
					PosX,
					PosY,
					AnchuraDePantalla / AnchuraDeLaberinto,// determina la anchura de la pantalla 
					AlturaDePantalla / AlturaDeLaberinto, // determina la altura de la pantalla 
					0);
			}
			else if(Laberinto[i][j] == '0')
			{
				al_draw_scaled_bitmap(BlackScreen,// image que dibuja 
					0.0f,
					0.0f,
					AnchuraBlack,
					AlturaBlack,
					PosX,
					PosY,
					AnchuraDePantalla / AnchuraDeLaberinto,// determina la anchura de la pantalla 
					AlturaDePantalla / AlturaDeLaberinto, // determina la altura de la pantalla 
					0);
			}

			PosX += AnchuraDePantalla / AnchuraDeLaberinto;
		}
		PosX = 0;
		PosY += AlturaDePantalla / AlturaDeLaberinto;
	}

}

void DefinirMaze() {
	// estas dos variable son para 
	// saber que tan grande esta sera 
	// el arreglo 
	AlturaDeLaberinto = 0;
	AnchuraDeLaberinto = 0;

	char ValorDeLaberinto = '\0';

	file.open("Laberinto.txt");
	// primero averiguamos cuantos elementos 
	// tendra el laberinto 
	file >> AlturaDeLaberinto >> AnchuraDeLaberinto;
	// creamos las columnas del laberinto
	Laberinto.resize(AlturaDeLaberinto);
	// definimos que anchar seran las filas 
	for (int i = 0; i < Laberinto.size(); ++i) {
		Laberinto[i].resize(AnchuraDeLaberinto);
	}

	// asignamos los valore del Mapa 
	// para el juego 
	for (int i = 0; i < AlturaDeLaberinto; ++i)
	{
		for (int j = 0; j <AnchuraDeLaberinto; ++j)
		{
			file >> ValorDeLaberinto;
			Laberinto[i][j] = ValorDeLaberinto;
		}
	}

	if (logger.M_LogLevel == logger.M_LogSeguro)
	{
		for (int i = 0; i < AlturaDeLaberinto; ++i)
		{
			for (int j = 0; j < AnchuraDeLaberinto; ++j)
			{
				std::cout << Laberinto[i][j];
			}
			std::cout << '\n';
		}

	}

	file.close();
}