#include <iostream>
#include<vector>
#include <string>
#include <stdexcept>
#include <set>
using namespace std;


struct Fruit{
	string name;
	int quantity;
	double unit_price;
	
	Fruit(const string& n, int q=0, double p=0.0): name{n}, quantity{q}, unit_price{p}{}



};


struct Fruit_ptr_cmp{
	bool operator()(const Fruit* a, const Fruit* b){
		return a-> name <b->name;
		//return a->quantity <b->quantity
	
	}
};


int main(){
	try{
	vector <Fruit> vf{
	Fruit{"Plum", 3,},
	Fruit{"Grape", 13,},
	Fruit{"Banana", 73,},
	Fruit{"Apple", 55,},
	Fruit{"cherry", 21,},
	Fruit{"Plum", 3,},
	Fruit{"Kiwi", 99,},};
	
	for (auto& i:vf){cout<<i.name<<endl;}
	cout<<endl;
	set<Fruit*, Fruit_ptr_cmp>sf;
	for (auto& f:vf){
	sf.insert(&f);
	}
	
	for (auto& i:sf){cout<<i->name<<endl;}
	cout<<endl;
	
	
	}catch(exception& e){
	cerr<<e.what()<<endl;
	return 1;
	}catch(...){
	cerr<<"Unknown error"<<endl;
	}

}
