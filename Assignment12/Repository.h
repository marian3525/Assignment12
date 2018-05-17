#pragma once

#include <vector>
#include "Tutorial.h"

class Repository {
private:
	vector<Tutorial> elems;
	bool toDestroy = true;
public:
	explicit Repository(bool toDestroy);
	~Repository();
	void add(Tutorial tutorial);
	void remove(string nameToRemove);

	//the name cannot be changed
	void update(string nameToUpdate, string presenter, int duration, int likes, string link);
	bool existsByTitle(string title);
	Tutorial& getByTitle(string title);
	vector<Tutorial> getAll();
	unsigned long getSize();
	Tutorial& operator[](int pos);
	void sync();
};


