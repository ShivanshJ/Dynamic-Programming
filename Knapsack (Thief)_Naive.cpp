#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
using namespace std;


//Given max weight thief can carry. Weights of the items he is stealing. Value of those items. 
//Find maximum of these values

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int weight[]={2,3,4,5,6,7};			//Weight of item
int val[]={3,7,2,9,5,8};			//Value of the items above
int best=0; 

void knap(int tot, int i, int cost)
{ 

	//NOTE : WE HAVE TO PUT REJECT CASE AFTER ACCEPT AS OTHERWISE LAST VALUE WON'T COMPUTE, i.e, 
			//for weight[0], wont be included
	
	if(tot<0||i<-1)
	return;


	

	//NOTE: it is i=-1 so that i=0 pulls of.. i-1, cost+weight[0];
	if(i==-1 || tot==0 ) //Even if total is not 0, and last item then also we see the result
	{ if(cost>best)
		best=cost;

		return;
	}	
	
	
	
//NOTE: The order is important
	
	knap(tot,i-1,cost);					//Case2: Excluding element, Item not included

	knap(tot-weight[i],i-1,cost+val[i]);	//Case1: Including only once, Item included
	
//Not like coin change where each item can be taken more than once, IF item chosen, then also index -1.. In coin: index remains.
	

	return;

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
}	
