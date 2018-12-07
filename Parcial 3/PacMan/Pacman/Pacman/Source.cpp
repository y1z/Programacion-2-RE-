// Pacman.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Entidad.h"
#include "LOG.h"
#include "Tablero.h"
#include "Pacman.h"
#include "Fantasma.h"
#include "Grafo.h"

// usare estos valore para consiguir la escala 
// de todos los demas objetos 
short AlturaDeLaberinto = 0;
short AnchuraDeLaberinto = 0;

float EscalaHorizontal;
float EscalaVertical;

static PacMan *ptr_Player = new PacMan;

Tablero *ptr_tablero = new Tablero;

Fantasma *ptr_Pinky = new Fantasma;

Fantasma *ptr_Inky = new Fantasma;

Fantasma *ptr_Binky = new Fantasma;

// para leer Archivos 
std::fstream file;
// para marcar errores o otra informacion del
// programa
LOG logger;

const float FPS = 60.0f;

void InicarFantasmas();

void DefinirMaze();

void DibujarLaberiento(ALLEGRO_BITMAP *Bitmap, ALLEGRO_BITMAP *BlackScreen, ALLEGRO_DISPLAY *Display);

std::string QuitarEspaciosEnBlanco(std::string &);

std::vector<Vertice> DFS(Grafo&,Vertice &PuntoEntrada ,Vertice &Destino);

std::vector<Vertice> BFS(Grafo&, Vertice &PuntoEntrada, Vertice &Destino);

int CalcularDiferencia(Vertice &Valor, const Vertice &Destino);

Vertice CalcularHeuristica(std::array<Vertice, 4> &Valores, const Vertice &Destino);

std::vector<Vertice> PrimeroMejor(Grafo&grafo, Vertice &PuntoEntrada, Vertice &Destino);

void GetEscala(ALLEGRO_DISPLAY *Display);

// esta funcion no es parte del programa 
// solo existe cuando debo probra al aprate del 
// Programa 
void Test();

void Stop() {
	std::cin.ignore();
	std::cin.get();
}

int main(int args, char** argv)
{
	logger.setLevel(logger.M_LogInfo);
	DefinirMaze();

	// para crear la Ventana 
	ALLEGRO_DISPLAY *Ventana = NULL;
	//para dibujar images 
	ALLEGRO_BITMAP *I_Maze = NULL;
	ALLEGRO_BITMAP *I_BlackSpace = NULL;
	ALLEGRO_BITMAP *I_Pacman = NULL;
	ALLEGRO_BITMAP *I_Sprite = NULL; 
	// para tener una lista de todos los 
	// eventos para el juego 
	ALLEGRO_EVENT_QUEUE	*EventoQueue = NULL;

	ALLEGRO_TIMER *TimerMain = NULL;

	if (al_init() == false) {
		fprintf(stderr, "Fracaso de iniciar allgro ");
		return -1;
	}


	// para tener acceso a los eventos 
	// de teclado
	if(!al_install_keyboard())
	{
		fprintf(stderr, "Fracaso de iniciar el teclado ");
		return -1;
	}

	if (!al_init_primitives_addon()) {
		fprintf(stderr, " Primitives Fracaso al Iniciar ");
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

	I_Sprite = al_load_bitmap("Pac-Man Sprite.jpg");


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

	if (!I_Sprite) {
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

	//----------//

	//ptr_Pinky->ptr_tablero = ptr_tablero;
	// para mantenerlo dentro de los confines del 
	// juego 
	// Los Datos para Pinky
	ptr_Pinky->getEscala(Ventana, AnchuraDeLaberinto, AlturaDeLaberinto);

	ptr_Pinky->MetodosBusqueda = DFS;

	ptr_Pinky->ptr_Bitmap = I_Sprite;
	// Los Datos Para Inky 
	ptr_Inky->getEscala(Ventana, AnchuraDeLaberinto, AlturaDeLaberinto);

	ptr_Inky->MetodosBusqueda = BFS;

	ptr_Inky->ptr_Bitmap = I_Sprite;

	// Los Datos para Binky 
	ptr_Binky->getEscala(Ventana, AnchuraDeLaberinto, AlturaDeLaberinto);

	ptr_Binky->ptr_Bitmap = I_Sprite;

	ptr_Binky->MetodosBusqueda = PrimeroMejor;


	Grafo grafo;
	grafo.GeneralGrafo(ptr_tablero->Laberinto);

	GetEscala(Ventana);


	InicarFantasmas();

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
			
			//	logger.Informar("Aqui estan la posiciones X, Y de Pacman",ptr_Player->M_MapCoordenadas.x, ptr_Player->M_MapCoordenadas.y);

			Vertice PosPacMan(ptr_Player->M_MapCoordenadas.x, ptr_Player->M_MapCoordenadas.y);

			ptr_Pinky->Conportamiento(grafo, PosPacMan);
			ptr_Binky->Conportamiento(grafo, PosPacMan);
			ptr_Inky->Conportamiento(grafo, PosPacMan);
			//PrimeroMejor(grafo, tempVert1, PosPacMan);

			al_flip_display();
		}
	}


	delete ptr_Player;
	delete ptr_Pinky;
	delete ptr_Inky;
	delete ptr_Binky;
	delete ptr_tablero;

	al_destroy_display(Ventana);
	al_destroy_bitmap(I_Maze);
	al_destroy_bitmap(I_BlackSpace);
	al_destroy_bitmap(I_Pacman);
	al_destroy_bitmap(I_Sprite);
	al_destroy_event_queue(EventoQueue);
	al_destroy_timer(TimerMain);
	al_uninstall_keyboard();
	return 0;
}

void InicarFantasmas()
{

	for (size_t i = 0; i < ptr_tablero->Laberinto.size(); i++)
	{
		for (size_t j = 0; j < ptr_tablero->Laberinto[i].size(); j++)
		{

			if (ptr_tablero->Laberinto[i][j] == 'p') {
				ptr_Pinky->IniciarFantasma('p',j, i);
			}
			else if (ptr_tablero->Laberinto[i][j] == 'b') {
				ptr_Binky->IniciarFantasma('b', j, i);
			}
			else if (ptr_tablero->Laberinto[i][j] == 'i') {
				ptr_Inky->IniciarFantasma('i', j, i);
			}

		}

	}


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
		// incrementa el tamaño del vector de vectores
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
			 if(ptr_tablero->Laberinto[i][j] != '1')
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

// quita las caracteres de ' ', en otras palabras
// espacio en blanco.
std::string QuitarEspaciosEnBlanco(std::string &string)
{
	// sera el string que retornamos 
	std::string ReturnString;
	for (int i = 0; i < string.size(); ++i) {
		// solo quita la caracteres que 
		// no deseamos para el laberiento 
		if (string[i] != ' ')
		{
			ReturnString += string[i];
		}
	}
	return ReturnString;
}


std::vector<Vertice> DFS(Grafo &grafo,Vertice &PuntoEntrada, Vertice &Destino) {

	// Estos dos vectores contiene la posicion actual (first) y 
	// de donde viene (second)

	// a donde podemos ir
	std::vector<std::pair<Vertice,Vertice>> Abiertos;
	// donde estabamos antes
	std::vector<std::pair<Vertice, Vertice>> Cerrados;

	// para saber en donde estamos 
	Vertice PosicionActual;
	// para saber de donde venimos 
	Vertice PosicionPrevia;

	std::vector<Vertice> ReturnVector;
	
	// hacemos la pregunta : ? los vertices que me 
	// provee realmente exiten dentro del grafo?
	bool EsPuntoEntradaValido = false;
	bool EsDestinoValido = false;

	/* hacemos la pregunta : 
	? Encontramos el la posicion que nos pide el usario ?*/
	bool EsTerminado = false;

	bool EsPrimeraIteracion = true;

	int Returno = 0;

	// revisamos si existen las coordenadas dentro de 
	// nuestro grafo.
	for(Vertice vert : grafo.M_Vertices)
	{
		if (vert == PuntoEntrada) {
			EsPuntoEntradaValido = true;
		}
	    if (vert == Destino) {
			EsDestinoValido = true;
		}
	}

	Abiertos.resize(1);

	
	if (EsDestinoValido && EsPuntoEntradaValido) {
		// iniciamos tomando el punto de Entrada 
		// como posicion inicial 
		Abiertos[0].first = PuntoEntrada;
		Abiertos[0].second = PuntoEntrada;
		PosicionActual = PuntoEntrada;

		while (!EsTerminado)
		{
			// revisar si terminamos 
			(PosicionActual == Destino) ? EsTerminado = true : 0;

			if (PosicionActual == Destino) {
				EsTerminado = true;
				break;
			}

			// Un vertice solo puede tener 4 arista maximo (en nuestro grafo) 
			std::array<Arista, 4> AristaPosiciones;
			/* Hacemos la pregunta 
			? deberia usar esta arista ? */
			std::array<bool, 4> AristaValidos;
			// primero todo son falsos
			AristaValidos.fill(false);

			// Buscamos las adyaciencias de nuestra posicion 
			int tempIterador = 0;
			for (int i = 0; i < grafo.M_Vertices.size(); ++i)
			{
			
				if (grafo.EsAdyaciente(PosicionActual, grafo.M_Vertices[i]))
				{
					bool EsDuplica = false;
					/* Esta Copia exite dado que sin ella
					El Vertice Original 'Posicion' se modifica
					por alguna razon.
					*/
					Vertice Copia = grafo.M_Vertices[i];
					// este 'if' exite para que no tengan aristas 
					// duplicados 

					for (Arista arista : AristaPosiciones)
					{
						if (arista.Comparar(arista.ptr_Vert2 , grafo.M_Vertices[i]))
						{
							EsDuplica = true;
						}
					}

					// hacemos la siguentes operciones cuando 
					// NO tenemos una arista duplicada
					if (!EsDuplica)
					{
						AristaPosiciones[tempIterador].setVertices(PosicionActual, grafo.M_Vertices[i]);
						AristaValidos[tempIterador] = true;
						tempIterador++;
					}
				}
			}

			// revisar Cada vertice para ver si uno valido,
			// en otra palabras si lo aviamos visitado antes 
			for (int i = 0; i < AristaPosiciones.size() - 1; ++i)
			{
				for (auto pair : Cerrados) {

					if (AristaPosiciones[i].Comparar(AristaPosiciones[i].ptr_Vert2, pair.first))
					{
						AristaValidos[i] = false;
					}
				}
			}

			for (int i = 0; i < Abiertos.size() - 1; ++i)
			{
				for (int j = AristaPosiciones.size() - 1; j >= 0; j--)
				{
					if(AristaPosiciones[j].Comparar(AristaPosiciones[j].ptr_Vert2,Abiertos[i].second))
					{
						AristaValidos[j] = false;
					}
				}
			}

			for (int i = 0; i < AristaValidos.size(); ++i)
			{
			
				if (AristaValidos[i] == true)
				{
					Vertice Origen = *AristaPosiciones[i].ptr_Vert1;
					Vertice Vecino = *AristaPosiciones[i].ptr_Vert2;

					Abiertos.emplace_back(std::make_pair(Origen, Vecino));
				}	
			}

			if(EsPrimeraIteracion)
			{
				Cerrados.emplace_back(std::make_pair(PosicionActual, PosicionActual));
				PosicionPrevia = PosicionActual;
				PosicionActual = Abiertos[Abiertos.size() - 1].second;
				Abiertos.erase(Abiertos.begin() + 0);

				EsPrimeraIteracion = false;
			}
			else {

				/*Esto es para saber si llege al final
				del camino actual */
				bool EsFinCamino = true;


				for (bool Valido : AristaValidos)
				{
					(Valido == true) ? EsFinCamino = false
						: 0;
				}

				if(!EsFinCamino){
					// Antes de cambiar nuestra posicion previa
					// debemos dicer que es igual a la PosicionActual 
					PosicionPrevia = PosicionActual;
					// tomamos el ultimo valor de abiertos y 
					// lo tomamos como posicion actual 
					PosicionActual = Abiertos[Abiertos.size() - 1].second;
				}
				else {
					PosicionPrevia = Abiertos[Abiertos.size() - 1].first;
					PosicionActual = Abiertos[Abiertos.size() - 1].second;
				}

					for (int i = 0; i < Abiertos.size(); i++)
					{
						// trasfiero Posicion actual a cerrados
						if (PosicionPrevia == Abiertos[i].first && PosicionActual == Abiertos[i].second)
						{
							Abiertos.erase(Abiertos.begin() + i);
							Returno = Abiertos.size() - 1;
							break;
						}
					}
					Cerrados.emplace_back(PosicionPrevia, PosicionActual);
				
			}
		}
	}
	if (EsTerminado) {

		for( int i = 0 ; i < Cerrados.size(); ++i)
		{
			al_draw_line(Cerrados[i].second.M_x * EscalaHorizontal
				, Cerrados[i].first.M_y * EscalaVertical
				, Cerrados[i].first.M_x * EscalaHorizontal
				, Cerrados[i].second.M_y * EscalaVertical
				, al_map_rgb(255, 255, 255)
				, EscalaVertical / AlturaDeLaberinto
			);
		}

		for (auto vert : Cerrados) {
			ReturnVector.emplace_back(vert.first);
			ReturnVector.emplace_back(vert.second);
		}
	}
	else {
		fprintf(stderr, "La Posicion es Ivalida ");
	}

	return ReturnVector;
}


std::vector<Vertice> BFS(Grafo &grafo, Vertice &PuntoEntrada, Vertice &Destino) {
	// Estos dos vectores contiene la posicion actual (first) y 
	// de donde viene (second)

	// a donde podemos ir
	std::vector<std::pair<Vertice, Vertice>> Abiertos;
	// donde estabamos antes
	std::vector<std::pair<Vertice, Vertice>> Cerrados;

	// para saber en donde estamos 
	Vertice PosicionActual;
	// para saber de donde venimos 
	Vertice PosicionPrevia;

	std::vector<Vertice> ReturnVector;
	// hacemos la pregunta : ? los vertices que me 
	// provee realmente exiten dentro del grafo?
	bool EsPuntoEntradaValido = false;
	bool EsDestinoValido = false;

	/* hacemos la pregunta :
	? Encontramos el la posicion que nos pide el usario ?*/
	bool EsTerminado = false;

	bool EsPrimeraIteracion = true;

	// revisamos si existen las coordenadas dentro de 
	// nuestro grafo.
	for (Vertice vert : grafo.M_Vertices)
	{
		if (vert == PuntoEntrada) {
			EsPuntoEntradaValido = true;
		
		}
		if (vert == Destino) {
			EsDestinoValido = true;
		}
	}

	Abiertos.resize(1);

	if (EsDestinoValido && EsPuntoEntradaValido) {
		// iniciamos tomando el punto de Entrada 
		// como posicion inicial 
		Abiertos[0].first = PuntoEntrada;
		Abiertos[0].second = PuntoEntrada;
		PosicionActual = PuntoEntrada;

		while (!EsTerminado)
		{
			// revisar si terminamos 
			(PosicionActual == Destino) ? EsTerminado = true : 0;

			if (PosicionActual == Destino) {
				EsTerminado = true;
				break;
			}

			// Un vertice solo puede tener 4 arista maximo (en nuestro grafo) 
			std::array<Arista, 4> AristaPosiciones;
			/* Hacemos la pregunta
			? deberia usar esta arista ? */
			std::array<bool, 4> AristaValidos;
			// primero todo son falsos
			AristaValidos.fill(false);

			// Buscamos las adyaciencias de nuestra posicion 
			int tempIterador = 0;
			for (int i = 0; i < grafo.M_Vertices.size(); ++i)
			{

				if (grafo.EsAdyaciente(PosicionActual, grafo.M_Vertices[i]))
				{
					bool EsDuplica = false;
					/* Esta Copia exite dado que sin ella
					El Vertice Original 'Posicion' se modifica
					por alguna razon.
					*/
					Vertice Copia = grafo.M_Vertices[i];
					// este 'if' exite para que no tengan aristas 
					// duplicados 

					for (Arista arista : AristaPosiciones)
					{
						if (arista.Comparar(arista.ptr_Vert2, grafo.M_Vertices[i]))
						{
							EsDuplica = true;
						}
					}

					// hacemos la siguentes operciones cuando 
					// NO tenemos una arista duplicada
					if (!EsDuplica)
					{
						AristaPosiciones[tempIterador].setVertices(PosicionActual, grafo.M_Vertices[i]);
						AristaValidos[tempIterador] = true;
						tempIterador++;
					}
				}
			}

			// revisar Cada vertice para ver si uno valido,
			// en otra palabras si lo aviamos visitado antes 
			for (int i = 0; i < AristaPosiciones.size() - 1; ++i)
			{
				for (auto pair : Cerrados) {

					if (AristaPosiciones[i].Comparar(AristaPosiciones[i].ptr_Vert2, pair.first))
					{
						AristaValidos[i] = false;
					}
				}
			}

			for (int i = 0; i < Abiertos.size() - 1; ++i)
			{
				for (int j = AristaPosiciones.size() - 1; j >= 0; j--)
				{
					if (AristaPosiciones[j].Comparar(AristaPosiciones[j].ptr_Vert2, Abiertos[i].second))
					{
						AristaValidos[j] = false;
					}
				}
			}

			for (int i = 0; i < AristaValidos.size(); ++i)
			{

				if (AristaValidos[i] == true)
				{
					Vertice Origen = *AristaPosiciones[i].ptr_Vert1;
					Vertice Vecino = *AristaPosiciones[i].ptr_Vert2;

					Abiertos.emplace_back(std::make_pair(Origen, Vecino));
				}
			}

			if (EsPrimeraIteracion)
			{
				Cerrados.emplace_back(std::make_pair(PosicionActual, PosicionActual));
				PosicionPrevia = PosicionActual;
				PosicionActual = Abiertos[Abiertos.size() - 1].second;
				Abiertos.erase(Abiertos.begin() + 0);

				EsPrimeraIteracion = false;
			}
			else {

				// Antes de cambiar nuestra posicion previa
				// debemos dicer que es igual a la PosicionActual 
				PosicionPrevia = Abiertos[0].first;
				// tomamos el ultimo valor de abiertos y 
				// lo tomamos como posicion actual 
				PosicionActual = Abiertos[0].second;
				

				for (int i = 0; i < Abiertos.size(); i++)
				{
					// trasfiero Posicion actual a cerrados
					if (PosicionPrevia == Abiertos[i].first && PosicionActual == Abiertos[i].second)
					{
						Abiertos.erase(Abiertos.begin() + i);
						break;
					}
				}

				Cerrados.emplace_back(PosicionPrevia, PosicionActual);

			}
		}
	}
	if (EsTerminado) {

		for (int i = 0; i < Cerrados.size(); ++i)
		{
			al_draw_line(Cerrados[i].first.M_x * EscalaHorizontal
				, Cerrados[i].first.M_y * EscalaVertical
				, Cerrados[i].second.M_x * EscalaHorizontal
				, Cerrados[i].second.M_y * EscalaVertical
				, al_map_rgb(20, 20, 255)
				, EscalaVertical / AlturaDeLaberinto
			);
		}
		al_flip_display();
	}
	else {
		fprintf(stderr, "La Posicion es Ivalida ");
	}

	for (auto vert : Cerrados) {
		ReturnVector.emplace_back(vert.first);
		ReturnVector.emplace_back(vert.second);
	}

	return ReturnVector;
}

/* El Valor Menor es el valor con que esta mas cerca */
int CalcularDiferencia(Vertice &Valor, const Vertice &Destino)
{	
	int resultado = 0;

	// para saber la distancia entre el Vertice 
	// y su Nuestro Destino en el eje X 
	int Mayor = std::max(Valor.M_x, Destino.M_x);
	int Menor = std::min(Valor.M_x, Destino.M_x);

	resultado += (Mayor - Menor);

	// para saber la distancia entre el Vertice 
	// y su Nuestro Destino en el eje Y
	 Mayor = std::max(Valor.M_y, Destino.M_y);
	 Menor = std::min(Valor.M_y, Destino.M_y);

	resultado += (Mayor - Menor);

	return resultado;
}

/* calculamos la distancia entre los */
Vertice CalcularHeuristica(std::array<Vertice, 4> &Candidatos, const Vertice &Destino)
{
	
	// determinara que Vertice voy a tomar 
	std::array<int, 4 > ValoresHeuriticos;
	// busco el vertice con el Heuritico mas bajo 
	// por lo tanto relleno todo los demas valores grandes 
	// para luego cambiarlos 
	ValoresHeuriticos.fill(999999999);

	int ValorDeComparacion = ValoresHeuriticos[0];

	auto HueriticoItr = ValoresHeuriticos.begin();

	for(Vertice Vert : Candidatos)
	{
		*HueriticoItr = CalcularDiferencia(Vert, Destino);
		HueriticoItr++;
	}

	int LugarDeValorMenor = 0;

	for (size_t i = 0; i < ValoresHeuriticos.size(); i++)
	{
		if(ValoresHeuriticos[i] < ValorDeComparacion)
		{
			ValorDeComparacion = ValoresHeuriticos[i];
			LugarDeValorMenor = i;
		}
	}

	return Candidatos[LugarDeValorMenor];
}

std::vector<Vertice> PrimeroMejor(Grafo&grafo, Vertice &PuntoEntrada, Vertice &Destino) {

	/*Primero vemos si lo lugares que vamos a buscar 
	 Existen */
	bool EsPuntoEntradaValido = false;
	bool EsDestinoValido = false;

	// para saber en donde estamos actualmente 
	Vertice PosicionActual;

	// para saber los lugares que ya vistamos 
	std::vector<Vertice> Camino;
	// lugares donde exiten varias opciones para donde
	// moverse para luego regresa a esta ubicaciones 
	std::vector<std::pair<Vertice,char>> Interseccion;

	for(Vertice vert : grafo.M_Vertices)
	{
		// vemos si PuntoEntrada es valido 
		(vert == PuntoEntrada) ? EsPuntoEntradaValido = true
			: 0;
		// vemos si el destino es valido 
		(vert == Destino) ? EsDestinoValido = true 
			: 0;
		
		if(EsPuntoEntradaValido && EsDestinoValido)
		{
			break;
		}
	}

	// iniciar la busqueda 
	if(EsPuntoEntradaValido && EsDestinoValido)
	{
		bool EsTerminado = false;
		PosicionActual = PuntoEntrada;
		Camino.emplace_back(PosicionActual);

		(PosicionActual == Destino) ? EsTerminado = true : 0;

		while(!EsTerminado)
		{
			// crearmos una arreglo de todas la posibles candidatos 
			std::array<Vertice, 4> PosicionesPosibles;

			char CountPosiciones = 0;

			for(int i = 0; i < PosicionesPosibles.size(); i++)
			{
				PosicionesPosibles[i].M_x = -1000;
				PosicionesPosibles[i].M_y = -1000;
			}

			auto PosicionesItr = PosicionesPosibles.begin();
				
			for (Vertice verticeAdyacientes : grafo.M_Vertices) {
				// para ver si extiten vertices Adyacientes 
				// a nuestra Posicion.

				// 4 es el valor maximo de adyaciencias que permite nuestro grafo 
				// por lo tanto no exite necesidad de continuar buscando adyaciencias 
				if (CountPosiciones == 4)
					break;
				

				if (grafo.EsAdyaciente(PosicionActual, verticeAdyacientes))
				{
					/*hacemos la pregunta 
					? ya pase por este vertice antes ? */
					bool EsDuplica = false;
					// para no atarvera el mismo camino 2 veces 
					for(Vertice vertices : PosicionesPosibles )
					{
						( PosicionActual == vertices)
							? EsDuplica = true : 0;
					}
					// para no atravezar el mismo camino 2 veces 
					for (Vertice verticesCamino : Camino) {
						(verticesCamino == verticeAdyacientes)
							? EsDuplica = true : 0;
					}

					if(!EsDuplica)
					{
						*PosicionesItr = verticeAdyacientes;
						PosicionesItr++;
						CountPosiciones++;
					}
					
					if (verticeAdyacientes.M_y == PosicionActual.M_y + 1)
						break;
				}
			}
			if(CountPosiciones > 1)
			{
				Interseccion.emplace_back(std::make_pair(PosicionActual, CountPosiciones));
			}

			if (CountPosiciones == 0) {

				if (Interseccion[0].second != 0) 
				{
					Camino.emplace_back(PosicionActual);
					PosicionActual = Interseccion[0].first;
					Interseccion[0].second--;
				}
				else
				{
					Interseccion.erase(Interseccion.begin() + 0);
					PosicionActual = Interseccion[0].first;
					Interseccion[0].second--;
				}
			
			}
			else {
				// buscamos la posicion adyaciente que este mas cercano
				// al Destino
				PosicionActual = CalcularHeuristica(PosicionesPosibles, Destino);

				Camino.emplace_back(PosicionActual);

				(PosicionActual == Destino) ? EsTerminado = true : 0;
			}
		}
		if (EsTerminado) {
			if (Camino.size() > 1) 
			{
				for (int j = 1; j < Camino.size(); ++j)
				{
					al_draw_line(Camino[j - 1 ].M_x * EscalaHorizontal
						, Camino[j - 1 ].M_y * EscalaVertical
						, Camino[j].M_x * EscalaHorizontal
						, Camino[j].M_y * EscalaVertical
						, al_map_rgb(100 + j, 255, 255)
						, EscalaVertical / AlturaDeLaberinto
					);
				}
			}

		}
	
	}

	return Camino;
}

void Test()
{
	/*Arista temp;

	Vertice ver1(2, 2);
	Vertice ver2(6, 6);

	temp.ptr_Vert1 = &ver1;
	temp.ptr_Vert2 = &ver2;

	std::array<Arista, 4> Adyaciencias;
	std::array<Arista, 4>::iterator Iterador;
	Iterador = Adyaciencias.begin();

	for (char i = 0; i < 2; i++)
	{
		*Iterador = temp;
		Iterador++;
	}*/

	Stop();
}


void GetEscala(ALLEGRO_DISPLAY *Display) 
{
	int anchura = al_get_display_width(Display);
	int altura = al_get_display_height(Display);

	EscalaHorizontal = 1;
	EscalaVertical = 1;

	EscalaVertical = altura/AlturaDeLaberinto ;
	EscalaHorizontal = anchura/AnchuraDeLaberinto ;
}