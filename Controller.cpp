#include <iostream>
#include "Controller.h"


int Controller::addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer)
{
	Movie m = { title,genre,year,likes,trailer };
	return this->repo.addMovie(m);
}

int Controller::delMovie(const std::string& t)
{
	return this->repo.deleteMovie(t);
}

void Controller::addMovieToMovieslist(const Movie& m)
{
	this->movieslist.add(m);
}

DynamicVector<Movie> Controller::getWatchlistMovies()
{
	return this->movieslist.getMovieslist();
}

void Controller::startWatchlist()
{
	this->movieslist.play();
}

void Controller::nextMovieWatchlist()
{
	this->movieslist.next();
}

DynamicVector<Movie> Controller::printByGenre(const std::string& genre)
{
	// get all the songs from the repository
	DynamicVector<Movie> genree;
	DynamicVector<Movie> v = this->repo.getMovies();
	Movie* movies = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		Movie m = movies[i];
		if (m.getGenre() == genre)
			genree.add(m);

	}
	return genree;
}

int Controller::deleteMovieFromMovieslist(const std::string& t, const int& like)
{	
	int pos;
	pos = this->movieslist.findByTitle(t);
	if (pos != -1)
	{
		this->movieslist.deleteMovie(t);
		this->repo.increaseLikes(t, like);
		return 1;
	}
	return 0;
}

