#ifndef _DICTIONARY_H
#define _DICTIONARY_H

class Dictionary
{
private:
	char entries[100][50];
	char translation[100][50];
	int wordNumber;
public:
	Dictionary();

	void addWord(char const*, char const*);
	void deleteWord(char const*);

	const char* getTranslation(char const*) const;
	int withinDict(char const*) const;
	void print() const;
};

#endif