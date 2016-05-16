#ifndef _CATE_H
#define _CATE_H

#include "Pet.h"

class Cate : public Pet
{
	int lives;
public:
	Cate();
	~Cate();
	Cate(Cate const&);
	Cate& operator=(Cate const&);
	
	Cate(char const*, int, char const*, int, int);
};

#endif