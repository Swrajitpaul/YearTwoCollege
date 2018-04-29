#include <iostream>
#include <cstdlib>
using namespace std;

bool test(int a[8], int C) {
   for (int i=0; i< C; ++i) 
      if (a[i] == a[C] || (C-i) == abs(a[C]-a[i])) {
         return false;
      }
   return true;
}

void print (int a[], int c) {
   cout << "#" << c << "." << endl;    
   for (int i=0; i<8; i++) {
      for (int j=0; j<8; j++) {
         if(a[i]==j) 
            cout << "Q";
         else 
            cout << "O";
      }
      cout << endl;
   }
   cout << endl;
}

void backTrack(int &col) {
    --col;
}

int main(){ 
   int q[8]={0};
   int counter=1;
   int c=0;
    
   while (true) {
      c++;
      if (c==8) {
         print(q, counter++);
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
   return 0;
}
