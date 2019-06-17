#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <map>
#include <locale.h>
#include <string>
//#include <ctype.h>
#include <cctype>
#include <algorithm>

using namespace std;

typedef map<string, int> AllWords;	//ключ-слово, а связанное с ней int — это число раз, которое это слово встретилось.

void countWords(istream& in, AllWords& words)
{	
	string s="";  //слово
	cout<<"Исходный текст:"<<endl<<endl;
	while (in>>s)		//если еще нет такого слова создаем новое  и прибавлем,если есть прибавляем
	{
		cout<<s<<" ";
		transform(s.begin(), s.end(), s.begin(), ::tolower);	//приведем к нижнему регистру все слова
		while(!(isalpha(s[0]))  || !(isalpha(s[s.length()-1])) )	//пока не избавимся от всех лишних знаков вокруг слова
		{
			if(!(isalpha(s[s.length()-1])) && s.length()>1 )	//проверка последнего символа строки на букву и переписывание слова
			{	
				s=s.substr(0,s.length()-1);
			}
			if(!(isalpha(s[0])) && s.length()>1 )	//проверка первого символа строки на букву и переписывание слова
			{	
				s=s.substr(1,s.length());
			}
		}
		words[s]++;		//счетчик повторений по ключу
	}
			
}

#endif
