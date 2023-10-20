#pragma once
#include <list>
#include "Pokémon.h"
#include <vector>
#include "StopWatch.h"

 class Orden
{
	 StopWatch Tiempo;

	 double tiempo1 = 0;
	 double tiempo2 = 0;
	 double tiempo3 = 0;
	 double tiempo4 = 0;
	 double tiempo5 = 0;
	 double tiempo6 = 0;

	public:

		std::list<Pokemon> SelectionSortGen(std::list<Pokemon> ABC);
		std::list<Pokemon> SelectionSortReg(std::list<Pokemon> ABC);
		std::list<Pokemon> ShellSortGen(std::list<Pokemon> ABC);
		std::list<Pokemon> ShellSortReg(std::list<Pokemon> CBA);
		std::vector<Pokemon> QuickSortGen(std::vector<Pokemon> &Pokedex, int high, int low);
		std::vector<Pokemon> QuickSort(std::vector<Pokemon>& Pokedex, int low, int high);
		int PartitionReg(std::vector<Pokemon>& Pokedex, int low, int high);
		void ImprimirPokedex(std::list<Pokemon> lista1, std::list<Pokemon> lista2, std::vector<Pokemon> lista3);
		void ImprimirPokedex2(std::list<Pokemon> lista1, std::list<Pokemon> lista2, std::vector<Pokemon> lista3);
		int Partition(std::vector<Pokemon>& Pokedex, int high, int low);
		void Swap(Pokemon* Pokemon1, Pokemon* Pokemon2);
		std::vector<Pokemon> Barajear(std::vector<Pokemon> &Pokemon);

};

