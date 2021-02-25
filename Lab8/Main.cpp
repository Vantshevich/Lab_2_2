#include <iostream>
#include <fstream>
#include "CList.h"

using namespace std;

/*�������� ����
  9 ������, ������������ 1/8, ������� 2, ������� 4*/


  /*	� ����� input.txt ����� ����� ����� �����.
	  �������� �� � ������ ��������� ������.
	  ������������  ������, ����� ���������� � ������� ��.
	  ���������  �������� � ����� ������ � ������� � ���� Output.txt.*/


	  /*������ 1*/
//	Input data : 1 22 1 213 1 12 2 2 3 1 32 2 1 321 321 31 22
//	Output data : 1 1 213 1 2 2 3 1 2 1 321 321

			/*������ 2*/
//	Input data : 22 22 22 2 22 22 22
//	Output data : 2

			/*������ 3*/
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
		while (Input >> in)					//���������� ����� � ������ � ������������ ������� �� � Output.txt ��� ����� ������� ��������
		{
			arrNumbers.Push_Back(in);
			Output << in << " ";
		}
		Output << endl;
	}
	Input.close();

	CList<int> arrNewNumbers;
	while (arrNumbers.Size())				//���������, �������� �� ��������� ������� ������ ����������, ���� ��� �� ������������ ��� � ����� ������						
	{										//���� ��, �� ������� ���
		if (arrNumbers.Back() < 100 && arrNumbers.Back() > 9)
			arrNumbers.Pop_Back();
		else
		{
			arrNewNumbers.Push_Back(arrNumbers.Back());
			arrNumbers.Pop_Back();
		}
	}


	if (Output.is_open())					// ������� ������ � ����
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