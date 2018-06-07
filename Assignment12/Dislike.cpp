#include "Dislike.h" 

void Dislike::execute()
{
	repo.getByTitle(title).decLikes();
	if(watchlist.existsByTitle(title))
		watchlist.getByTitle(title).decLikes();
}

Repository& Dislike::getRepo() const
{
	return repo;
}

string Dislike::getClassName() const
{
	return string("Dislike");
}

string Dislike::getTitle() const
{
	return title;
}
