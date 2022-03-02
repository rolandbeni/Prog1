#include "GUI/Graph.h"
#include"GUI/Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try{
	
		Point t1{300, 50};
		Simple_window win(t1, 1000, 800, "My_window");
		win.wait_for_button();
		int x_size=800;
		int y_size=800;
		Lines grid;
		
		
		for (int i=0; i<=800; i+=100)
		{
		grid.add(Point(i, 0), Point(i, y_size));
		grid.add(Point(0, i), Point(x_size, i ));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		Rectangle r {Point{0, 0}, 100, 100 };
			win.attach(r);
			r.set_fill_color (Color::red);
		Rectangle a {Point{100, 100}, 100, 100 };
			win.attach(a);
			a.set_fill_color (Color::red);
		Rectangle s {Point{200, 200}, 100, 100 };
			win.attach(s);
			s.set_fill_color (Color::red);
		Rectangle d {Point{300, 300}, 100, 100 };
			win.attach(d);
			d.set_fill_color (Color::red);
		Rectangle f {Point{400, 400}, 100, 100 };
			win.attach(f);
			f.set_fill_color (Color::red);
		Rectangle g{Point{500, 500}, 100, 100 };
			win.attach(g);
			g.set_fill_color (Color::red);
		Rectangle h{Point{600, 600}, 100, 100 };
			win.attach(h);
			h.set_fill_color (Color::red);
		Rectangle j {Point{700, 700}, 100, 100 };
			win.attach(j);
			j.set_fill_color (Color::red);
		/*
		for (int i=0; i<=8; i++)
			{Rectangle r {Point{i*100, i*100}, 100, 100 };
			win.attach(r);
			r.set_fill_color (Color::cyan);
			win.wait_for_button();
			}*/
		win.wait_for_button();
		
		int c=700;
		int b=0;
		
		Image ii {Point(800,600),"badge.jpg"};
		ii.set_mask(Point(100,50), 200, 200);
		win.attach(ii);
		win.wait_for_button();
		
		for (int i=0; i<=8; i++){
		Image kk {Point(c-i*100,b+i*100),"badge.jpg"};
		kk.set_mask(Point(100,100), 100, 100);
		win.attach(kk);
		win.wait_for_button();}


	
	}catch (exception& e){
	cerr <<"exception: "<<e.what()<<'\n';
	return 1;

	}catch (...){
	cerr<<"error\n";
	return 2;
	}

}
