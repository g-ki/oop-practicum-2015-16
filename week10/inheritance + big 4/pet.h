#ifndef _PET_H
#define _PET_H

class Pet
{
	char* name;
	int age;
	char* owner;
	int cuteness;

	void copy(Pet const&);
public:
	Pet(char const*, int, char const*, int);
	
	Pet();
	~Pet();
	Pet(Pet const&);
	Pet& operator=(Pet const&);
	
	int getCuteness() const;
	char const* getName() const;
	
	void setName(char const*);
};

#endif