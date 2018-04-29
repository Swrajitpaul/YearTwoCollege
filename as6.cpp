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

   int i,j,k,l;
   typedef char box[5][7];
   box bb,wb,*board[8][8];
   char x = char(219);
   char o = ' ';
   
   box bq = {
   x, x, x, x, x, x, x,
   x, o, x, o, x, o, x,
   x, o, o, o, o, o, x,
   x, x, o, o, o, x, x,
   x, o, o, o, o, o, x,
   };
   
   box wq = {
   o, o, o, o, o, o, o,
   o, x, o, x, o, x, o,
   o, x, x, x, x, x, o,
   o, o, x, x, x, o, o,
   o, x, x, x, x, x, o,
   };
   
   for(i=0;i<5;i++){
      for( j=0;j<7;j++){
         wb[i][j]=' ';
         bb[i][j]=char(219);
     }
   }
   
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
         if((i+j)%2==0){
            if(a[i]==j)
		       board[i][j]=&wq;
		    else 
			   board[i][j]=&wb;
		 }
		 else{
		 	if(a[i]==j)
               board[i][j]=&bq;
			else
		       board[i][j]=&bb;
	     }
      }
		 
   }

   
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<'_';
 cout<<endl;
 // now print the board
 for(i=0;i<8;i++)
 for(k=0;k<5;k++)
 {cout<<" "<<char(179); //print left border
 for(j=0;j<8;j++)
 for(l=0;l<7;l++)
 cout<<(*board[i][j])[k][l];
 cout<<char(179)<<endl; // at end of line print bar and then newline
 }
 //before exiting print lower border
 cout<<" ";
 for(i=0;i<7*8;i++)
 cout<<char(196);
 cout<<endl;
 
 
 
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

