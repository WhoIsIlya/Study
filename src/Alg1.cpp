#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	vector<int> firstWordIndex;
	vector<int> secondWordIndex;
	int temp1, temp2, temp_distance, count = 0;;
	int first_word_first_match = 0, first_word_last_match = 0;
	int second_word_first_match = 0, second_word_last_match = 0;
	int max_distance = 0, min_distance = 0;
	string word, word1, word2;
	word1 = "day";
	word2 = "today";
	ifstream file;
	file.open("input1.txt");
	if (!file.is_open())
		return 0;

	clock_t start = clock();

	while (file >> word) //Чтение из файла
	{
		if (word == word1)
		{
			firstWordIndex.push_back(count); //Индексируем совпадения первого слова и помещаем номера в вектор
		}
		else if (word == word2)
		{
			secondWordIndex.push_back(count); //Индексируем совпадения второго слова и помещаем номера в вектор
		}
		count++;
	}

	int minx = abs(firstWordIndex[0] - secondWordIndex[0]); //Находим начальный минимум
	int i = 0, j = 0;
	while (i < secondWordIndex.size() && j < secondWordIndex.size()) //Проходим оба массива один раз
	{
		int x = firstWordIndex[i] - secondWordIndex[j]; //Разница между текущими элементами двух массивов
		if (x < 0) //Если она меньше нуля, то инверсируем и двигаемся дальше по первому массиву
		{
			x = -x;
			i++;
		}
		else if (x > 0) //Если больше нуля, то смещаемся по второму массиву
		{
			j++;
		}
		else
		{
			minx = 0;
			break;
		}
		if (x < minx) //Если меньше текущей, то заменяем
		{
			minx = x;
		}
	}

	min_distance = minx - 1;
	temp1 = abs(firstWordIndex[0] - secondWordIndex[secondWordIndex.size() - 1])-1;
	temp2 = abs(secondWordIndex[0] - firstWordIndex[firstWordIndex.size() - 1])-1;
	if (temp1 > temp2) //Находим максимальную дистанцию между первыми и последними совпадениями
		max_distance = temp1;
	else
		max_distance = temp2;

	clock_t end = clock();
	double seconds = (double)(end-start) / CLOCKS_PER_SEC;
	cout << "Max distance: " << max_distance << endl;
	cout << "Min distance: " << min_distance << endl;
	cout << "Words in text: " << count << endl;
	cout << "Time: " << seconds << " s." << endl;
	return 0;
}

//Потрачено времени 6ч
//Сложность алгоритма O(n)
