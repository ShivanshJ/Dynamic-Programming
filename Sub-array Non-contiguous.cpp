#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)
#define RF(i,a,b) for(int i= (int)(a) ; i > (int)(b) ; i--)


//Non CONTIGUOUS
// to make it non-c... we take sum from S[i-2] + current position or we take it for series ending at S[i-1]

//........................extra note: for recursion, the function are would be:
//	int func( int a[], sum, int i)
//	..	
// 	func(a, sum + a[i], i-2)
//  func(a, sum, i-1)


int mx(int a , int b)
{ a>b?cout<<a:cout<<b;
	cout<<endl;

	return a>b?a:b;

}


// reasoning at: http://code-em-up.blogspot.in/2012/07/question-given-unsorted-array-of.html

void sum(int a[10], int n)
{
	
	
	int sol[10]; //New matrix memoized version
	
	sol[0]=a[0];
	sol[1]=a[1];
	
	F(i,2,n)
	sol[i] = mx( (sol[i-2] + a[i]) , sol[i-1] );    

	int res=sol[0];
	
	F(j,1,n)
	if(res<sol[j])
	res=sol[j];
	
	cout<<"Final greatest sum in non- contiguous subarray is: "<<res;
	
}


int main()
{ int a[10]= {-11,4,-2,8,-10,4,-3,4,3};

int n=sizeof(a)/sizeof(a[0]);

	sum(a,n);

}
