#include <iostream>
using namespace std;

typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b);
double line(double x);
double square(double x);
double cube(double x);


int main(){
	cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl; 
	cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl; 
	cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
	
	return 0;
}

double integrate(FUNC f, double a, double b){
	double value = 0.0;
	for(double x=a; x<b; x=(x+.0001)){
		value = value + (f(x)* .0001);
		
	}
	return value;
}
double line(double x) {
	return x;
}

double square(double x){ 
	return x*x; 
}

double cube(double x){
	return x*x*x; 
}
