#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)


int mina(int a , int b)
{ 
return a<b?a:b;

}

void  fx(int m , int n , int **ar)
{
	
	int cost[m][n];
	cost[0][0]=ar[0][0];
	
	F(j,1,n)
	 {
	 
	 	cost[0][j]=cost[0][j-1] + ar[0][j];
	 
	 }
		
	 F(j,1,m)
	 {
	  
	 	cost[j][0]=cost[j-1][0] + ar[j][0];
	 
	 }
		
	F(i,1,m)
	{ F(j,1,n)
		{   
		
		
			cost[i][j]= mina(cost[i-1][j] , cost[i][j-1]) + ar[i][j];
		}
	}
	
	
	cout<<cost[m-1][n-1];
}

int main()
{ int m,n;
 cout<<"Enter row and column: \n";
 cin>>m>>n;


	int **ar=(int **)malloc(m*sizeof(int *));
	F(i,0,n)
	{
		ar[i]= (int *)malloc(m*n*sizeof(int));
	}
	
	cout<<"Enter cost of each point in matrix\n";
	F(i,0,m)
	{ F(j,0,n)
		cin>>ar[i][j];
		
	}
	
	/*int ch=1;
	while(ch)
	{int x,y;
	cout<<"Enter position  position: \n";
	cin>>x>>y;
	cout<<"Want more walls? 1 for yes, 0 for no  :   ";
	cin>>ch;
	ar[x][y]=0;
	}*/
	
	
	cout<<endl<<"Matrix is: \n";
	F(i,0,m)
	{ F(j,0,n)
		{
		cout<<ar[i][j]<<"  ";}
		cout<<endl;
	}
cout<<endl;
	

	cout<<"Minimum Cost is: ";
	fx(m,n,ar);

return 0;
}
