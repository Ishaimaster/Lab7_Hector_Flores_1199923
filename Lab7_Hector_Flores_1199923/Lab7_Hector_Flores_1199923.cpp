#include "pch.h"
#include <fstream>
#include <iostream>
#include "Pokémon.h"
#include <list>
#include "Orden.h"
#include <random>
#include <algorithm>
#include <ctime>
#include <vector>


using namespace System;

PCdeBill MiPC;
Orden Sort;
std::list<Pokemon> Pokedex;


int main(array<System::String ^> ^args)
{
    //Funcion que lee los pokemons del archivo de texto
    MiPC.Lectura(Pokedex);
    
    bool menu = true;
    int opcion = 0;

    //Declara vectores que se barajean para el método QuickSort, en base a la lista de Pokemons
    std::vector<Pokemon> NuevoPokedex1;
    NuevoPokedex1.assign(Pokedex.begin(), Pokedex.end());
    Sort.Barajear(NuevoPokedex1);

    std::vector<Pokemon> NuevoPokedex2;
    NuevoPokedex2.assign(Pokedex.begin(), Pokedex.end());
    Sort.Barajear(NuevoPokedex2);

    while (menu)
    {


        Console::WriteLine("----------------Ordenamiento de la Pokedex----------------");
        Console::WriteLine("Segun que orden desea ordenar su pokedex?");
        Console::WriteLine("1. Por Generacion (o Nombre)");
        Console::WriteLine("2. Por Numero Regional");
        Console::WriteLine("3. Salir");
        Console::Write("Opcion: ");
            std::cin >> opcion;

        if (std::cin.fail() || (opcion < 1) || (opcion > 3))
        {
            std::cerr << "Opcion invalida. Por favor, ingrese un numero entre 1 y 3." << std::endl;
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            Console::ReadKey();
            Console::Clear();
            continue;
        }
       

        switch (opcion)
        {
            case 1:

                Sort.ImprimirPokedex(Sort.SelectionSortGen(Pokedex), Sort.ShellSortGen(Pokedex), Sort.QuickSortGen(NuevoPokedex1, NuevoPokedex1.size() - 1, 0));
                Console::ReadKey();
                Console::Clear();

            break;

            case 2:

                Sort.ImprimirPokedex2(Sort.SelectionSortReg(Pokedex), Sort.ShellSortReg(Pokedex), Sort.QuickSort(NuevoPokedex2, 0, NuevoPokedex2.size() - 1));
                Console::ReadKey();
                Console::Clear();

                break;


            case 3:

                menu = false;

                break;
        }



    }
    
    
    return 0;
}
    
