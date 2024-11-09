#include "iostream"
#include "vector"
#include "string"

int main()
{
	std::string EnterString;
	std::vector <char> StringToChars;
	std::vector <int> CountingChar;
	
	// Ввод строки и разделение её на символы
	std::cout << "[IN]: ";
	std::getline(std::cin, EnterString);
	for (int i=0;i<EnterString.size();i++)
	{
		StringToChars.push_back(EnterString[i]);
		CountingChar.push_back(1);
	}
	
	//подсчет кол-ва символов и удаление лишних из массива
	int SizeForCounting = StringToChars.size();
	for (int i = 0; i < SizeForCounting; i++)
	{
		for (int j = i+1; j < SizeForCounting; j++)
		{
			if (StringToChars[i] == StringToChars[j])
			{
				CountingChar[i]++;
				StringToChars.erase(StringToChars.begin()+j);
				CountingChar.erase(CountingChar.begin() + j);
				SizeForCounting--;
			}
		}
	}
	
	// Сортировка символов по количеству повторений
	int TempForSwap;
	char CharForSwap;
	for (int SwapIndex = 0; SwapIndex < SizeForCounting ; SwapIndex++)
	{
		for (int i = 0; i < SizeForCounting-1; i++)
		{
			if (CountingChar[i] < CountingChar[i + 1])
			{
				TempForSwap = CountingChar[i + 1];
				CountingChar[i + 1] = CountingChar[i];
				CountingChar[i] = TempForSwap;
				CharForSwap = StringToChars[i + 1];
				StringToChars[i + 1] = StringToChars[i];
				StringToChars[i] = CharForSwap;
			}
			if ((CountingChar[i] == CountingChar[i + 1]) && (StringToChars[i] > StringToChars[i + 1]))
			{
				CharForSwap = StringToChars[i + 1];
				StringToChars[i + 1] = StringToChars[i];
				StringToChars[i] = CharForSwap;
			}
		}
	}

	// Вывод массива
	std::cout << "\n[IN]: ";
	for (int i = 0; i < SizeForCounting; i++)
	{
		std::cout << "\n" << StringToChars[i] << ": " << CountingChar[i];
	}
	return 61;
}