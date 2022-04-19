#include<iostream>
//#include<iomainip>
#include<cmath>
#include<complex>
#include<cerrno>
#include"Matrix.h"
#include"MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main(){
	try{
		cout<<"sizeof:\n";
		cout<<"char\t"<<sizeof(char)<<endl;
		cout<<"short\t"<<sizeof(short)<<endl;
		cout<<"int\t"<<sizeof(int)<<endl;
		cout<<"long\t"<<sizeof(long)<<endl;
		cout<<"float\t"<<sizeof(float)<<endl;
		cout<<"double\t"<<sizeof(double)<<endl;
		cout<<"int*\t"<<sizeof(int*)<<endl;
		cout<<"double*\t"<<sizeof(double*)<<endl;
		
		cout<<"Matrix sizes\n";
		Matrix<int>a(10);
		Matrix <int>b(100);
		Matrix <double>c(10);
		Matrix <int, 2>d(10, 10);
		Matrix <int, 3>e(10,10,10);
		cout<< "ID int 10 elem\t"<<sizeof(a)<<endl;
		cout<< "ID int 100 elem\t"<<sizeof(b)<<endl;
		cout<< "ID double 10 elem\t"<<sizeof(c)<<endl;
		cout<< "ID int 10*10 elem\t"<<sizeof(d)<<endl;
		cout<< "ID int 10*10*10 elem\t"<<sizeof(e)<<endl;
	
		cout<<"Number of elements:\n";
		cout<<"a:\t"<<a.size()<<endl;
		cout<<"b:\t"<<b.size()<<endl;
		cout<<"c:\t"<<c.size()<<endl;
		cout<<"d:\t"<<d.size()<<endl;
		cout<<"e:\t"<<e.size()<<endl;
		
		int x;
		while (cin>>x){
		if (x>=0){
			cout<<sqrt(x);
		}else{cout<< "no square root"<<endl;}}
		
		cin.clear();
		cin.ignore();
		cout<<"\nEnter 10 floats: "<<endl;
		Matrix<double> m(10);
		double d2;
		for (int i=0; i<m.size(); i++)
		{cin>>d2;
		if(!cin)throw runtime_error("error while reading from cin");	
		m[i]=d2;}
		
		
		cout<<"Mátrix:\n"<<m<<endl;
		int n;
		int y;
		cout<<"\nAdj meg 2 indexet:\n";
		cin>>n;
		cin>>y;
		Matrix <int, 2> dd(n, y);
		if (n>0 and y>0){
		
		
		for (int i=1; i<=n; i++){
			for (int q=1; q<=y; q++){
			dd( i-1, q-1)=i*q;
			}
		}
		}
		cout<<"Szorzó tábla:\n"<<dd<<endl;
		
		
		Matrix <complex<double>> m4(10);
		cout<<"\nenter 10 complex numbers (Re, Im): ";
		complex<double>comp;
		for (int i=0; i<10; i++){
		cin>>comp;
		if(!cin)throw runtime_error("Problem reading complex nums!");
		m4[i]=comp;
		}
		
		complex<double>sum;
		for (Index i=0; i<m4.size(); i++){
			sum+=m4[i];
		}
		cout<<"Összeg: "<<sum<<endl;
		//(1,1) (1,1) (1,1) (1,1) (1,1) (1,1) (1,1) (1,1) (1,1) (1,1) 
		
		cout<<"adj meg 6 számot\n";
		int mam;
		Matrix<int, 2> m5(2,3);
		for (int i=0; i<2; i++){
			for (int y=0; y<3; y++){
				cin>>mam;
				m5(i, y)=mam;
		}
		}
		
		cout<<m5<<endl;
		
		
		
		
		
		
		
		
		
	}catch (exception& e){
		cerr<<"Exception: "<<e.what()<<endl;
	}catch(...){
		cerr<<"unknown exception!"<< endl;
		}
}










































