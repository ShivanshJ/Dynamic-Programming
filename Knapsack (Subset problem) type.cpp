#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//Subset Sum Problem
//Can the set of numbers be divided into two sets with equal weights

//Explanation: http://www.ideserve.co.in/learn/set-partition-problem-recursion

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int path[256]={0};
int found=0;

int part(int *ar, int sum,int i, int k)
{ 	
	//i<-1, so that last element can run properly, i.e, when part(ar,sum-ar[0],0-1,k+1)
	if(i<-1 || sum<0)
	return 0;
	
//	cout<<sum<<endl;
	
	path[k]=ar[i];
	
	if(sum==0)
	{	found=1;
	    cout<<"Path is:";
		F(j,0,k)
		cout<<path[j]<<" ";
		
		cout<<endl;
		return 1;
	}
	
	
	//NOTE: Order is important
	part(ar,sum-ar[i], i-1, k+1);	//Case 2: Including the element[Only once (thus i-1) ] 
	part(ar,sum,i-1, k); 			//Case 1: Excluding the element
			
				//In knapsack, coin change .case 2 does not have the "i-1" , part as it does recursion for the same element many times
				//Here, one element can be subtracted only once			
return 0;
}

bool check(int *ar,int sum, int index)
{ if(sum%2!=0)
	return false;
	
	
	
    part(ar,sum/2,index,0);
    if(found==1)
	return true;
	
	return false;
}

int main()
{ int ar[]={2,5,8,5};

int n=sizeof(ar)/sizeof(ar[0]);
int sum=0;

F(i,0,n)
sum+=ar[i];

if( check(ar,sum,n-1)	)	
cout<<endl<<"Yes";

else cout<<"No";

return 0;
}
