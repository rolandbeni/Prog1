#include <iostream>
#include<map>
#include<stdexcept>
#include <numeric>

using namespace std;

template<typename K, typename V>
void print(const map<K, V>&m){
	
	for(pair<K, V> i:m)
	//for (auto& i:m)
	{cout<<i.first<<'\t'<<i.second<<endl;}
}

void read_map(map<string, int >& m){
	string s;
	int i=0;
	while (m.size()<10){
	cin>>s>>i;
	//m[s]=i;   		//felülírás
	m.insert(make_pair(s, i));   	//nincs felülírás
	}


} 
void sum(map<string, int >& m){
	int s=0;
	//for(pair<K, V> i:m){
	for (auto& i:m){
	s=s+i.second;	}
	cout<<"Összeg: "<<s<<endl;
}

int main (){
	try{
	map<int, string> mis;
	map<string, int>msi;
	msi["a"]=1;
	msi["b"]=3;
	msi["ab"]=7;
	msi["efgh"]=98;
	msi["xy"]=76;
	msi["qw"]=61;
	msi["efh"]=60;
	msi["xc"]=23;
	msi["qwertz"]=11;
	msi["ax"]=1;
	
	cout<<"Msi map: "<<endl;
	print(msi);
	sum(msi);
	msi.erase("a");
	cout<<"Msi map 1 elem törlése után: "<<endl;
	print(msi);
	sum(msi);
	msi.erase(msi.begin(), msi.end());
	cout<<"Msi map teljes törlés után: "<<endl;
	print(msi);
	sum(msi);
	cout<<"Adj meg 10 kulcs-érték párt: "<<endl;
	read_map(msi);
	cout<<"Msi map beolvasás után: "<<endl;
	print(msi);
	sum(msi);
	
	for (pair<string , int> i:msi){
		mis[i.second]=i.first;
	}
	cout<<"mis map:"<<endl;
	print(mis);
	}catch(exception& e){
	cerr<<"Exception: "<<e.what()<<endl;
	return 1;
	
	}catch(...){
	cerr<<"Unknown exception"<<endl;
	return 2;
	}




}
