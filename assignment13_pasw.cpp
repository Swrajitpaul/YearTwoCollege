#include <iostream>
#include <cstdlib>
using namespace std;

bool test(int *a[], int C) {
   for (int i=0; i< C; ++i) 
      if (a[i] == a[C] || (C-i) == abs(a[C]-a[i])) {
         return false;
      }
   return true;
}


void backTrack(int &col) {
    --col;
}

int main() {
   int n;
   cout << "number of queens: ";
   cin >> n;
   
for (int i = 1; i <=n; i++) {
   int *q = new int[i];
   q[0]=1;
   int counter= -1;
   int c=0;
    
   while (true) {
      c++;
      if (c==8) {
         backTrack(c);
      }
      else q[c]= -1;
        
      while (true) {
         q[c]++;
         if(q[c]==8){
            backTrack(c);
            if(c== -1) {
               return 0;
            }
            continue;    
         }
            
         if (test(q,c)) {
            break;
         }
      }
   }
   delete []q;
   cout << "There are" << counter << "solutions to the" << i << " queen(s) problem" << endl;
}
   return 0;
}

