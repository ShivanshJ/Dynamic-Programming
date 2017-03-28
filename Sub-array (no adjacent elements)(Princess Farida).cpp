#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//Subset Sum Problem
//Can the set of numbers be divided into two sets with equal weights

//Explanation: http://www.ideserve.co.in/learn/set-partition-problem-recursion

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int mon[]={5,2,1,10,7,3};
int best=0;

int mx(int a, int b)
{ return a>b?a:b ;
}

void gold(int n, int sum)
{  
	if(n<-2)
	return;
	
	
	//Base cases
	//Note: n==-2, since last element will be added only when gold(0-2,sum+mon[0])
	if(n==-2 || n==-1 )
	{	if(best < sum)
			best=sum;
		return;
	}
	
	gold(n-2,sum+mon[n]);	//Case1: Include, then go down by two, cuz no adjacent
	gold(n-1,sum); 			//Case2: Exclude, then shift by 1;
	
	
	return;
}

int main()
{	int n=sizeof(mon)/sizeof(mon[0]);
	gold(n-1,0);
	cout<<best;
	return 0;
}
