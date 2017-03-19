#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
using namespace std;


//.......................................Look at Naive for all comments
#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int weight[]={2,3,4,5,6,7};			//Weight of item
int val[]={3,7,2,9,5,8};			//Value of the items above
int best=0; 

int save[40][5]={0}; 
//Save array, here it is taken in the form f save[total weight][index] as shown in the recursion tree
// http://www.ideserve.co.in/learn/dynamic-programming-0-1-knapsack-problem
// and then return condition is put : if(save[tot][i]>0 )	return save[tot][i];

int max(int a, int b)
{ return a>b?:a,b;
}

int knap(int tot, int i, int cost)
{ 	
    
	if(tot<0||i<-1)
	return 0;
	
	if(save[tot][i]>0 )
		return save[tot][i];
	

	
	if(i==-1 || tot==0 )
	{ if(cost>best)
		best=cost;
		
		return best;
	}	
	

	
	save[tot][i]=knap(tot,i-1,cost) + knap(tot-weight[i], i-1,cost+val[i]); 
	
	return max(save[i][0],save[i][1]);

}

int main()
{ 	clock_t t;
    t = clock();
    
	int total;
	cout<<"Enter the total weight the thief can carry: ";
	cin>>total;
	
	int n=sizeof(weight)/sizeof(weight[0]); //Size of weight array, as we have to subtract this from total weight
	if(n-1<=0)
	{ cout<<"No items available";
	return 0;
    }
    
	knap(total,n-1,0);
	
	cout<<"The maximum value of things he can carry is :"<<best;
	
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("\nTook %f seconds to execute \n", time_taken);
	return 0;
	return 0;
}	
