#pragma once
#include "Movie.h"
#include "DynamicVector.h"
#include <assert.h>

class Repository
{
private:
	DynamicVector<Movie> movies {};
	std::string filename;
public:
	//Default constructor: initializes an object of type repository.
	Repository() {}

	int Repository::addMovie(const Movie& m);//Adds a movie to the repository. Input: m - Movie. Output: the movie is added.
	DynamicVector<Movie> getMovies() const { return movies; } //get all the movies
	int Repository::findByTitle(const std::string& t); //Find a movie by title. Input: t - title of movie. Output: the position
													   // on which the movie was found or -1 if the movie was not found.
	int Repository::deleteMovie(const std::string& t);//Deletes a movie from repository. Input: m - Movie. Output: the movie is deleted.
	int Repository::updateGenre(const std::string& title, const std::string& genre);//If the movie was found,the genre will be updated with 
													  //the new one. Input: t -title of the movie, genre - the genre. 
	int Repository::updateYear(const std::string& t, const int& year);//If the movie was found,the year will be updated with 
													  //the new one. Input: t -title of the movie, year - the year. 
	int Repository::updateLikes(const std::string& t, const int& likes);//If the movie was found,the no of likes will be updated with 
													  //the new one. Input: t -title of the movie, likes - no of likes.
	int Repository::increaseLikes(const std::string& title, const int& likes); //If the movie was found,the no of likes will be updated with 
													  //the new one. Input: t -title of the movie, likes - no of likes.
	
private:
	void readFromFile();
	void writeToFile();

	void testRepo() {
		Repository r{};
		DynamicVector<Movie> movies;
		assert(movies.getSize() == 0);
		Movie m{ "Lala", "ads", 2007,123, "google.com" };
		int k = r.addMovie(m);
		assert(movies.getSize() == 1);
		int p = r.deleteMovie("Lala");
		assert(movies.getSize() == 0);
	}

};