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

void backTrack(int &col) { 
   --col;
   if(col== -1) exit(1);
}

int main(){ 
   int Array[3];
   int c=0;
   Array[0]=0;
   bool reset = false;
    
   while (true) {
      c++;
      if (c==3) {
         reset = true;
         print(Array);
         backTrack(c);
      }
      
      if(!reset) 
         Array[c]= -1;
         reset = false;

      while (true) {
         Array[c]++;
         if(Array[c]==3){
            backTrack(c);   
         }
            
         else if (test(Array,c)) {
            break;
         }
      }
   }
   return 0;
}
