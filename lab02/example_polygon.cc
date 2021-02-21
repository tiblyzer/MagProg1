/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
	//using namespace Graph_lib;
	//ablak kezdopontjainak megadasa: x,y
	Graph_lib::Point tl{ 500,100 };// to become top left corner of window
	
	//ablak parameterei
	Simple_window win{ tl,1280,800,"Test" };// make a simple window

	//poligon példányosítása
	Graph_lib::Polygon poly;// make a shape (a polygon)
	
	//sorban megadjuk a töréspontok koordinatait, ezzel definialjuk hany oldala lesz, es honnan.
	//a sorrend mondja meg hogy jonnek a pontok.
	poly.add(Point{ 300,200 });// add a point
	poly.add(Point{ 350,100 });// add another point
	poly.add(Point{ 400,200 });// add a third point
	poly.add(Point{ 500,300 });// add a fourth point
	poly.add(Point{ 600,200 });// add a fourth point

	//beallitjuk a a poligon vonalának(keretenek) szinet
	poly.set_color(Color::yellow);// adjust properties of poly
	//beallitjuk a poligon kitoltesi szinet.
	poly.set_fill_color(Color::green);
	
	//hozzacsatoljuk a letrehozott ablakhoz.
	win.attach(poly);// connect poly to the window	
	
	//kirajzoltatjuk a vegeredmenyt
	win.wait_for_button();
	
	return 0;
}
