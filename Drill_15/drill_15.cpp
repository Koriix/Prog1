/*
	g++ drill_15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill_15 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	using namespace Graph_lib;

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	Simple_window win {Point{100,100},xmax,ymax,"Function graphs"};

	Axis x {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	constexpr int range_min = -10;
	constexpr int range_max = 11;

	constexpr int xscale = 20;
	constexpr int yscale = 20;

	constexpr int npoints = 400;

	const Point orig {300,300};

	Function vonalka1 {one, range_min, range_max, orig, npoints, xscale, yscale};
	Function vonalka2 {slope, range_min, range_max, orig, npoints, xscale, yscale};
	Function vonalka3 {[](double x) {return x * x; }, range_min, range_max, orig, npoints, xscale, yscale};
	Function vonalka4 {cos, range_min, range_max, orig, npoints, xscale, yscale};
	vonalka4.set_color(Color::blue);
	Function vonalka5 {[](double x) {return cos(x) + slope(x); }, range_min, range_max, orig, npoints, xscale, yscale};

	win.attach(vonalka1);
	win.attach(vonalka2);
	win.attach(vonalka3);
	win.attach(vonalka4);
	win.attach(vonalka5);
	win.attach(x);
	win.attach(y);	
	win.wait_for_button();
}
