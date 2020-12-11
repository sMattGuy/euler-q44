#include <iostream>
#include <cmath>

#define MAX 10000
using namespace std;

int penta(int x){
	int result = 3*x;
	result = result - 1;
	result = result * x;
	result = result / 2;
	return result;
}

bool pentaTest(double x){
	double result = sqrt((24*x)+1);
	result = result + 1;
	result = result / 6;
	if(floor(result) == result){
		return true;
	}
	return false;
}

int main(){
	int pos1 = 0;
	int pos2 = 0;
	int pents[MAX];
	for(int i=0;i<MAX;i++)
		pents[i] = penta(i+1);
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(i==j)
				continue;
			else{
				int add = pents[i] + pents[j];
				int sub = abs(pents[i] - pents[j]);
				if(pentaTest((double)add) && pentaTest((double)sub)){
					pos1 = i;
					pos2 = j;
					int D = abs(pents[i] - pents[j]);
					cout<<"\n\nAnswer:"<<D<<" at positions "<<i<<", "<<j<<endl;
					return 0;
				}
			}
		}
		cout<<"Progress:"<<floor(((double)i/MAX)*100)<<"%\r";
	}
	return 0;
}