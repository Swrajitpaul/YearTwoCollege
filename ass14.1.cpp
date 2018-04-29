#include <iostream>
#include <cstdlib>
using namespace std;

bool test(int a[3], int c) {
   static int mp[3][3] ={{0,2,1},{0,2,1},{1,2,0}};
   static int wp[3][3] ={{2,1,0},{0,1,2},{2,0,1}};

   int newMan = c;
   int newWoman= a[c];

   for (int i=0; i< c; ++i){ 
      if (a[i] == a[c]) {
         return false;
      }
      int currentMan = i;
      int currentWoman = a[i];     
      if (mp[i][a[c]] < mp[i][a[i]] && wp[a[c]][i] < wp[a[c]][c]){
	 return false;
      }
   }
   return true;
}

void print (int a[]) {
   static int counter =0;
   cout << "Solution " << ++counter <<endl;

   for (int i=0; i<3; i++) 
      cout<< a[i];
   cout << endl;
}


void shift(int* q, int c){ 
      if (c==3) {
         print(q);
         return;
      }

	for(int j=0; j<3; j++){
		q[c]=j;
		if (test(q,c)) {
            shift(q, c+1);
         }
      }
}
int main() {
	int Array[3];
	Array[0]=0;
    int c=0;
    shift(Array, c);
    return 0;
}
