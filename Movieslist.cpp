#include "Movieslist.h"
#include <stdio.h>

Movieslist::Movieslist()
{
	this->current = 0;
}

void Movieslist::add(const Movie& m)

{
	this->movies.add(m);
}

int Movieslist::deleteMovie(const std::string& t)
{
	int pos = this->findByTitle(t);
	if (pos != -1)
	{
		this->movies.deleted(pos);
		return 1;
	}
	return 0;
}


DynamicVector<Movie> Movieslist::getMovieslist()

{
	return this->movies;
}

Movie Movieslist::getCurrentMovie()
{
	if (this->current == this->movies.getSize())
		this->current = 0;
	Movie* elems = this->movies.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Movie{};
}

void Movieslist::play()
{
	if (this->movies.getSize() == 0)
		return;
	this->current = 0;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

void Movieslist::next()
{
	if (this->movies.getSize() == 0)
		return;
	this->current++;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}
int Movieslist::findByTitle(const std::string& t)
{
	Movie* mm;
	mm = this->movies.getAllElems();
	for (int i = 0; i < this->movies.getSize(); i++)
	{
		if (mm[i].getTitle() == t)
			return i;
	}
	return -1;
}