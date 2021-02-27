/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
try{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "My"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	//---Függvények---
	//Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	//Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};



	Rectangle r {Point{338,200}, 220, 145};
	r.set_fill_color(Color::green);
	r.set_style(Line_style(Line_style::dash, 4));
	r.set_color(Color::black);


	Closed_polyline repulo;
	repulo.add(Point{320,50});
	repulo.add(Point{440,50});
	repulo.add(Point{500,100});
	repulo.add(Point{300,100});
	repulo.add(Point{250,30});
	repulo.set_fill_color(Color::white);

	Closed_polyline szarny;
	szarny.add(Point{360,75});
	szarny.add(Point{400,75});
	szarny.add(Point{390,95});
	szarny.add(Point{320,120});
	szarny.set_fill_color(Color::blue);

	Polygon haromszog;
	haromszog.add(Point{560,200});
	haromszog.add(Point{450,130});
	haromszog.add(Point{330,200});

	haromszog.set_color(Color::yellow);
	haromszog.set_style(Line_style::dash);
	haromszog.set_fill_color(Color::red);

	
	

	Text t {Point{195,380}, "Welcome buddy!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	t.set_color(Color::red);

	Image pic {Point{0,0}, "background.jpg"};
	Image run {Point{70,160}, "runnin.gif"};

	Circle c {Point{40,40}, 100};
	c.set_color(Color::yellow);
	c.set_fill_color(Color::yellow);



	win.attach(pic);
	win.attach(repulo);
	win.attach(szarny);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(haromszog);
	//win.attach(s);
	//win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);
	win.attach(run);
	

    win.wait_for_button();

}
catch(exception& e)
{
	return 1;
}
catch(...)
{
	return 2;
}
