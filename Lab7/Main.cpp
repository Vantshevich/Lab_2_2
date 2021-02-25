#include <iostream>
#include <fstream>
#include "CStack.h"

using namespace std;

/*Ванцевич Олег
  9 группа, лабораторная 1/7, семестр 2, вариант 4*/


  /*	В файле input.txt задан набор целых чисел, записать их в память используя стек.
	  Просматривая по парам, удалить один из них, если они одинаковые.
	  Pезультат записать в новый стек  и вывести в файл Output.txt.*/

	  /*Пример 1*/
//	Input data : 34 2 2 292 23 3 2 2 3 1 2 1 223 1 2 1 2 2 1 12 22 1 22 12 2 22 12121 2 122 12 1 21212 1 21 21 21
//	Output data : 34 2 292 23 3 2 3 1 2 1 223 1 2 1 2 1 12 22 1 22 12 2 22 12121 2 122 12 1 21212 1 21

				/*Пример 2*/
//	Input data : 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
//	Output data : 1

				/*Пример 3*/
//	Input data : 1
//	Output data : 1

int main() {
	ifstream Input("Input.txt");
	ofstream Output("Output.txt");

	CStack<int> arrNumbers;
	if (Input.is_open() && Output.is_open())
	{
		int in;
		Output << "Input data: ";
		while (Input >> in)					//Записываем числа в стек и одновременно выводим их в Output.txt для более удобной проверки
		{
			arrNumbers.Push(in);
			Output << in << " ";
		}
		Output << endl;
	}
	Input.close();

	CStack<int> arrNewNumbers;
	arrNewNumbers.Push(arrNumbers.Top());
	arrNumbers.Pop();
	while (arrNumbers.Size())				//	Идем по нашему стеку и поочередно сравниваем последние элементы в нем и в новом стеке, 
	{										// и если они различны, то перепеисываем из новго в старый
		if (arrNewNumbers.Top() != arrNumbers.Top())
		{
			arrNewNumbers.Push(arrNumbers.Top());
			arrNumbers.Pop();
		}
		else
		{
			arrNumbers.Pop();
		}
	}


	if (Output.is_open())					// Выводим данные в файл
	{
		Output << "Output data: ";
		while (arrNewNumbers.Size())
		{
			Output << arrNewNumbers.Top() << " ";
			arrNewNumbers.Pop();
		}
	}
	Output.close();

	system("pause");
	return 0;
}