#include "pch.h"
#include "Orden.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

list <Pokemon> Orden::SelectionSortGen(std::list<Pokemon> Pokedex)
{
	//Genera una semilla para los numeros aleatorios
	random_device rd;
	mt19937 g(rd());

	//Declaracion del vector que será ordenado
	vector<Pokemon> NewPokedex;

	//Se llena el vector con los elementos de la lista
	while(!Pokedex.empty())
	{
		NewPokedex.push_back(Pokedex.front());
		Pokedex.pop_front();
	}

	//Se inicia el contador
	Tiempo.Start();

	//Se obtiene el tamaño de la lista
	int n = NewPokedex.size();

	//Se barajea el vector
	shuffle(NewPokedex.begin(), NewPokedex.end(), g);


	//Selection Sort
	//Declara un iterador que va a recorrer todo la lista
	for(int i = 0; i < n - 1; i++)
	{
		//Declara como indice del elemento menor la posicion 0
		int minimo = i;

		//Declara un iterador que recorre la lista una posicion después de la posicion i
		for(int k = i + 1; k < n; k++)
		{
			//Verifica si la generacion del Pokemon en el indice k es menor que el primer elemento
			if(NewPokedex[k].Generacion < NewPokedex[minimo].Generacion)
			{
				//Si se cumple la condicion, el indice del elemento minimo pasa a ser la posicion "k"
				minimo = k;
			
				//Verifica que si las generaciones de los pokemones son iguales
			}else if(NewPokedex[k].Generacion == NewPokedex[minimo].Generacion)
			{
				//Verifica que el nombre del Pokemon del segundo iterador sea menor alfabéticamente que el nombre del Pokemon de la posicion
				//de partida
				if(NewPokedex[k].Nombre  < NewPokedex[minimo].Nombre)
				{
					//Si se cumple la condicion, el indice del elemento minimo pasa a ser la posicion "k"
					minimo = k;
				
				}
			}
		}

		//Se guarda en una variable temporal, el pokemon que esta en el indice minimo
		Pokemon Temporal = NewPokedex[minimo];

		//Se intercambia el Pokemon que esta en el indice minimo y se coloca al principio de la lista
		NewPokedex[minimo] = NewPokedex[i];

		//Se intercambia el Pokemon que estaba al principio de la lista, y se coloca en la posicion del indice minimo
		NewPokedex[i] = Temporal;
	
	}

	//Para el contador
	Tiempo.Stop();

	//Se traslada el vector a la lista nuevamente
	while(!NewPokedex.empty())
	{
		Pokedex.push_front(NewPokedex.back());
		NewPokedex.pop_back();
	
	}

	tiempo1 = Tiempo.ElapsedMilliseconds();

	return Pokedex;

}

list <Pokemon> Orden::SelectionSortReg(std::list<Pokemon> Pokedex)
{
	//Realiza lo mismo que la funcion anterior
	random_device rd;
	mt19937 p(rd());

	vector<Pokemon> SortRegional;

	while(!Pokedex.empty())
	{
		SortRegional.push_back(Pokedex.front());
		Pokedex.pop_front();
	
	}

	Tiempo.Start();

	shuffle(SortRegional.begin(), SortRegional.end(), p);

	int n = SortRegional.size();


	for(int t = 0; t < n - 1; t++)
	{
		int indexmin = t;
	
		for(int r = t + 1; r < n; r++)
		{
			//La diferencia es la condicion, ya que se compara el numero regional
			if(SortRegional[r].NumPokedex < SortRegional[indexmin].NumPokedex)
			{
				indexmin = r;
			
			}
		
		}

		Pokemon Tempo = SortRegional[indexmin];

		SortRegional[indexmin] = SortRegional[t];

		SortRegional[t] = Tempo;
	
	}

	Tiempo.Stop();

	while(!SortRegional.empty())
	{
		Pokedex.push_front(SortRegional.back());
		SortRegional.pop_back();
	}

	tiempo2 = Tiempo.ElapsedMilliseconds();

	return Pokedex;

}

list<Pokemon> Orden::ShellSortGen(std::list<Pokemon> Pokedex)
{
	random_device rd;
	mt19937 l(rd());

	vector<Pokemon> ShellSortG;

	while(!Pokedex.empty())
	{
		ShellSortG.push_back(Pokedex.front());
		Pokedex.pop_front();
	}

	Tiempo.Start();

	int n = ShellSortG.size();

	shuffle(ShellSortG.begin(), ShellSortG.end(), l);

	
	//Crea un "gap" grande entre la serie de elementos, que luego se va reduciendo
	for(int gap = n/2; gap > 0; gap /= 2)
	{
		// Con la lista formada a partir del gap empieza a ordenar la lista "gapeada"
		for(int i = gap; i < n; i++)
		{
		
			//Guarda como variable temporal la posicion donde se encuentra el origen
			Pokemon Temporal = ShellSortG[i];
	
			//Declaracion de variables para las iteraciones
			int k;

			//Bucle for que coloca un indice en la posicion de origen, y valida que "k" no sea menor que gap para no salir del rango de la lista
			//Ademas, valida que en la posicion del gap, el pokemon sea de mayor generacion que el del origen del gap, y le resta a la iterador el valor del gap
			for(k = i; k >= gap && ShellSortG[k - gap].Generacion >= Temporal.Generacion; k -= gap)
			{
				if(ShellSortG[k - gap].Nombre > Temporal.Nombre)
				{
					//Si se cumple el for, reemplaza la posicion de origen del gap, por el elemento que esta en la posicion del gap
					ShellSortG[k] = ShellSortG[k - gap];

				}else if(ShellSortG[k - gap].Generacion >Temporal.Generacion)
				{
				
					ShellSortG[k] = ShellSortG[k - gap];

				
				}else
				{
					break;
				}

			}
			
			//Luego, al disminuir K, se obtiene el indice del salto, por lo que se intercambia el elemento por el elemento que estaba en el origen del gap, terminando el intercambio.
			ShellSortG[k] = Temporal;


		
		}
	
	
	}

	Tiempo.Stop();

	while(!ShellSortG.empty())
	{
		Pokedex.push_front(ShellSortG.back());
		ShellSortG.pop_back();
	
	}

	tiempo3 = Tiempo.ElapsedMilliseconds();

	return Pokedex;

}

list<Pokemon> Orden::ShellSortReg(std::list<Pokemon> CBA)
{
	random_device rd;
	mt19937 s(rd());

	vector<Pokemon> ShellSortR;

	while(!CBA.empty())
	{
		ShellSortR.push_back(CBA.front());
		CBA.pop_front();
	
	}

	Tiempo.Start();

	int n = ShellSortR.size();
	
	shuffle(ShellSortR.begin(), ShellSortR.end(),s);

	for(int gap = n/2; gap > 0; gap /= 2)
	{

		for(int i = gap; i < n; i++)
		{
			
			Pokemon Tempo = ShellSortR[i];
		

			int j;

			for(j = i; j >= gap && ShellSortR[j - gap].NumPokedex > Tempo.NumPokedex; j -= gap)
			{
			
				ShellSortR[j] = ShellSortR[j - gap];
			
			}
			
			ShellSortR[j] = Tempo;

		
		}
	}

	Tiempo.Stop();

	while(!ShellSortR.empty())
	{
		CBA.push_front(ShellSortR.back());
		ShellSortR.pop_back();
	}

	tiempo4 = Tiempo.ElapsedMilliseconds();


	return CBA;

}

vector<Pokemon> Orden::QuickSortGen(vector<Pokemon> &Pokedex, int high, int low)
{
	Tiempo.Start();

	//Se comprueba que el primer indice de la lista no sea igual al ultimo indice, lo que significaria que ya se termino de ordenar el vector.
	if (low < high)
	{
		//Se realiza una particion del vector, teniendo como elemento de comparacion un "Pivote", del cual se compararan los demas elementos
		//ordenandolos a la izquierda los menores y a la derecha los mayores
		int parti = Partition(Pokedex, high, low);


		//Crea subdivisiones del vector que parten de la posicion del "Pivote" hacia al principio o hacia al final del vector
		QuickSortGen(Pokedex, parti - 1, low);

		QuickSortGen(Pokedex, high, parti + 1);

	}
	
	Tiempo.Stop();

	tiempo5 = Tiempo.ElapsedMilliseconds();

	return Pokedex;
}




int Orden::Partition(std::vector<Pokemon>& Pokedex, int high, int low)
{
	//Se declara como parametro de comparacion o "Pivote" el elemento que esta en la ultima posicion del vector
	Pokemon Pivote = Pokedex[high];

	//Se declara un iterador que estará detras del iterador principal
	int i = -1;

	//Se declara un bucle que recorrera el vector desde el principio hasta el Pivote
	for(int j = 0; j < high; j++ )
	{
		//Se verifica que la generacion del Pokemon en la posicion "j" sea menor que el Pivote
		if(Pokedex[j].Generacion < Pivote.Generacion)
		{
			//Si lo es, le suma +1 al iterador "i"

			i++;
			
			//Y cambia el Pokemon en la posicion "j" y lo coloca en la posicion "i", y viceversa
			Swap(&Pokedex[i], &Pokedex[j]);
		
			//Si las generaciones son iguales,se verifica si el nombre esta en orden alfabetico
		}else if(Pokedex[j].Generacion == Pivote.Generacion && Pokedex[j].Nombre < Pivote.Nombre)
		{
			//Si no lo esta, realiza el mismo procedimiento de intercambio de posiciones
			i++;
			Swap(&Pokedex[i], &Pokedex[j]);
		}
	
	}

	//Por ultimo, coloca el pivote en su posicion correcta, que seria en el medio del vector
	Swap(&Pokedex[i + 1], &Pokedex[high]);

	return (i + 1);
}

void Orden::Swap(Pokemon* Pokemon1, Pokemon* Pokemon2)
{
	//Guarda en una variable temporal el elemento a intercambiar
	Pokemon Intercambio = *Pokemon1;

	//Coloca en la posicion[i] el elemento de la posicion [j]
	*Pokemon1 = *Pokemon2;

	//Y en la posicion [j], coloca que estaba en la posicion [i]
	*Pokemon2 = Intercambio;

}

std::vector<Pokemon> Orden::Barajear(std::vector<Pokemon> &lista)
{
	//Crea una semilla aleatoria y randomiza un vector

	random_device rds;
	mt19937 a(rds());

	shuffle(lista.begin(), lista.end(), a);


	return lista;
}


vector<Pokemon> Orden::QuickSort(vector<Pokemon>& Pokedex, int low, int high)
{
	Tiempo.Start();

	if (low < high)
	{

		int parti = PartitionReg(Pokedex, low, high);


		QuickSort(Pokedex, low, parti - 1);

		QuickSort(Pokedex, parti + 1, high);

	}

	Tiempo.Stop();

	tiempo6 = Tiempo.ElapsedMilliseconds();

	return Pokedex;
}


int Orden::PartitionReg(std::vector<Pokemon>& Pokedex, int low, int high)
{
	Pokemon Pivote = Pokedex[high];

	int i = -1;

	for (int j = 0; j < high; j++)
	{
		if (Pokedex[j].NumPokedex < Pivote.NumPokedex)
		{
			i++;

			Swap(&Pokedex[i], &Pokedex[j]);

		}

	}

	Swap(&Pokedex[i + 1], &Pokedex[high]);

	return (i + 1);
}




void Orden::ImprimirPokedex(list<Pokemon> lista1, list<Pokemon> lista2, vector<Pokemon> lista3)
{
	system("cls");

	
	list<Pokemon> Listado3;

	while (!lista3.empty())
	{
		Listado3.push_front(lista3.back());
		lista3.pop_back();
	}

	int n = lista1.size();


	cout << "SELECTION SORT                                   SHELL SORT                                 QUICK SORT" << endl;
	cout << "Tiempo: " << tiempo1 <<" ms                                Tiempo: " << tiempo3 <<" ms                          Tiempo: " << tiempo5 << " ms" << endl;

	for( int i = 0; i < n - 1; i++)
	{
		std::cout << std::left << lista1.front().NumPokedex << "," << lista1.front().Nombre << "," << setw(30) << lista1.front().Generacion;
		std::cout << lista2.front().NumPokedex << "," << lista2.front().Nombre << "," << std::setw(30) << lista2.front().Generacion;
 		std::cout << Listado3.front().NumPokedex << "," << Listado3.front().Nombre << "," <<  std::setw(30) << Listado3.front().Generacion << std::endl;
		
		lista1.pop_front();
		lista2.pop_front();
		Listado3.pop_front();
	
	}


}



void Orden::ImprimirPokedex2(list<Pokemon> lista1, list<Pokemon> lista2, vector<Pokemon> lista3)
{
	system("cls");


	int n = lista1.size();

	list<Pokemon> Listado3;

	while (!lista3.empty())
	{
		Listado3.push_front(lista3.back());
		lista3.pop_back();
	}

	cout << "SELECTION SORT                                   SHELL SORT                                 QUICK SORT" << endl;
	cout << "Tiempo: " << tiempo2 << " ms                                Tiempo: " << tiempo4 << " ms                          Tiempo: " << tiempo6 << " ms" << endl;
	
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << std::left << lista1.front().NumPokedex << "," << lista1.front().Nombre << "," << setw(30) << lista1.front().Generacion;
		std::cout << lista2.front().NumPokedex << "," << lista2.front().Nombre << "," << std::setw(30) << lista2.front().Generacion;
		std::cout << Listado3.front().NumPokedex << "," << Listado3.front().Nombre << "," << std::setw(30) << Listado3.front().Generacion << std::endl;
		

		lista1.pop_front();
		lista2.pop_front();
		Listado3.pop_front();


	}


}