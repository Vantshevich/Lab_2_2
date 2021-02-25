#include <iostream>
#include <fstream>
#include "CList.h"

using namespace std;

/*Ванцевич Олег
  9 группа, лабораторная 1/8, семестр 2, вариант 4*/


  /*	В файле input.txt задан набор целых чисел.
	  Записать их в память используя список.
	  Просматривая  список, найти двузначные и удалить их.
	  Результат  записать в новый список и вывести в файл Output.txt.*/


	  /*Пример 1*/
//	Input data : 1 22 1 213 1 12 2 2 3 1 32 2 1 321 321 31 22
//	Output data : 1 1 213 1 2 2 3 1 2 1 321 321

			/*Пример 2*/
//	Input data : 22 22 22 2 22 22 22
//	Output data : 2

			/*Пример 3*/
//	Input data : 22
//	Output data :

int main() {
	ifstream Input("Input.txt");
	ofstream Output("Output.txt");

	CList<int> arrNumbers;
	if (Input.is_open() && Output.is_open())
	{
		int in;
		Output << "Input data: ";
		while (Input >> in)					//Записываем числа в список и одновременно выводим их в Output.txt для более удобной проверки
		{
			arrNumbers.Push_Back(in);
			Output << in << " ";
		}
		Output << endl;
	}
	Input.close();

	CList<int> arrNewNumbers;
	while (arrNumbers.Size())				//Проверяем, является ли последний элемент списка двузначным, если нет то переписываем его в новый список						
	{										//если да, то удаляем его
		if (arrNumbers.Back() < 100 && arrNumbers.Back() > 9)
			arrNumbers.Pop_Back();
		else
		{
			arrNewNumbers.Push_Back(arrNumbers.Back());
			arrNumbers.Pop_Back();
		}
	}


	if (Output.is_open())					// Выводим данные в файл
	{
		Output << "Output data: ";
		while (arrNewNumbers.Size())
		{
			Output << arrNewNumbers.Back() << " ";
			arrNewNumbers.Pop_Back();
		}
	}
	Output.close();

	system("pause");
	return 0;
}