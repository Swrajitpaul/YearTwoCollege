 #include <iostream>
 #include <cstdlib>
 #include <cmath>
 
 using namespace std;
 
 bool ok(int q[], int col){//method returns true if a queen can go in the spot. returns false if it cant
     for(int i=0; i<col; i  )
         if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
             return false;
     return true;
 };//end of ok
 
 void backtrack(int &col){
     col--;//this method goes back one column.
     if(col==-1){//If it goes before all the columns, then all solutions have been found so the program ends
         system("PAUSE");
         exit(1);
     }
 };//end of backtrack
 
 void print(int q[]) {
     static int count =0;
     cout<<    count<<endl<<endl;
     //copy and paste the code (from the first void main function)
     //from Dr. Waxman's handout and make changes so that the
     //board printout corresponds to the solution given in the q array
     
     //feel free to use the code below, but do experiment with your own artwork!
     int i,j,k,l;
     typedef char box[5][7];
     box bb,wb,*board[8][8];
     char ws = char(219);
     // "drawing" the crown in black queen box
     box bq =
     {
         ws, ws, ws, ws, ws, ws, ws,
         ws, ' ', ws, ' ', ws, ' ', ws,
         ws, ' ', ' ', ' ', ' ', ' ', ws,
         ws, ' ', ' ', ' ', ' ', ' ', ws,
         ws, ws, ws, ws, ws, ws, ws
     };// end of bq
     
     // "drawing" the crown in white queen box
     box wq =
     {
         ' ', ' ', ' ', ' ', ' ', ' ', ' ',
         ' ', ws, ' ', ws, ' ', ws, ' ',
         ' ', ws, ws, ws, ws, ws, ' ',
         ' ', ws, ws, ws, ws, ws, ' ',
         ' ', ' ', ' ', ' ', ' ', ' ', ' '
     };//end of wq
     for(i=0;i<5;i++  )//create the black boxes
         for( j=0;j<7;j++  )
         {wb[i][j]=' ';
             bb[i][j]=char(219);
         }
     for(i=0;i<8;i++)
         for(j=0;j<8;j++)
             if((i+j)%2==0){//set the board with the white and black tiles in a diagnol pattern. place a queen when appropriate
                 if(q[i]==j){
                     board[i][j]=&wq;
                 } else {
                     board[i][j]=&wb;
                 }
             } else {
                 if(q[i]==j){
                     board[i][j]=&bq;
                 } else {
                    board[i][j]=&bb;
                 }
             }
     
     
     // print the board via the pointers in array board
     // first print upper border
     cout<<" ";
     for(i=0;i<7*8;i++  )
         cout<<'_';
     cout<<endl;
     // now print the board
     for(i=0;i<8;i++ )
         for(k=0;k<5;k++  )
         {cout<<" "<<char(179); //print left border
             for(j=0;j<8;j++  )
                 for(l=0;
                     l<7;l++  )
                     cout<<(*board[i][j])[k][l];
             cout<<char(179)<<endl; // at end of line print bar and then newline
         }
     //before exiting print lower border
     cout<<" ";
     for(i=0;i<7*8;i++
           )
         cout<<char(196);
     cout<<endl;
 
 
 }//end of print
 int main(){
     int q[8]; q[0]=0;
     int c=1;
     
     bool from_backtrack=false;//this variable will be used to determine whether the row should be reset to -1 in that column
     
     while(true){//the loop will repeat forever
         while(c<8){//this should repeat 8 times for all the columns
             
             if(!from_backtrack)q[c]=-1;//if this was reached where baktrack was not called then q[c] is set to -1
             from_backtrack=true;
             
             while(q[c]<8){//this loop repeats 8 times for the rows
                 q[c]  ;
                 
                 if(q[c]==8){//if it reaches 8, then there is no solution, so backtrack is called
                     from_backtrack=true;
                     backtrack(c);
                     break;
                 }//end of if(q[c]==8)
                 
                 if(ok(q,c)){//this tests if the spot can have a queen. if it does then we go to the next column
                     from_backtrack=false;
                     c  ;
                     break;
                 }//end of if(ok(q,c)
                 
             }//end of while(q[c]<8)
             
         }//end of while(c<8)
         print(q);// By this point a solution was reached so we print it
         from_backtrack=true;
         backtrack(c);//now to find other solutions, we backtrack
     }//end of while(true)
     
     
 }//end of main()
