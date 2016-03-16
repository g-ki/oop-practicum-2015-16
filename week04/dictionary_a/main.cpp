#include "dictionary.h"
#include <iostream>
#include <cstring>

using namespace std;

void append(char* toAppend, char symbol)
{
	size_t length = strlen(toAppend);
	toAppend[length++] = symbol;
	toAppend[length] = '\0';
}

//Приемаме, че translation е достатъчно голям, за да побере превода
void translate(Dictionary const& dictionary, char const* sentence, char* translation)
{
	int sentenceIndex = 0, currentWordIndex = 0;

	//Пазим си текущата дума в currentWord
	//Заделяме си толкова памет, колкото е голямо изречението, в случай че
	//то се състои от една дума
	char* currentWord = new char[strlen(sentence) + 1];
	
	//"Нулираме" translation, тъй като е възможно потребителят да не подаде празен низ
	strcpy(translation, "");

	while (sentence[sentenceIndex] != '\0')
	{
		//Ако текущият символ в изречението ни е буква, копираме го в текущата дума
		if (isalpha(sentence[sentenceIndex]))
			currentWord[currentWordIndex++] = sentence[sentenceIndex];
		else
		{
			//Ако текущата ни дума не е празният низ
			if (strlen(currentWord) > 0)
			{
				//Не забравяме затапващия символ накрая
				currentWord[currentWordIndex] = '\0';
				//Както и да нулираме индекса за следващата дума
				currentWordIndex = 0;

				//Ако думата я има в речника, копираме превода ѝ
				if (dictionary.withinDict(currentWord) != -1)
					strcat(translation, dictionary.getTranslation(currentWord));
				//Иначе копираме текущата дума
				else
					strcat(translation, currentWord);
				
				//"Нулираме" текущата ни дума
				strcpy(currentWord, "");
			}

			// Проблеми със strcat? Нищо, пишем си наша функция :)
			append(translation, sentence[sentenceIndex]);
		}

		sentenceIndex++;
	}
	
	delete[] currentWord;
}

int main()
{
	Dictionary d;

	d.addWord("Robert", "Downey");
	d.addWord("Alfred", "Nobel");
	d.addWord("Johnny", "Bravo");
	d.print();

	cout << endl;
	d.deleteWord("Alfred");
	d.print();
	cout << endl;

	char tr[100];
	translate(d, "Robert and Johnny went to a party.", tr);
	cout << tr;
}