#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


#include<limits.h>

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int sx,sy;
int best=10000; //for best solution, since we need shortest(minimum) distance, hence taking a big number for comparison

int path[5][5]={0}; //Visited nodes, its important so that it doesn't go back the same path or doesn't keep going in cycles

int robo(int ar[5][5], int i, int j ,int ct)
{ 
//Return conditions
if(i>4 || j>4 || i<0 || j<0)
 	return INT_MAX;
 	
 if(ar[i][j]==0 )
 return INT_MAX;
 
 
 if(path[i][j]==1) //When already stepped on that path before
 return INT_MAX;
 
//Accepting condition
	
 path[i][j]=1;	//Marking as visited node
  
	if(i==sx && j==sy)
  	{ 
	  	for(int i=0;i<5;i++)
	   		{	cout<<endl;
	   			for(int j=0;j<5;j++)
	   				cout<<path[i][j];
        	}
        
  	  	path[i][j]=0; //Before returning, necessary to unmark the final node we just encountered
  	 	cout<<endl;
  	 	 
		if(best>ct)
		   best=ct;
		   
	   	 return ct; //can return any value as there is no use of value being returned
	   
	   }
//	Recursion   

//NOTE : I WASTED MANY DAYS BECAUSE OF ct++ and not ct+1
robo(ar, i,j-1 , ct+1);
robo(ar, i-1,j , ct+1) ;
robo(ar, i,j+1 , ct+1);
robo(ar, i+1,j , ct+1) ;

/*
robo(ar, i-1,j-1 , ct+1) ;
robo(ar, i+1,j+1 , ct+1) ; Incase of diagnols */ 

//Go back
//Its gonna go back anyway with return statement, unmark visited nodes while at it
path[i][j]=0;
return 1;
}

int main()
{	int ar[5][5]= { {1,1,1,1,0},
					{0,0,0,1,0},
					{1,1,1,1,1},
					{1,0,0,1,0},
					{1,1,1,1,1}};
	
	cout<<"Enter starting point: \n";
	cin>>sx>>sy;
	if( robo(ar,4,4,0) < INT_MAX ) ;
	cout<<"Shortest path is: "<<best;
	return 0;
	
	
}
/*Note 1: for only printing the shortest path, check out https://thetokenizer.com/2013/01/13/practicing-backtracking/
NOte 2: Change path to 3d matrix. such that each 2d matrix is inside one of its dimensions, then print


/*EXPLANATION:
	
	
	This does not contain the form : ct + min(func() + func() + ...) as many combinations are made in this. Heavy computation.
	
	func(i+1 ,ct+1) ; func(i-1 ,ct+1) ...; 
	This form is used so that return value does not affect any value. Hence whether its return INT_MAX or return 1, its 
	the same as the count is being incremented in the function alone.
	func() is only used to traverse in all possible ways.
	
	
	First conditions:
		->Check reject conditions, i.e, when traversal has to be stopped.
		
		->Check accept condition, i.e, when it reaches start node.
		
		->We make a visited node otherwise if visited node is not there, the traversal might continue in a square cycle
		Also if visited node not there, then if cycle is not made, the following can happen. Example:-
		
		robo(ar, i+1,j , ct+1);
		robo(ar, i-1,j , ct+1) ;
		..
		..
		In this first, it goes upward till block is encountered, i.e,
		0000
		0001
		0001
		0001
		
		Acc. to program it first looks for robo(i+1), i.e, blocked. Then looks for robo(i-1), and
		then comes back down the same path without seeing that it has already gone through that, thus increasing steps.
		It can directly return INT_MAX by seeing path is already visited without creating more trees under the same recursion.
		
		
		->At the end we write conditions for recursion,i.e, robo(i+1,ct+1) ,etc.
		
		
		->Then considering that we reached the final destination, we unmark nodes as after we reach we return a value to come back the path.
		While coming back , which will happen anyway we unmark the nodes.
		
		
*/
