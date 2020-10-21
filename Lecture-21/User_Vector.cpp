// User_Vector
#include <iostream>
using namespace std;

class Vector{
public:
	int *arr;
	int ms;
	int cs;
	Vector(int s = 2){
		arr = new int[s];
		ms = s;
		cs = 0;
	}

	void push_back(int data){
		if(cs == ms){
			int *oldarr = arr;
			int oldms = ms;
			arr = new int[2*ms];
			ms = 2*ms;
			for(int i = 0 ; i < cs ; i++){
				arr[i] = oldarr[i];
			}
			delete []oldarr;
		}
		arr[cs++] = data;
	}

	void pop_back(){
		if(cs==0){
			return;
		}
		cs--;
	}

	int size(){
		return cs;
	}

	int capacity(){
		return ms;
	}

	int operator[](int i){
		return arr[i];
	}
};

int main(){
	
	Vector v;

	for(int i = 0 ; i < 5 ; i++){
		v.push_back(i);
	}

	for(int i = 0 ; i < v.size() ; i++){
		cout<<v[i]<<' ';
	}
	cout<<endl;

	cout<<"Size : "<<v.size()<<endl;
	cout<<"Capacity : "<<v.capacity()<<endl;

	cout<<endl;
	return 0;
}