/* 
g++ d3.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o d3 `fltk-config --ldflags --use-images`
*/

//#include "./GUI/Simple_window.h"
//#include "./GUI/Graph.h"

#include <string>
#include <iostream>
//using namespace Graph_lib;
using namespace std;

class B1{
	public:
		virtual void vf(){cout<<"B1::vf()"<<endl;}
		void f() {cout<<"B1::f()"<<endl;}
		virtual void pvf()=0;
};

class D1:public B1{
	public:
		void vf(){cout<<"D1::vf()"<<endl;}
};
class D2: public D1{
	public:
	void pvf(){cout<<"D2::pvf()"<<endl;}

};

class B2 {
	public:
		virtual void pvf()=0;

};
class D21:public B2{
	public:
		string s;
		void pvf(){cout<< s<<endl;}

};
class D22:public B2{
	public:
		int n;
		void pvf(){cout<<n<<endl;}
};

void f(B2& b2ref){
	b2ref.pvf();
}


int main(){
	try{
	/*B1 b1;
	b1.vf();
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f();
	
	B1& bref=d1;
	bref.vf();
	bref.f();*/
	
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	d21.s="d21.s";
	d21.pvf();
	
	D22 d22;
	d22.n=3;
	d22.pvf();
	
	f(d21);
	f(d22);





}catch (exception& e){
cerr <<"exception: "<<e.what()<<'\n';
return 1;

}catch (...){
cerr<<"error\n";
return 2;
}

}
