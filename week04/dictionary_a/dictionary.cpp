#include "dictionary.h"

#include <iostream>
#include <cstring>

using namespace std;

Dictionary::Dictionary()
{
	wordNumber = 0;
}

int Dictionary::withinDict(char const* entry) const
{
	for (int i = 0; i < wordNumber; i++)
		if (!strcmp(entries[i], entry))
			return i;

	return -1;
}

void Dictionary::addWord(char const* word, char const* trans)
{
	int wordIndex = withinDict(word);

	if (wordIndex == -1)
	{
		strncpy(entries[wordNumber], word, 50);
		strncpy(translation[wordNumber++], trans, 50);
	}
	else
		strncpy(translation[wordIndex], trans, 50);
}

void Dictionary::deleteWord(char const* word)
{
	int wordIndex = withinDict(word);

	if (wordIndex != -1)
	{
		for (int i = wordIndex; i < wordNumber - 1; i++)
		{
			strncpy(entries[i], entries[i + 1], 50);
			strncpy(translation[i], translation[i + 1], 50);
		}
		wordNumber--;
	}
}

const char* Dictionary::getTranslation(char const* word) const
{
	int wordIndex = withinDict(word);
	if (wordIndex != -1)
		return translation[wordIndex];
	return "-";
}

void Dictionary::print() const
{
	for (int i = 0; i < wordNumber; i++)
		cout << entries[i] << " -> " << translation[i] << endl;
}