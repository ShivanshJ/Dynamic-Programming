#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#include <limits.h> //For using INT_MAX
#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int best=INT_MAX;
void fx(int m , int n , int **ar, int cost)
{ 
	//Return condition
	 if (n < 0 || m < 0 || ar[m][n]==0)  //IF WALL CONDITION NOT THERE, REMOVE AR[M][N]==0 part
      return;
    //Accept condition
	if(m==0 && n==0)
	{	cost+=ar[m][n];
		if(cost<best)
			best=cost;
		return;
	}
	//Recursive function
	else 
	{
		fx(m-1,n,ar,cost+ ar[m][n]); 
		fx(m,n-1,ar,cost+ ar[m][n]); 
		fx(m-1,n-1,ar, cost+ ar[m][n]);	
	}
	return;
}

int main()
{ int m,n;
 cout<<"Enter row and column: \n";
 cin>>m>>n;

//Dynamic initialization of 2d array
	int **ar=(int **)malloc(m*sizeof(int *));
	F(i,0,n)
	{
		ar[i]= (int *)malloc(m*n*sizeof(int));
	}
//Taking input
	cout<<"Enter cost of each point in matrix and walls as 0\n";
	F(i,0,m)
	{ F(j,0,n)
		cin>>ar[i][j];
		
	}
//Printing the matrix	
	cout<<endl<<"Matrix is: \n";
	F(i,0,m)
	{ F(j,0,n)
		{
		cout<<ar[i][j]<<"  ";}
		cout<<endl;
	}
cout<<endl;
//Final result
	cout<<"Minimum Cost is: ";
	fx(m-1,n-1,ar, 0);
	cout<<endl<<best;

return 0;
}
/* Another approach for recursion, this doesn't need: global variable best, 'int cost' in void fx(.. , .. , .. )

int min(int x, int y, int z)
{ if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

void fx(int m , int n , int **ar)
{ 
	 if (n < 0 || m < 0 || ar[m][n]==0)  //IF WALL CONDITION NOT THERE, REMOVE AR[M][N]==0 part
      return;
      
	if(m==0 && n==0)
		return ar[m][n];
	else 
	{	return ar[m][n] + min ( fx(m-1,n,ar), 
		fx(m,n-1,ar),
		fx(m-1,n-1,ar );	
	}
	return;
}

*/
