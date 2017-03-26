#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

//Question:
/*A magician is distributing money to 2 friends. He has an array of coins, each with a diff value 
He gives the 1st friend the first coin & 2nd friend the 1st coin.
Based on 2 conditions:
1)if i+1 and (i-1)th coin value is even . Then i CAN be average of the two
2) 

Take out the maximum absolute difference that can be there in the cases
Example :  5,6,5,2,7, 1,9,7,2,5
case 1: |5-5| + |6-2| + |5-7| + |2-9| + |7-1| =19
case 2: if we do magic on i=2,i.e, 5 .. IT BECOMES (6+2)/2 = 4. and we thus calculate again.

 */



#include<iomanip>
#define F(i,a,b) for(int i= (int)(a) ; i < (int)(b) ; i++)

int ar[10]={5,6,5,2,7, 2,9,7,2,5};
const int n=sizeof(ar)/sizeof(ar[0]);



int mx(int a , int b)
{ 
return a>b?a:b;

}


int best=0;
int path[10]={0};

int magic(int *ar, int i, int j, int cost)
{   
	
	//Accept condition
	if(i>j || i==j)
	{ if(best < cost)
		best=cost;
		
	 cout<<" : for the test case : ";
	  F(k,0,n)
	  	cout<<path[k];	
	 
	 cout<<endl;
		return 0;
	}
	
	//Taking down path followed
	path[i]=ar[i];
	path[j]=ar[j];
	
	int x=0, y=0;
	
	//Calculation if magic is possible
	if(i!=0)
	{ if(ar[i-1]%2==0  && ar[i+1]%2==0)
	    x=(ar[i-1]+ar[i+1])/2;
		
	  if(ar[j-1]%2==0  && ar[j+1]%2==0)
	  	y=(ar[j-1]+ar[j+1])/2;
	    
	}
	
	//Recursive functions
	magic(ar,i+1,j-1, cost + fabs(ar[i]-ar[j]) ) ;
	
	if(i!=0 )
	{   if(x>0)
	    {path[i]=x;
		cout<<endl;
		magic(ar,i+1,j-1,  cost + fabs(x-ar[j]) ) ;
		}
		if(y>0)
	    {path[j]=y;
		cout<<endl;
		magic(ar,i+1,j-1,  cost + fabs(ar[i]-y) ) ;
		}
		if(x>0 && y>0)
		magic(ar,i+1,j-1,  cost + fabs(x-y) ) ;
	}
	
	//Go back 
	return 0;
	
}

int main()
{ 
	cout<<"Size of array is: "<<n<<endl;
	magic(ar,0,n-1,0);
	
	cout<<endl<<"Maximum absolute difference is: "<<best;
	

return 0;
}

