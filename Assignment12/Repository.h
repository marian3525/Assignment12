#pragma once

#include <vector>
#include "Tutorial.h"

class Repository {
private:
	vector<Tutorial> elems;
	string repoType;		//repo/watchlist
public:
	explicit Repository(string repoType = string("repo"));
	~Repository();
	void add(Tutorial tutorial);
	void remove(string nameToRemove);
	string getType() { return repoType; }

	//the name cannot be changed
	void update(string nameToUpdate, string presenter, int duration, int likes, string link);
	bool existsByTitle(string title);
	Tutorial& getByTitle(string title);
	vector<Tutorial> getAll();
	unsigned long getSize();
	Tutorial& operator[](int pos);
	void sync();
};


