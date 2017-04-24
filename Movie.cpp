#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie() : title(""), genre(""), year(), likes(), trailer("") {}

Movie::Movie(const std::string& title, const std::string& genre, const int& year, const int& likes, const std::string& trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}
