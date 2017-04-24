#include "Movie.h"
#include "UI.h"
#include <Windows.h>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;


void miniMain()
{
	system("color f4");

	Repository repo{};
	Movieslist m{};

	// add some movies
	Movie m1{ "The Great Gatsby","Romance",2013,123,"https://www.youtube.com/watch?v=sN183rJltNM" };
	Movie m2{ "I origins","Drama",2014,99,"https://www.youtube.com/watch?v=amFKzf4Lr5M" };
	Movie m3{ "Beauty and the beast","Fantasy",2017,133,"https://www.youtube.com/watch?v=e3Nl_TCQXuw" };
	Movie m4{ "Fast and furious","Action",2017,45,"https://www.youtube.com/watch?v=2DMpqplvADQ" };
	Movie m5{ "Me before you","Romance",2016,234,"https://www.youtube.com/watch?v=Eh993__rOxA&t=9s" };
	Movie m6{ "The ticket","Drama",2016,34,"https://www.youtube.com/watch?v=HfyOMkE-r1M" };
	Movie m7{ "Miss Peregrine's Home for Peculiar Children","Fantasy",2016,456,"https://www.youtube.com/watch?v=tV_IhWE4LP0" };
	Movie m8{ "The great dictator","Comedy",1940,987,"https://www.youtube.com/watch?v=zroWIN-lS8E" };
	repo.addMovie(m8);
	repo.addMovie(m1);
	repo.addMovie(m2);
	repo.addMovie(m3);
	repo.addMovie(m4);
	repo.addMovie(m5);
	repo.addMovie(m6);
	repo.addMovie(m7);

	Controller ctrl{ repo , m };
	UI ui{ ctrl };
	ui.run();

}
int main()
{
	miniMain();

	_CrtDumpMemoryLeaks();
	return 0;
}