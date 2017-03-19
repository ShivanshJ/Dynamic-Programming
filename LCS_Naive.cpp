#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


char s1[7]="ABCDGH";
char s2[7]="AEDGHR";
int n=strlen(s1)>strlen(s2) ? strlen(s2):strlen(s1);//Shorter of the two lenghts for array of path

char path[9], best_path[9];
int best_ct=0;

int mx(int a , int b)
{ 

	return a>b?a:b;

}

int y;

int func(int i, int j, int ct, int p)
{ 
	if (i==-1 || j==-1)
	{ if(ct > best_ct)
		{ best_ct=ct;
		 int k;
		   for(k=p , y=0 ; k<8;k++, y++)
		   best_path[y]=path[k];
		}
		
		return 1;
    }
    
    
    
	if(s1[i]==s2[j])
		{ 
		  path[p]=s1[i];
		  
		return 1+ func(i-1,j-1,ct+1,p-1);
	
		}
	
	
     return  mx( func(i-1,j,ct,p), func(i,j-1,ct,p)	);
}

int main()
{ int x;
	

  x=func(strlen(s1)-1 ,strlen(s2)-1 , 0, 7);
  
  cout<<x<<endl;
  
  for(int j=0; j<y; j++)
		  cout<<best_path[j];
  
  return 0;
	
	
}
