/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <vector>
int main()
{
	//ablak parameterek
	int width = 1000;
	int height = 500;

	//skala beosztasa, hany db vonal lesz
	int scale = 5;

	//using namespace Graph_lib;
	Graph_lib::Point tl{ 500,100 };// to become top left corner of window
	Simple_window win{ tl,width,height,"Test" };// make a simple window

	//a vonalak közötti pixeltávolság kiszámítása aránypárral
	int unitWidth_x = width / scale;
	int unitWidth_y = height / scale;

	//a vonalak x és y irányban
	Lines x,y;

	//feltöltjük a Lines osztályt a vonalakkal add metódussal x irányban.
	//aránypárral léptetjük és határozzuk meg a kezdõ és végpont értékeit
	for (int i = 1; i < scale; ++i) {
		x.add(Point(unitWidth_x * i, 0), Point(unitWidth_x * i, height));
	}

	//feltöltjük a Lines osztályt a vonalakkal add metódussal x irányban.
	//aránypárral léptetjük és határozzuk meg a kezdõ és végpont értékeit
	for (int i = 1; i < scale; ++i) {
		y.add(Point(0,unitWidth_y * i), Point(width,unitWidth_y * i));
	}

	x.set_color(Color::black);
	y.set_color(Color::black);

	//meghatarozzuk konstans értékekkel hogy a kék színû téglalap melyik cellába essen.
	const int POS_RECT_X = 3;
	const int POS_RECT_Y = 4;

	//itt adjuk meg pixelpontosan, hogy az adott cellaba essen, es ki is töltse azt.
	//kezdõpontok értékei: cellaszélesség * cellaszám.
	//szélesség,hosszúság= cella szélessége x és y irányban.
 	Graph_lib::Rectangle R(Point{ unitWidth_x * POS_RECT_X,unitWidth_y * POS_RECT_Y }, unitWidth_x, unitWidth_y);
	R.set_fill_color(Color::blue);

	//letrehozunk egy rectangle típusú vektort, amibe majd a téglalapokat fogjuk belerakni.
	Vector_ref<Graph_lib::Rectangle> R_vector;

	//ebben a ciklusban töltjük fel az R_vectort.
	//a végén hozzá is adjuk az ablakhoz, az egyes elemek sima tömbindexeléssel érhetõek el.
	for (int i = 0; i < 2; ++i) {
		R_vector.push_back(new Graph_lib::Rectangle(Point{ unitWidth_x * (3-i),unitWidth_y * i }, unitWidth_x, unitWidth_y));
		R_vector[i].set_fill_color(Color::green);
		win.attach(R_vector[i]);
	}

	//meghatarozzuk konstans értékekkel hogy a kép melyik cellába essen.
	const int POS_IMG_X = 2;
	const int POS_IMG_Y = 3;

	//itt adjuk meg pixelpontosan, hogy az adott cellaba essen.
	//kezdõpontok értékei: cellaszélesség * cellaszám.
	//szélesség,hosszúság= cella szélessége x és y irányban.
	Image unitIMG(Point(unitWidth_x * POS_IMG_X, unitWidth_y * POS_IMG_Y), "unitIMG.jpg");

	
	win.attach(x);
	win.attach(y);
	win.attach(unitIMG);
	win.attach(R);

	win.wait_for_button();// give control to the display engine
}
