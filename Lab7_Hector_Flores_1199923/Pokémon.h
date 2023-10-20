#pragma once
#include <fstream>
#include <iostream>
#include <list>

struct Pokemon
{
	int NumPokedex;
	int Generacion;
	std::string Nombre;

};

 class PCdeBill
{


	public:


		void Lectura(std::list<Pokemon> &Pokedex);
};

