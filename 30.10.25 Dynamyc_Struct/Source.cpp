//Динамічні структури даних – стек
//Завдання
//Є рядок символів, ознакою кінця якого є; .У рядку можуть бути фігурні, круглі, квадратні дужки.Дужки можуть бути відкриваючими та закриваючими.
//Необхідно перевірити коректність розміщення дужок.При цьому необхідно, щоб виконалися такі правила :
//1.	Кожна дужка, що відкриває, повинна мати праворуч таку саму дужку, що закриває.Зворотне також має бути правильним.
//2.	Пари дужок різних типів, що відкривають і закривають, повинні бути правильно розташовані по відношенню одна до одної.
//Викорстати стек, який я зробив на занятті.
#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
	Queue<char> q;
	char ch;
	cout << "Enter string ending with ; : ";
	cin.get(ch);
	while (ch != ';')
	{
		q.enqueue(ch);
		cin.get(ch);
	}
	bool isCorrect = true;
	Queue<char> stack;
	while (!q.isEmpty() && isCorrect)
	{
		char curr = q.dequeue();
		if (curr == '(' || curr == '{' || curr == '[')
		{
			stack.enqueue(curr);
		}
		else if (curr == ')' || curr == '}' || curr == ']')
		{
			if (stack.isEmpty())
			{
				isCorrect = false;
			}
			else
			{
				char top = stack.dequeue();
				if ((curr == ')' && top != '(') ||
					(curr == '}' && top != '{') ||
					(curr == ']' && top != '['))
				{
					isCorrect = false;
				}
			}
		}
	}
	if (!stack.isEmpty())
	{
		isCorrect = false;
	}
	if (isCorrect)
	{
		cout << "The string is correct." << endl;
	}
	else
	{
		cout << "The string is incorrect." << endl;
	}
	return 0;
}