#pragma once
#include "DynamicVector.h"
#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

class Movieslist
{
private:
	DynamicVector<Movie> movies {};
	int current;

public:
	Movieslist();
	void add(const Movie& movie);
	int deleteMovie(const std::string& t);
	DynamicVector<Movie> getMovieslist();
	void Movieslist::play();
	void Movieslist::next();
	Movie Movieslist::getCurrentMovie();
	int Movieslist::findByTitle(const std::string& t);
};


