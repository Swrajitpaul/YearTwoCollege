#include <iostream>
using namespace std;

bool leapYear (int y){
	if ((y%4==0 && y%100 !=0) || y%400 ==0) {
		return true;
	}
	return false;
}
int main() {
	int y;
	cout<< "enter a year";
	cout << endl;
	cin >> y;
	while (leapYear(y) != true){
	   if (leapYear(y)==true){
		   cout<< "the year is a leap year!";
	   }
	   cout << "enter a year again please" << endl;
       cin >> y;
    }
    
	return 0;
}
