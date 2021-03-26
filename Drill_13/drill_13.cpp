/*
    g++ drill_13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill_13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


int main()
try{
    using namespace Graph_lib;

    constexpr int xmax = 800;
    constexpr int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Ez_egy_ablak"};

    constexpr int grid_size = 100;
    constexpr int grid_max = 800;

    Lines grid;
    for (int xy = grid_size; xy <= grid_max; xy += grid_size)
    {
    	grid.add(Point{xy,0}, Point{xy, grid_max});
    	grid.add(Point{0,xy}, Point{grid_max, xy});
    }

    win.attach(grid);

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < grid_max; i += grid_size)
    {
        rects.push_back(new Rectangle{Point{i,i}, Point{i + grid_size, i + grid_size}});
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }


    Image pics1 {Point{0,500}, "pics13.jpg"};
    Image pics2 {Point{300,600}, "pics13.jpg"};
    Image pics3 {Point{600,300}, "pics13.jpg"};

    win.attach(pics1);
    win.attach(pics2);
    win.attach(pics3);

    Image pics4 {Point {0,0}, "gif13.gif"};
    win.attach(pics4);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 ; j++)
        {
            win.wait_for_button();
            if (j < 7) pics4.move(100,0);
            else pics4.move(-700,100);
        }
    }

    win.wait_for_button();
}
catch(exception& e)
{
    cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch(...)
{
    cerr << "error\n";
	return 2;
}
