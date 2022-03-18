/* 
g++ d42.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o d42 `fltk-config --ldflags --use-images`
*/


#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;


double one(double x) { return 1;};
double slope (double x){return x/2;};
double square (double x){return x*x;};
double sloping_cos(double x) {return cos(x) + slope(x);};
int main(){
	try{
		Point o (300, 300 );
		Point t1 {100, 100};
		Simple_window win {t1, 600, 600, "Function graphs"};
		win.wait_for_button();
		
		Axis xa {Axis::x, o, 400, 20, "x_axis"};
		xa.set_color (Color::red);
		win.attach(xa);
		win.set_label("1 = = 20 pixels");
		win.wait_for_button();

		Axis ya{ Axis::y, o, 400,20, "y_axis"};
		ya.set_color (Color::red);
		win.attach(ya);
		win.set_label("1 = = 20 pixels");
		win.wait_for_button();
		
		int n_points = 400;
    		int r_min=-10, r_max=11;
    		int sx=20;
    		int sy=20;
  		Function l{one,r_min,r_max, o ,n_points,20,20};
		win.attach(l);
		win.wait_for_button();
		
		Function s{slope,r_min,r_max, o ,n_points,20,20};
		win.attach(s);
		Text ts {Point{s.point(0).x,s.point(0).y - 20},"x/2"};
		win.attach(ts);
		win.wait_for_button();
		
		Function p{square,r_min,r_max, o ,n_points,20,20};
		win.attach(p);
		win.wait_for_button();
		
		Function cs{cos,r_min,r_max, o ,n_points,20,20};
		win.attach(cs);
		win.wait_for_button();
		
		Function scs{sloping_cos,r_min,r_max, o ,n_points,20,20};
		win.attach(scs);
		win.wait_for_button();


}catch (exception& e){
cerr <<"exception: "<<e.what()<<'\n';
return 1;

}catch (...){
cerr<<"error\n";
return 2;
}

}
