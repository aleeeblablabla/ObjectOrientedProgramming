#include <iostream>
#include "Repository.h"
#include <string>

using namespace std;

int Repository::findByTitle(const std::string& t)
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

int Repository::addMovie(const Movie& m)
{
	if (findByTitle(m.getTitle()) == -1)
	{
		this->movies.add(m);
		return 1;
	}
	return 0;
}

int Repository::deleteMovie(const std::string& t)
{
	int pos = findByTitle(t);
	if (pos != -1)
	{
		this->movies.deleted(pos);
		return 1;
	}
	return 0;
}


int Repository::updateGenre(const std::string& title, const std::string& genre)
{
	int p;
	Movie m;
	p = findByTitle(title);
	if (p == -1)
		return 0;
	else
	{
		m = this->movies.getElementFromPos(p);
		Movie newMovie = { m.getTitle(),genre,m.getYear(),m.getLikes(),m.getTrailer() };
		deleteMovie(m.getTitle());
		addMovie(newMovie);
		return 1;
	}
}

int Repository::increaseLikes(const std::string& title, const int& likes)
{
	int p;
	Movie m;
	p = findByTitle(title);
	if (p == -1)
		return 0;
	else
	{
		m = this->movies.getElementFromPos(p);
		Movie newMovie = { m.getTitle(),m.getGenre(),m.getYear(),m.getLikes()+likes,m.getTrailer() };
		deleteMovie(m.getTitle());
		addMovie(newMovie);
		return 1;
	}
}

int Repository::updateLikes(const std::string& title, const int& likes)
{
	int p;
	Movie m;
	p = findByTitle(title);
	if (p == -1)
		return 0;
	else
	{
		m = this->movies.getElementFromPos(p);
		Movie newMovie = { m.getTitle(),m.getGenre(),m.getYear(), likes,m.getTrailer() };
		deleteMovie(m.getTitle());
		addMovie(newMovie);
		return 1;
	}
}

int Repository::updateYear(const std::string& title, const int& year)
{
	int p;
	Movie m;
	p = findByTitle(title);
	if (p == -1)
		return 0;
	else
	{
		m = this->movies.getElementFromPos(p);
		Movie newMovie = { m.getTitle(),m.getGenre(),year,m.getLikes(),m.getTrailer() };
		deleteMovie(m.getTitle());
		addMovie(newMovie);
		return 1;
	}
}