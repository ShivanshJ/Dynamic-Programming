#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#include <limits.h> //For using INT_MAX
#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

/*
Note: In top-down dynamic,
I noticed that the recursions are usually combined with addition operator ( + ),
In this case, since the shortest path is being found, we use the function min() on the three recursions

LOOK AT the other commented approach IN THE NAIVE.cpp file for this code
*/

int save[10][10]={0}; //2D Matrix constructed for saving purposes

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int fx(int m , int n , int **ar, int cost)
{ 
	
	 if (n < 0 || m < 0 || ar[m][n]==0)  //IF WALL CONDITION NOT THERE, REMOVE AR[M][N]==0 part
      return INT_MAX;
      
    if(save[m][n]>0)
    	return save[m][n];
      
	if(m==0 && n==0)
	{	
		
		return ar[m][n];
	}
	else 
	{
		save[m][n]= ar[m][n] + min( fx(m-1,n,ar,cost+ ar[m][n]) , fx(m,n-1,ar,cost+ ar[m][n]) , fx(m-1,n-1,ar, cost+ ar[m][n]) );	
	}
	return save[m][n];
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
	cout<<fx(m-1,n-1,ar, 0);
	

return 0;
}
