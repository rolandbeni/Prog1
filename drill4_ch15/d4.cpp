#include <string>
#include <iostream>
#include <stdexcept>
#include<vector>
using namespace std;

void correct(string name){
	string v=";:\"'[]*&^%$#@!";
	for (int i=0; i<v.size(); i++){
		for (int x=0; x<name.size(); x++){if (v[i]==name[x]){
			throw runtime_error("invalid name");
			}
		}
		
	}

}

class Person{
	public:
		Person(){};
		//Person (string n, int a):n{n}, a{a}{
		Person (string f, string l, int a): f{f}, l{l}, a{a}{
			if(a<0 || a>150){throw runtime_error("invalid age");}
			string n=f+l;
			correct(n);
			};
		string first() const {return f;}
		string last() const {return l;}
		int age() const {return a;}
		
	private:
		string f;
		string l;
		//string n;
		int a;
	
	
};
ostream& operator<<(ostream& os, const Person& p){
	//return os<<p.name()<<" "<<p.age();
	return os<<p.first()<<" "<<p.last()<<" "<<p.age();
}
istream& operator>>(istream& is,  Person& p){
	//string n;
	string f;
	string l;
	int a;
	//is>>n>>a;
	is >>f>>l>>a;
	p=Person (f, l, a);
	return is;
}	


int main(){
	Person p;
	//p.n="Goofy";
	//p.a=63;
	p=Person("Sir", "Goofy", 63);
	
	cout<<p.first()<<" "<<p.last()<<" is "<<p.age()<<" years old"<<std::endl;
	Person p2;
	cin>>p2;
	cout<<p2<<endl;

	vector <Person> vec;
	for (Person p; cin >>p;){
		if (p.first()+p.last()=="end") break;
		vec.push_back(p);
	
	}
	
	for (Person p: vec){
		cout<<p<<endl;
	}
}
