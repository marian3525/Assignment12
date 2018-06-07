#include "Update.h"

void Update::execute()
{
	repo.update(title, presenter, duration, likes, link);
	if (watchlist.existsByTitle(title)) {
		watchlist.update(title, presenter, duration, likes, link);
	}
}

Repository& Update::getRepo() const
{
	return repo;
}

string Update::getClassName() const
{
	return string("Update");
}

string Update::getTitle() const
{
	return title;
}
