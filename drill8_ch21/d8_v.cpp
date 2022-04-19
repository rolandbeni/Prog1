#include <iostream>
#include<stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

template<typename C>
void print (const C& c, char sep='\n'){
	cout<<"Container elements:"<<endl;
	for (const auto elem:c){cout<<elem<<sep;}
}

int main(){
	try{
	const string iname{"inputf.txt"};
	ifstream ifs {iname};
	vector<double > vd;
	
	for (double d; ifs>>d;)
	{vd.push_back(d);}
	print(vd);
	
	
	vector<int> vi;
	for(auto& d: vd){
		vi.push_back(d);
	}
	//copy(vd.begin(), vd.end(), vi.begin());
	print(vi);

	for (int i=0; i<vd.size(); i++){
	cout<< vd[i]<< '\t'<<vi[i]<<endl;
	
	}
	
	double osz=0;
	for (auto& i: vd){
		osz=osz+i;
	}
	double oss=0;
	for (auto& i: vi){
		oss=oss+i;
	}
	cout<<"vd összege: "<<osz<<", vi összege: "<<oss<<", A kettő különbsége: "<<osz-oss<<endl;
	
	reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean=osz/vd.size();
	cout<<vd_mean<<endl;
	vector<double>vd2;
	for (auto& i:vd){
	if (i<vd_mean)
		vd2.push_back(i);
	}
	
	print(vd2);
	
	sort(vd.begin(), vd.end());
	print(vd);
	
	
}catch (exception& e){
cerr <<"exception: "<<e.what()<<'\n';
return 1;

}catch (...){
cerr<<"error\n";
return 2;
}

}
