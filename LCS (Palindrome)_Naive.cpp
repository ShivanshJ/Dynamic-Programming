#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


//Longest palindrome subsequence.. subsequence means non-contiguous


#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)
#define RF(i,a,b) for(int i= (int)(a) ; i > (int)(b) ; i--)

char s1[]="BBABCBCAB";

char path[9], best_path[9];
int best_ct=0;

int mx(int a , int b)
{ 
	return a>b?a:b;
}


void func( int i, int j, int ct, int p )
{  if(j<0 || i>strlen(s1))
	return;

	if(i>j)
 	{ if(ct>best_ct)
 		{
 		 best_ct=ct;
 		F(i,0,p+1)		//For storing the best array
 			{  
 				best_path[i]=path[i];
 			}
 			cout<<endl;	
 		}
 		
 		//Printing all of them
 		else F(i,0,p+1)
 			 cout<<path[i];
 			 
 		cout<<endl;
 		
 			return;
	}
	
	if(s1[i]==s1[j])
		{ path[p]=s1[i];
			if(i==j)  func(i+1,j-1,ct+1,p+1); //if both are the same character, increase count only by 1
			else  func(i+1,j-1,ct+2,p+1);	//increase length of palindrome by having first and last both in the string
		 
		  return;
		}
	else	
	{
	func(i+1,j,ct,p);
	func(i,j-1,ct,p);
	}
	return;		
}

int main()
{ int x;
	
	int length=strlen(s1);
	cout<<length;

  func(0, length-1 , 0,0);
  
  cout<<x<<endl<<"Printing the best path: ";
  
  F(j,0, (best_ct+1)/2)
		  cout<<best_path[j];

 //Printing the other half of palindrome, by simply reprinting best path in backwards
	RF(j,best_ct/2 -1, 0-1 )
		  cout<<best_path[j];
		  
	cout<<endl;	  
		  
	cout<<"The longest palindrome subsequence is of length: "<<best_ct;
  
  return 0;
		
}



/* THIS IS LIKE LCS_NAIVE


// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;
 
   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;
 
   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;
 
   // If the first and last characters do not match
    return max( lps(seq, i, j-1), lps(seq, i+1, j) );
   
   
   */


