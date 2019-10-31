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
	ifstream file;
	file.open("input.txt");
	if (!file.is_open()) 
		return 0;
	int temp1, temp2, temp_distance;
	int first_word_first_match = 0, first_word_last_match = 0;
	int second_word_first_match = 0, second_word_last_match = 0;
	int max_distance = 0, min_distance = 0;
	string word, word1, word2;
	word1 = "day";
	word2 = "today";
	int count = 0;
	clock_t start = clock();
	
	while (file >> word)
	{
		if (word == word1)
		{
			firstWordIndex.push_back(count);
		}
		else if (word == word2)
		{
			secondWordIndex.push_back(count);
		}
		count++;
	}

	for (int i = 0; i < firstWordIndex.size(); i++)
	{
		for (int j = 0; j < secondWordIndex.size(); j++)
		{
			temp_distance = abs(firstWordIndex[i] - secondWordIndex[j]);
			if(temp_distance < min_distance || min_distance == 0)
				min_distance = temp_distance - 1;
		}
	}
	temp1 = abs(firstWordIndex[0] - secondWordIndex[secondWordIndex.size() - 1])-1;
	temp2 = abs(secondWordIndex[0] - firstWordIndex[firstWordIndex.size() - 1])-1;
		


	clock_t end = clock();
	double seconds = (double)(end-start) / CLOCKS_PER_SEC;
	if (temp1 > temp2)
		max_distance = temp1;
	else
		max_distance = temp2;
	cout << "Max distance: " << max_distance << endl;
	cout << "Min distance: " << min_distance << endl;
	cout << "Words in text: " << count << endl;
	cout << "Time: " << seconds << " s." << endl;
	return 0;
}