#pragma once
#include <iostream>

class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer; //a youtube link

public:
	//Default constructor for a movie:
	Movie();

	//Constructor with parameters:
	Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer);

	//Getters:
	std::string getTitle() const { return title; };
	std::string getGenre() const { return genre; };
	int getYear() const { return year; };
	int getLikes() const { return likes; };
	std::string getTrailer() const { return trailer; };

	//Setters:
	void Movie::setTitle(const std::string& t)
	{
		//Sets the title to t. Input: t - string
		this->title = t;
	}
	void Movie::setGenre(const std::string& g)
	{
		//Sets the genre to g. Input: g - string
		this->genre = g;
	}
	void Movie::setYear(const int& y)
	{
		//Sets the year to y. Input: y - integer
		this->year = y;
	}
	void Movie::getLikes(const int& l)
	{
		//Sets the number of likes to l. Input : l - integer
		this->likes = l;
	}

	
	//Plays the current trailer: the page corresponding to the source link is opened in a bowser.
	void play();
};
