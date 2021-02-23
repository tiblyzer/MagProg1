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

	//a vonalak k�z�tti pixelt�vols�g kisz�m�t�sa ar�nyp�rral
	int unitWidth_x = width / scale;
	int unitWidth_y = height / scale;

	//a vonalak x �s y ir�nyban
	Lines x,y;

	//felt�ltj�k a Lines oszt�lyt a vonalakkal add met�dussal x ir�nyban.
	//ar�nyp�rral l�ptetj�k �s hat�rozzuk meg a kezd� �s v�gpont �rt�keit
	for (int i = 1; i < scale; ++i) {
		x.add(Point(unitWidth_x * i, 0), Point(unitWidth_x * i, height));
	}

	//felt�ltj�k a Lines oszt�lyt a vonalakkal add met�dussal x ir�nyban.
	//ar�nyp�rral l�ptetj�k �s hat�rozzuk meg a kezd� �s v�gpont �rt�keit
	for (int i = 1; i < scale; ++i) {
		y.add(Point(0,unitWidth_y * i), Point(width,unitWidth_y * i));
	}

	x.set_color(Color::black);
	y.set_color(Color::black);

	//meghatarozzuk konstans �rt�kekkel hogy a k�k sz�n� t�glalap melyik cell�ba essen.
	const int POS_RECT_X = 3;
	const int POS_RECT_Y = 4;

	//itt adjuk meg pixelpontosan, hogy az adott cellaba essen, es ki is t�ltse azt.
	//kezd�pontok �rt�kei: cellasz�less�g * cellasz�m.
	//sz�less�g,hossz�s�g= cella sz�less�ge x �s y ir�nyban.
 	Graph_lib::Rectangle R(Point{ unitWidth_x * POS_RECT_X,unitWidth_y * POS_RECT_Y }, unitWidth_x, unitWidth_y);
	R.set_fill_color(Color::blue);

	//letrehozunk egy rectangle t�pus� vektort, amibe majd a t�glalapokat fogjuk belerakni.
	Vector_ref<Graph_lib::Rectangle> R_vector;

	//ebben a ciklusban t�ltj�k fel az R_vectort.
	//a v�g�n hozz� is adjuk az ablakhoz, az egyes elemek sima t�mbindexel�ssel �rhet�ek el.
	for (int i = 0; i < 2; ++i) {
		R_vector.push_back(new Graph_lib::Rectangle(Point{ unitWidth_x * (3-i),unitWidth_y * i }, unitWidth_x, unitWidth_y));
		R_vector[i].set_fill_color(Color::green);
		win.attach(R_vector[i]);
	}

	//meghatarozzuk konstans �rt�kekkel hogy a k�p melyik cell�ba essen.
	const int POS_IMG_X = 2;
	const int POS_IMG_Y = 3;

	//itt adjuk meg pixelpontosan, hogy az adott cellaba essen.
	//kezd�pontok �rt�kei: cellasz�less�g * cellasz�m.
	//sz�less�g,hossz�s�g= cella sz�less�ge x �s y ir�nyban.
	Image unitIMG(Point(unitWidth_x * POS_IMG_X, unitWidth_y * POS_IMG_Y), "unitIMG.jpg");

	
	win.attach(x);
	win.attach(y);
	win.attach(unitIMG);
	win.attach(R);

	win.wait_for_button();// give control to the display engine
}
