#include <iostream>
#include <fstream>
#include <map>
#include "func.h"

using namespace std;


int main(void)
{

	setlocale(LC_ALL,"Russian");
	ifstream in("D:\\test.txt");

	if (!in.is_open())
	{ 
		cout<< "Невозможно открыть файл. "<<endl; 
		return 1; 
	}  
  
	AllWords w;		//map слов и их количества
	countWords(in, w);	//вызов функции с подсчетом слов

	for (AllWords::iterator p = w.begin();p != w.end(); ++p) //вывод
	{
		cout<<"Слово<<"<<p->first << ">> . Количество повторений:  "<< p->second <<endl<<endl;
	}

	in.close();//закроем поток

	system("pause");
	return 0;
}
