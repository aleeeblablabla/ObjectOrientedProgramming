#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printWatchListMenu();

	void addMovieToRepo();
	void displayAllMoviesRepo();
	void deleteMovieRepo();
	void addMovieToMovieslist();
	void updG();
	void updL();
	void updY();
	void UI::printUserMenu();
	void UI::seeMovies();
	void UI::printWatchList();
	void UI::deleteMovieWatchlist();
};