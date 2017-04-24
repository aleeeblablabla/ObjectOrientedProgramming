#include "UI.h"
#include <string>
#include <iostream>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit" << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add a movie" << endl;
	cout << "\t 2 - See all" << endl;
	cout << "\t 3 - Delete a movie" << endl;
	cout << "\t 4 - Update the genre of a movie" << endl;
	cout << "\t 5 - Update the year of a movie" << endl;
	cout << "\t 6 - Update the number of likes of a movie" << endl;
	cout << "\t 0 - Back" << endl;
}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - See the movies having a given genre." << endl;
	cout << "\t 2 - See watchlist." << endl;
	cout << "\t 3 - Delete a movie from watchlist and rate it." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printWatchListMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie" << endl;
	cout << "\t 3 - Play" << endl;
	cout << "\t 4 - Next" << endl;
	cout << "\t 0 - Back" << endl;
}

void UI::displayAllMoviesRepo()
{
	DynamicVector<Movie> m = this->ctrl.getRepo().getMovies();
	Movie* movies = m.getAllElems();
	if (movies == NULL)
		return;
	if (m.getSize() == 0)
	{
		cout << "There are no movies." << endl;
		return;
	}

	for (int i = 0; i < m.getSize(); i++)
	{
		Movie m = movies[i];
		cout << m.getTitle() << " \n   Genre: " << m.getGenre() << " \n   Year: " << m.getYear() <<  " \n   Likes: " << m.getLikes() << " \n   Trailer: " << m.getTrailer() << endl;
	}
}

void UI::addMovieToRepo()
{
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: " << endl;
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: " << endl;
    int year=0;
	cin >> year;
	cin.ignore();
	cout << "Enter the number of likes: " << endl;
	int likes = 0;
	cin >> likes;
	cin.ignore();
	cout << "Trailer link: ";
	std::string link;
	getline(cin, link);
	if (this->ctrl.addMovieToRepository(title, genre, year, likes, link) == 1)
		printf("Movie successfully added!\n"); 
	else 
		printf("This movie is already in the list!\n");
	
}

void UI::deleteMovieRepo()
{
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	if (this->ctrl.delMovie(title) == 1)
		printf("Movie successfully deleted!\n");
	else
		printf("Movie not found!\n");
}

void UI::updG()
{
	int k;
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: " << endl;
	std::string genre;
	getline(cin, genre);
	k = this->ctrl.updGenre(title, genre);
	if (k == 1)
		cout << "Movie successfully updated!" << endl;
	else
		cout << "Movie not found!" << endl;

}

void UI::updL()
{
	int k;
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter the number of likes: " << endl;
	int likes;
	cin >> likes;
	k = this->ctrl.updLikes(title, likes);
	if (k == 1)
		cout << "Movie successfully updated!" << endl;
	else
		cout << "Movie not found!" << endl;

}

void UI::updY()
{
	int k;
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Enter the year: " << endl;
	int year;
	cin >> year;
	k = this->ctrl.updYear(title, year);
	if (k == 1)
		cout << "Movie successfully updated!" << endl;
	else
		cout << "Movie not found!" << endl;
}

void UI::seeMovies()
{
	DynamicVector<Movie> v;
	cout << "Enter the genre: " << endl;
	std::string genre;
	getline(cin, genre);
	int command, command1;
	int i = 0;
	v = this->ctrl.printByGenre(genre);
	//DynamicVector<Movie> v = this->ctrl.getRepo().getMovies();
	Movie* movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no movies" << endl;
		return;
	}
	this->ctrl.startWatchlist();
	while (i < v.getSize())
	{
		Movie m = movies[i];
		cout << m.getTitle() << " \n   Genre: " << m.getGenre() << " \n   Year: " << m.getYear() << " \n   Likes: " << m.getLikes() << " \n   Trailer: " << m.getTrailer() << endl;
		//this->ctrl.nextMovieWatchlist();
		printf("Do you want to add this movie to the watchlist? \n");
		printf("1 Yes\n");
		printf("2 No\n");
		cout << "Input the command: ";
		cin >> command;
		if (command == 1)
		{
			this->ctrl.addMovieToMovieslist(m);
			//this->ctrl.delMovie(m.getTitle());
			printf("The movie was added to the watchlist!\n");
		}
		printf("1 Next movie.\n");
		printf("2 Back to the main menu. \n");
		cout << "Input the command: ";
		cin >> command1;
		if (command1 == 2)
			break;
		else
			i = i + 1;
			this->ctrl.nextMovieWatchlist();
		if (i == v.getSize())
		{
			i = 0;
			v = this->ctrl.printByGenre(genre);
			Movie* movies = v.getAllElems();
			this->ctrl.startWatchlist();
			if (movies == NULL)
				return;
			if (v.getSize() == 0)
			{
				cout << "There are no more movies! :)" << endl;
				return;
			}
		}
	}
}

void UI::printWatchList()
{
	DynamicVector<Movie> v = this->ctrl.getWatchlistMovies();
	Movie* movies = v.getAllElems();
	if (movies == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "The watchlist is empty." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Movie m = movies[i];
		cout << m.getTitle() << " \n   Genre: " << m.getGenre() << " \n   Year: " << m.getYear() << " \n   Likes: " << m.getLikes() << " \n   Trailer: " << m.getTrailer() << endl;
	}
}

void UI::deleteMovieWatchlist()
{
	cout << "Enter the title: " << endl;
	std::string title;
	getline(cin, title);
	cout << "Have you enjoyed this movie?" << endl;
	cout << "Enter your answer: " << endl;
	std::string answer;
	getline(cin, answer);
	int like;
	if (answer == "yes")
		like = 1;
	else
		like = 0;
	if (this->ctrl.deleteMovieFromMovieslist(title,like) == 1)
		cout << "Movie successfully deleted!" << endl;
	else
		cout << "Movie not found!" << endl;
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					this->displayAllMoviesRepo();
					break;
				case 3:
					this->deleteMovieRepo();
					break;
				case 4:
					this->updG();
					break;
				case 5:
					this->updY();
					break;
				case 6:
					this->updL();
					break;
				}
			}
		}
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUser{ 0 };
				cout << "Input the command: ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
					this->seeMovies();
					break;
				case 2:
					this->printWatchList();
					break;
				case 3:
					this->deleteMovieWatchlist();
					break;
				}
			}
		}
	}
}