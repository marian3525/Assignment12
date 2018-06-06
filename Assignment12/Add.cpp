#include "Add.h"

void Add::execute()
{
	Tutorial t{ title, presenter, duration, likes, link };
	repo.add(t);
	
}

Repository& Add::getRepo() const
{
	return repo;
}

string Add::getClassName() const
{
	return string("Add");
}

string Add::getTitle() const
{
	return title;
}
