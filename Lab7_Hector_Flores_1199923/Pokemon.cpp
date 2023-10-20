#include "pch.h"
#include "Pokémon.h"
#include <string>

using namespace std;

void PCdeBill::Lectura(list <Pokemon> &Pokedex)
{
    string poke;
    int prueba = 0;
    ifstream file;
    Pokemon Digimon;

    //Abre el archivo en Modo de lectura
    file.open("Listado de Pokemons Flores.txt", std::ios::in);

    if (file.fail())
    {
        cout << "NO se pudo abrir el archivo";
        return;
    }

    while (getline(file, poke))
    {
        string texto = " ";
        int contador = 0;

        for(int i = 0; i < poke.length(); i++)
        {

            if(poke[i] == ',')
            {
                if (contador == 0)
                {
                   Digimon.NumPokedex = stoi(texto);
                    texto = " ";
                    contador++;
                        
                }
                else 
                {
                    Digimon.Nombre = texto;
                    texto = " ";
                   
                }
            }else
            {
                texto += poke[i];
            }
        }
       
        Digimon.Generacion = stoi(texto);

        Pokedex.push_back(Digimon);

        //Reset de la estructura y el contador
        contador = 0;

        prueba++;
       
    }

    file.close();


}




