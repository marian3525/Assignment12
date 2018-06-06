#include "Like.h"

void Like::execute()
{
	if (likesAdded == 1)
		repo.getByTitle(title).incLikes();
	else
		repo.getByTitle(title).decLikes();
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
