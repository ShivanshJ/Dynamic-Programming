
#include<string.h>
/*ORIGINAL QUESTION
 *Given a number N. print in how many ways it can be represented as N = a+b+c+d , 1< =a< =b< =c< = d; 1<=N< = 5000
 */
 
 /*
 Explanation........(Consider it has to be completed as N=a+b+c+d, i.e, 4 numbers)
 
So the not allowed case is: index<0
The base case is: i==0    ->As we have to complete it in 4 times
 
When the recursive function is called:
 	for loop: All numbers starting from 1 till the number itself or till the maximum numbers allowed to make the input number.
 	In the loop
	If a number is chosen and subtracted, in the next recursion, the same number can be subtracted or a number bigger than it.		
	
	NOTE: In knapsack problems, we have two cases , either include or exclude, 
		  here we only take the 'include case' as we have to fill each space of the four numbers
		  a+b+c+d. Thus, only including a number. BUT for EACH gap, all numbers are tried.
	 		

Look when the function is called:
Here if j=small, and small is sent as j ,was not taken Then the possibilities could be permutations
 
 Example: For num =5 , Then output as: 1+1+1+2 & 1+1+2+1 & 1+2+1+1 & 2+1+1+1
 
 Taken a number, to be reduced to 0 in exactly 4 ways. It follows coin change problem.
 */
 
#include <iostream>
#include <conio.h>
using namespace std;

int ct=0;
void calc(int num,int i, int size, int small)
{
	if(i<0)
	return;
	
	if(i==0 && num==0)
	{ ct++;
	}
	
	for(int j=small; j<size && j<=num ; j++)
		{ 	
			calc(num-j,i-1,size,j) ; //Case1:Have to Include the element to fill the space& can repeat it as many number of times
			
		}
		
	return;
}

int main()
{ int num,k;
	cout<<"................Program to print a number as sum of 'k' numbers\n";
	cout<<"Enter the number: ";
	cin>>num;
	cout<<"Enter value for k: ";
	cin>>k;
	int size=5000;
	calc(num,k,size,1);
	cout<<ct;
	return 0;
}
