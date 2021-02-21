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
	Graph_lib::Point tl{ 500,100 };// to become top left corner of window

	Simple_window win{ tl,1280,800,"Test" };// make a simple window

	Axis xa{ Axis::x, Point{20,300}, 280, 10, "x axis" };
	Axis ya{ Axis::y, Point{20,300}, 280, 10, "y axis" };
	
	Function sine{ sin,0,100,Point{20,150},1000,50,50 };
	Graph_lib::Rectangle r{ Point{200,150}, 150, 100 };

	Text t{ Point{150,150}, "Hello, graphical world!" };
	Image ii{ Point{100,50},"mehecske.jpg" };
	
	xa.set_color(Color::black);
	ya.set_color(Color::black);
	sine.set_color(Color::blue);
	r.set_color(Color::red);
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 2));
	
	Graph_lib::Polygon poly;// make a shape (a polygon)
	Graph_lib::Circle c(Point{ 100,100 }, 50);

	
	poly.add(Point{ 300,200 });// add a point
	poly.add(Point{ 350,100 });// add another point
	poly.add(Point{ 400,200 });// add a third point
	poly.add(Point{ 500,300 });// add a fourth point
	poly.add(Point{ 600,200 });// add a fourth point

	poly.set_color(Color::yellow);// adjust properties of poly
	poly.set_fill_color(Color::green);

	win.attach(ii);
	win.attach(poly);// connect poly to the window
	win.attach(c);
	win.attach(xa);
	win.attach(ya);
	win.attach(r);
	win.attach(sine);
	win.attach(t);
	
	
	win.wait_for_button();
	
	return 0;
}
