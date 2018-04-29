
// another way
#include <iostream>
using namespace std;
int main(){
int i,j,k,l;
char c=' ';
for( i=0; i<8; i++)
for(k=0;k<5; k++)
{for(j=0; j<8; j++) // print a whole row across
{if((i+j)%2==0)
c=' ';
else
c=char(219);
for(l=0; l<7;l++)
cout<<c;
}
cout<<endl; // now move to the next line
}
}
