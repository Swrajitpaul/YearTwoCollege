#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


bool ok(int q[], int col){//method returns true if a queen can go in the spot. returns false if it cant
    for(int i=0; i<col; i++)
    if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
    return false;
    return true;
};//end of ok
//I took out the backtrack function, since it made things more complicated. instead the contents are used, and the program breaks out of the loop if the column ever reaches -1

int main(){
    int n;
    cout<<"How Many Queens? ";
    cin>>n;
    
    for (int i = 1; i <= n; ++i) {
        int *q = new int[i]; //dynamically allocate array of size i
        q[0]=1;
        int count = -1; //you want to keep track of how many solutions get printed
        int c = 0; //column
        bool from_backtrack=false;//this variable will be used to determine whether the row should be reset to -1 in that column
        
        while(true){//the loop will repeat forever
        
            while(c<i){//this should repeat i times for all the columns
            
                if(!from_backtrack)q[c]=-1;//if this was reached without backtracking then q[c] is set to -1
                from_backtrack=true;
            
                while(q[c]<i){//this loop repeats i times for the rows
                    q[c]++;
                
                    if(q[c]==i){//if it reaches i, then there is no solution, so we go backa  column to fix it
                        from_backtrack=true;
                        c--;
                        break;
                    }//end of if(q[c]==i)
                
                    if(ok(q,c)){//this tests if the spot can have a queen. if it does then we go to the next column
                        from_backtrack=false;
                        c++;
                        break;
                    }//end of if(ok(q,c)
                
                }//end of while(q[c]<i)
                if(c==-1)break;//exit loop if it reaches -1
            }//end of while(c<i)
        count++;
        c--;
        from_backtrack=true;
        if(c<=-1)break;//if its less then -1, then its time to exit the while loop
        
    }//end of while(true)
        delete []q; //free up heap memory taken by q
        cout<<"There is/are "<<count<<" solution(s) to the "<< i <<" Queen(s) problem."<<endl;
    
  }//end of for loop
    return 0;
}//end of main()
