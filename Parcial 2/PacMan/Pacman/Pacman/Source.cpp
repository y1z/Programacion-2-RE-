// Pacman.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Entidad.h"
#include "LOG.h"
#include "Tablero.h"
#include "Pacman.h"

// usare estos valore para consiguir la escala 
// de todos los demas objetos 
short AlturaDeLaberinto = 0;
short AnchuraDeLaberinto = 0;

static PacMan *ptr_Player = new PacMan;

Tablero *ptr_tablero = new Tablero;

std::fstream file;
// para marcar errores 
LOG logger;

const float FPS = 60.0f;

void DefinirMaze();

void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap, ALLEGRO_BITMAP *BlackScreen, ALLEGRO_DISPLAY *Display);

std::string QuitarEspaciosEnBlanco(std::string &);

int main(int args, char** argv)
{
	logger.setLevel(0);
	DefinirMaze();

	// para crear la Ventana 
	ALLEGRO_DISPLAY *Ventana = NULL;
	//para dibujar images 
	ALLEGRO_BITMAP *I_Maze = NULL;
	ALLEGRO_BITMAP *I_BlackSpace = NULL;
	ALLEGRO_BITMAP *I_Pacman = NULL;
	// para tener una lista de todos los 
	// eventos para el juego 
	ALLEGRO_EVENT_QUEUE	*EventoQueue = NULL;

	ALLEGRO_TIMER *TimerMain = NULL;

	

	if (al_init() == false) {
		fprintf(stderr, "Fracaso de iniciar allgro ");
		return -1;
	}

	if(!al_install_keyboard())
	{
		fprintf(stderr, "Fracaso de iniciar el teclado ");
		return -1;
	}

	Ventana = al_create_display(800, 600);

	// verifica si se logro a crear
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
	// eventos como el movimiento y logica del juego 
	TimerMain = al_create_timer(1.0 / FPS);

	//TimerAnimacion = al_create_timer(20.0 / FPS);
	
	I_Maze = al_load_bitmap("Cobbles-Yuma-Cobble.jpg");

	I_Pacman = al_load_bitmap("Pac-Man Sprite.jpg");

	ptr_Player->ptr_Bitmap = I_Pacman;

	I_BlackSpace = al_load_bitmap("Black Screen.jpg");

	// si no inicio el timer printra un mesaje de error 
	if (!TimerMain) {
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
	al_register_event_source(EventoQueue, al_get_timer_event_source(TimerMain));
	al_register_event_source(EventoQueue, al_get_keyboard_event_source());

	ALLEGRO_EVENT OtroEvento;
	// para comenzar el timer 
	al_start_timer(TimerMain);
	// para cambiar el color de la pantalla 
	al_clear_to_color(al_map_rgb(0, 0, 0));

	ptr_Player->M_PosicionX = 0.0f;
	ptr_Player->M_PosicionY = 0.0f;

	// ayuda a controlar la animacion 
	ptr_Player->Frame = 0;
	// para saber que tan grande deberia ser pacman
	ptr_Player->getEscala(Ventana,AnchuraDeLaberinto,AlturaDeLaberinto);
	// para mantenerlo dentro de los confines del 
	// juego 
	ptr_Player->SetLimites(AnchuraDeLaberinto, AlturaDeLaberinto);

	ptr_Player->ptr_tablero = ptr_tablero;

	while (true)
	{
		al_wait_for_event(EventoQueue, &OtroEvento);

		// verifica si el clicamos a la 'x' de la parte derecha 
		//	superior de la ventan
		if (OtroEvento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (OtroEvento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			// para mover el pacman 
			if( OtroEvento.keyboard.keycode == ALLEGRO_KEY_W)
			{
				logger.info("Pac-Man moviendose para Norte");
				ptr_Player->setDirection(ptr_Player->Norte);
			}
			else if (OtroEvento.keyboard.keycode == ALLEGRO_KEY_S) {
				logger.info("Pac-Man moviendose para Sur");
				ptr_Player->setDirection(ptr_Player->Sur);
			}
			else if (OtroEvento.keyboard.keycode == ALLEGRO_KEY_A) {
				ptr_Player->setDirection(ptr_Player->Oeste);
			}
			else if (OtroEvento.keyboard.keycode == ALLEGRO_KEY_D) {
				ptr_Player->setDirection(ptr_Player->Este);
			}

			// para debugging
			else if(OtroEvento.keyboard.keycode == ALLEGRO_KEY_1)
			{
				logger.M_LogLevel = logger.M_LogError;
			}
			else if (OtroEvento.keyboard.keycode == ALLEGRO_KEY_2) {
				logger.M_LogLevel = logger.M_LogAvertencia;
			}
			else if (OtroEvento.keyboard.keycode == ALLEGRO_KEY_3) {
				logger.M_LogLevel = logger.M_LogInfo;
			}
		
		}
		//este evento es para que algo occura cada cierta 
		// cantidad de tiempo 
		else if (OtroEvento.type == ALLEGRO_EVENT_TIMER)
		{
			// para Dibujar El Laberiento del juego 
			DibujarLaberiento(I_Maze, I_BlackSpace, Ventana);

			ptr_Player->Move();
			ptr_Player->Draw();
			
			logger.Informar("Aqui estan la posiciones X, Y de Pacman",ptr_Player->M_MapCoordenadas.x, ptr_Player->M_MapCoordenadas.y);

			al_flip_display();
		}
	}


	delete ptr_Player;
	delete ptr_tablero;

	al_destroy_display(Ventana);
	al_destroy_bitmap(I_Maze);
	al_destroy_bitmap(I_BlackSpace);
	al_destroy_bitmap(I_Pacman);
	al_destroy_event_queue(EventoQueue);
	al_destroy_timer(TimerMain);
	al_uninstall_keyboard();
	return 0;
}


// quita las caracteres de ' ', en otras palabras
// espacio blank space.
std::string QuitarEspaciosEnBlanco(std::string &string)
{
	// sera el string que retornamos 
	std::string ReturnString;
	for (int i = 0; i < string.size(); ++i) {
		// solo quita la caracteres que 
		// no 
		if(string[i] != ' ')
		{
			ReturnString += string[i];
		}
	}
	return ReturnString;
}

void DefinirMaze() {
	// estas dos variable son para saber
	// las dimenciones de laberinto 
	AlturaDeLaberinto = 0;
	AnchuraDeLaberinto = 0;

	std::string temp;

	file.open("Laberinto.txt");

	int Iteracion = 0;
	// para asegurar que el laberieto 
	// por lo minimo ten solo un espacio libre 
//	ptr_tablero->Laberinto.resize(1);

	do
	{
		ptr_tablero->Laberinto.emplace_back();
		std::getline(file, temp);
		// consiguimos la anchura del laberiento 
		// la anchura De laberinto deberia ser 
		// consistente 
		if (Iteracion == 0)
		{
			AnchuraDeLaberinto = temp.size();
		}
		
		// quitar los espacio en blanco
		if (AnchuraDeLaberinto != temp.size()) {
			temp = QuitarEspaciosEnBlanco(temp);
		}

		ptr_tablero->Laberinto[Iteracion].resize(AnchuraDeLaberinto);

		for (int i = 0; i < temp.size(); ++i)
		{
			ptr_tablero->Laberinto[Iteracion][i] = temp[i];
		}
		// incrementa el tama�o del vector de vectores
		Iteracion++;

	} while (!(file.eof()));

	file.close();

	AlturaDeLaberinto = ptr_tablero->Laberinto.size();
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
			if (ptr_tablero->Laberinto[i][j] == '1')
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
			else if(ptr_tablero->Laberinto[i][j] == '0')
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

