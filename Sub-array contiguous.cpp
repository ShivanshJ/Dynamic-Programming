#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)
#define RF(i,a,b) for(int i= (int)(a) ; i > (int)(b) ; i--)


//Contiguous sum maximum;
//  (x,x,x,x) <- S[i] considering is better then , (x,x,x)<-S[i-1] + a[i] .... Comparing this new one with old
// Thus, S[i]=max(S[i-1] + a[i] ,a[i])

//........................extra note: for recursion, the function are would be:
//	int func( int a[], sum, int i)
//	..	
// 	func(a, sum + a[i], i-1)
//  func(a, a[i], i-1)


int mx(int a , int b)
{ a>b?cout<<a:cout<<b;
	cout<<endl;

	return a>b?a:b;

}

//NOTE : This memoized just makes sure it memorises the previousl computed value of sum for each
//Fine reasoning at: http://blog.saadtaame.org/2016/06/the-maximum-contiguous-subarray-problem.html

//IMP : https://people.cs.clemson.edu/~bcdean/dp_practice/

void sum(int a[10], int n)
{
	
	
	int sol[10]; //New matrix memoized version
	
	sol[0]=a[0];
	
	F(i,1,n)
	sol[i] = mx( (sol[i-1] + a[i]) , a[i] );
	
	int res=sol[0];
	
	F(j,1,n)
	if(res<sol[j])
	res=sol[j];
	
	cout<<"Final greatest sum in contiguous subarray is: "<<res;
	
}


int main()
{ int a[10]= {-11,4,-2,8,-10,4,-3,4,3};

int n=sizeof(a)/sizeof(a[0]);

	sum(a,n);

}
