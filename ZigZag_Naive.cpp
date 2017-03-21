#include<stdlib.h>
#include<iostream>
using namespace std;
/*	
A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and 
negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a 
zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. 
In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second 
because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. 
A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining 
elements in their original order.

Examples
0) { 1, 7, 4, 9, 2, 5 }
Returns: 6
The entire sequence is a zig-zag sequence.

1)	 	
{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }
Returns: 7
There are several subsequences that achieve this length. One is 1,17,10,13,10,16,8.

2)	   	
{ 44 }
Returns: 1

3)	   	
{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
Returns: 2

4)	   	
{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }
Returns: 8

5)	    	
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
Returns: 36


*/
int best=0;

void zig(int i, int j, int *dp,int size, int ct)
{	//Return
	if(i>=j)
		return;
	if(j>size)
		return;
		
	//Accept
	if( (dp[i]>0 && dp[j]<0) || (dp[i]<0 && dp[j]>0) )
	{	ct+=1;
		if(ct>best)
			best=ct;
			
		return zig(j,j+1, dp,size, ct); //So that the next recursion i becomes the current j, as we want to continue recursion from there
	}
	
	//Recursion
	zig(i,j+1, dp,size, ct);
	zig(i+1,j, dp,size, ct);
	
	return;	
}


int main()
{	int ar[]={ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	int n=sizeof(ar)/sizeof(ar[0]);
	int *dp = (int*)malloc(n*sizeof(int));
	for(int i=0; i<=n-2; i++)
	 { dp[i]=ar[i+1]-ar[i];
	   cout<<dp[i]<<" ";
	}
	n=n-1;				//Reduced length for dp array
	zig(0,1,dp,n-1, 1);					//ct is sent as 1, because minimum length is 1, i.e, one number
	
	if(n>1)
		cout<<endl<<best +1 ;			//Note: since length of the subsequence is asked of original array , hence +1
	else
		cout<<endl<<1 ;
	return 1;
}

