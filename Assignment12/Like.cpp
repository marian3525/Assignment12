#include "Like.h"

void Like::execute()
{
		repo.getByTitle(title).incLikes();
		if (watchlist.existsByTitle(title))
			watchlist.getByTitle(title).incLikes();
}

Repository& Like::getRepo() const
{
	return repo;
}

string Like::getClassName() const
{
	return string("Like");
}

string Like::getTitle() const
{
	return title;
}
