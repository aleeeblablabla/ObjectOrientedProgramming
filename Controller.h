#pragma once
#include "Repository.h"
#include "Movieslist.h"
#include "DynamicVector.h"
#include <iostream>

class Controller
{
private:
	Repository repo;
	Movieslist movieslist;
public:
	Controller(const Repository& r, const Movieslist& m) :repo(r), movieslist(m) {}
	Repository getRepo() const { return repo; }
	
	//Adds a movie to the repository. Input: m - Movie. Output: the movie is added.
	int addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer);
	//Deletes a movie from repository. Input: m - Movie. Output: the movie is deleted.
	int delMovie(const std::string& t);
	//If the movie was found,the genre will be updated with the new one. Input: t -title of the movie, genre - the genre. 
	int Controller::updGenre(const std::string& title, const std::string& genre){ return this->repo.updateGenre(title, genre); }
	//If the movie was found,the no of likes will be updated with the new one. Input: t -title of the movie, likes - no of likes.
	int Controller::updLikes(const std::string& title, const int& likes) { return this->repo.updateLikes(title, likes); }
	//If the movie was found,the year will be updated with the new one. Input: t -title of the movie, year - the year.
	int Controller::updYear(const std::string& title, const int& year) { return this->repo.updateYear(title, year); }
	//Adds a movie to the list. Input: m - Movie. Output: the movie is added.
	void Controller::addMovieToMovieslist(const Movie& m); 
	//get all the movies in the watchlist
	DynamicVector<Movie> Controller::getWatchlistMovies();
	//start the watchlist
	void Controller::startWatchlist();
	//go to the next movie 
	void Controller::nextMovieWatchlist();
	//print all the movie that have the specified genre. Input: genre (of the movie). Output: the list of movies with that genre
	DynamicVector<Movie> Controller::printByGenre(const std::string& genre);
	//Deletes a movie from repository. Input: m - Movie. Output: the movie is deleted.
	int deleteMovieFromMovieslist(const std::string& t, const int& like);

};