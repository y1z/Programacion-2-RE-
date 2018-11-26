#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo()
{
}


Grafo::~Grafo()
{
}

void Grafo::GeneralGrafo(std::vector<std::vector<char>>& OtherMapa)
{
	/* Creado todos los vertices necesario para el grafo */
	for (int i = 0; i < OtherMapa.size(); i++)
	{
		for (int j = 0; j < OtherMapa[i].size(); j++)
		{
			if(OtherMapa[i][j] == '0')
			{
				M_Vertices.emplace_back(Vertice(j, i));
			}
		}
	}

	/* Connectar los Vertices por medio de los aristas */
	EnlasarGrafo();
}

void Grafo::EnlasarGrafo()
{
	// para enlasar los vertices 
	for (int i = 0; i < this->M_Vertices.size(); i++)
	{
		// para revisar que vertices pueden ser 
		// enlasados 
		for (int j = 0; j < this->M_Vertices.size(); j++)
		{
			// para que no se pueda tener un vertice 
			// enlasado con si mismo 
			if (j != i)
			{
				// queremos asegurar que no exita arista que son 
				// copias de otros aristas 
				if(!(EsConnecionExistente(M_Vertices[i],M_Vertices[j])))
				{
					// revisar ei se pueden enlasar 
					if (EsAdyaciente(M_Vertices[i], M_Vertices[j]))
					{
						M_Aristas.emplace_back(Arista(M_Vertices[i], M_Vertices[j]));
					}
				}
			}
		}
	}

}


bool Grafo::EsAdyaciente(Vertice& Orignal, Vertice& Compara) {
	
	// verifica si lo vertices estan ensiguida uno del otro 
	// en el eje X 
	if(Orignal.M_y == Compara.M_y && (Compara.M_x == Orignal.M_x - 1 || Compara.M_x == Orignal.M_x + 1))
	{
		return true;
	}
	// verifica si lo vertices estan ensiguida uno del otro 
	// en el eje X 
	else if (Orignal.M_x == Compara.M_x && (Compara.M_y == Orignal.M_y - 1 || Compara.M_y == Orignal.M_y + 1))
	{
		return true;
	}

	return false;
}

bool Grafo::EsConnecionExistente(Vertice& Orignal, Vertice& Compara)
{
	// verifica si los dos vertice ya estaban connectados 
	for(Arista arista : M_Aristas)
	{
		if (arista.ptr_Vert1 == &Orignal && arista.ptr_Vert2 == &Compara)
		{
			return true;
		}
		else if(arista.ptr_Vert2 == & Orignal && arista.ptr_Vert1 == &Compara)
		{
			return true;
		}
	}
	
	return false;
}