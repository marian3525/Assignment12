#include "Remove.h"

void Remove::execute()
{
	repo.remove(title);
}

Repository& Remove::getRepo() const
{
	return repo;
}

string Remove::getClassName() const
{
	return string("Remove");
}

string Remove::getTitle() const
{
	return title;
}
