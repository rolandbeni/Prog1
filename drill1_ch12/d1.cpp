/* 
g++ main.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
try{
Point t1 {100, 100};
Simple_window win {t1, 600, 400, "My window"};
win.wait_for_button();

Axis xa {Axis::x, Point {30, 300}, 280, 10, "x_axis"}; //20ról 30ra
win.attach(xa);
win.set_label("x axis");
win.wait_for_button();

Axis ya{ Axis::y, Point{20, 300}, 280,10, "y_axis"};
ya.set_color (Color::cyan);
//ya.set_label(Color::dark_red);
win.attach(ya);
win.set_label("y axis");
win.wait_for_button();


Polygon poly;
poly.add(Point{300, 200});
poly.add(Point{350, 100});
poly.add(Point{400, 200});

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);
win.set_label("Triangle");
win.wait_for_button();


Function sine {sin,0,100,Point{20,150},1000,50,50}; // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
win.set_label("Canvas #4");
win.wait_for_button();

Rectangle r {Point{200, 200}, 100, 50 };
win.attach(r);
Closed_polyline poly_rect;
poly_rect.add(Point{100, 50});
poly_rect.add(Point{200, 50});
poly_rect.add(Point{200, 100});
poly_rect.add(Point{100, 100});
poly_rect.add(Point{50, 75});
win.attach(poly_rect);
win.set_label("Rectangle");
win.wait_for_button();


r.set_fill_color(Color::yellow);
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::dark_blue); //green-ről dark_blue-ra
win.set_label("colors");
win.wait_for_button();

Text t {Point{150, 150}, "Hello graphical world!"};
t.set_font(Graph_lib::Font::times_bold);
t.set_font_size(20);
win.attach(t);
win.set_label("text");
win.wait_for_button();


t.set_font(Font::times_bold);
t.set_font_size(20);
win.set_label("Canvas #9");
win.wait_for_button();

Image ii {Point(100,50),"badge.jpg"}; // 400*212-pixel jpg
win.attach(ii);
win.set_label("Canvas #10");
win.wait_for_button();

ii.move(100,200);
win.set_label("Canvas #11");
win.wait_for_button();

Circle c {Point{100,200},50};
Ellipse e {Point{100,200}, 75,25};
e.set_color(Color::dark_red);
Mark m {Point(100,200),'x'};
ostringstream oss;
oss << "screen size: " << x_max() << "*" << y_max()
<< "; window size: " << win.x_max() << "*" << win.y_max();
Text sizes {Point{100,20},oss.str()};
Image cal {Point{225,225},"snow_cpp.gif"}; // 320*240-pixel gif
cal.set_mask(Point{50,50},200,150); // display center part of image// 40ről 50re
win.attach(c);
win.attach(m);
win.attach(e);
win.attach(sizes);
win.attach(cal);
win.set_label("Canvas #12");
win.wait_for_button();

}catch (exception& e){
cerr <<"exception: "<<e.what()<<'\n';
return 1;

}catch (...){
cerr<<"error\n";
return 2;
}

}

