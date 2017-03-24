#include<stdio.h>
#define M 3
#define N 3
#include<iostream>
#include<stdlib.h>
using namespace std;


int a[M][N]={ {1, 2, 3}, {4, 5, 6} , {7,8,9}};

int count=0;
int *b=(int *)malloc(M*N*sizeof(int)+1);




void fx(int i1,int j1,int b[7],int k)
{
	int i,j,l;
	
	if(i1>M-1 || j1>N-1)
		return;
	
	
	b[k]=a[i1][j1];
	
	if(i1==M-1 && j1==N-1)
	{
		for(l=0;l<=k;l++)
		{
			printf("%d ",b[l]);
		}
		printf("\n");
		count++;
		return;
	}
	
	fx(i1+1,j1,b,k+1);
	fx(i1,j1+1,b,k+1);
	
	
}
int main(){
	int x;
	for(x=0; x<(M*N+1); x++)
 		b[x]=0;
 
	fx(0,0,b,0);
	printf("Count is: %d",count);
	return 0;
}

/* MEMOIZED VERSION FROM geeksforgeeks, LOOK AT HOW FIRST ROW AND COLUMN ARE INITIALIZED
http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/


#include <iostream>
using namespace std;

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // Create a 2D table to store results of subproblems
    int count[m][n];

    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;

    // Count of paths to reach any cell in first column is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)

            // By uncommenting the last part the code calculatest he total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];

    }
    return count[m-1][n-1];
}

// Driver program to test above functions
int main()
{
    cout << numberOfPaths(3, 3);
    return 0;
}

*/
