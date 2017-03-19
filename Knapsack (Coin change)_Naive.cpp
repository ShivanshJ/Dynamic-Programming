#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;


//Given set of coins of RS. 1, 2 AND 5. Count total ways of making a particular sum with those coins.

//Bottom-up dynamic programming. We subtract a denomination from the total sum.


#include<limits.h>
#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int ar[]={2,5,3,6};				//Coins available
int n=sizeof(ar)/sizeof(ar[0]); //Size of array


int ct=0;
//Function passes the sum/weight and the index for array with coins/weights
int count(int s,int m)
{	
	//Here, m<0 as, if we include the element, then m remains the same
	if(s<0 || m<0)
		return 0;
	
 	if(s==0)
 	{
	 ct++; return 1;
 	}	
 
  // If there are no coins,i.e n=0 and s is greater than 0, then no solution exist
    if (n <=0 && s >= 1)
        return 0;
 
count(s,m-1) ; //Case1: Excluding the element
count(s-ar[m],m) ; //Case2: Including, For any element we can have as many subtractions.. Ex: sum of 5 can give.. 1,1,1,1,1
 return 0;
 
}


int main()
{ 
	int sum;
	cout<<"Enter the sum required to be made: ";
	cin>>sum;
	
	count(sum,n-1);
	
	cout<<"The count is: "<<ct;
	
	return 0;
}	
