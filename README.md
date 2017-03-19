# Dynamic-Programming
To make the best use of the repository for learning what took me ages to simplify.
Follow the instructions to understand how to read the codes systematically

...........Recursion (Naive approach)

A brute force approach has been first used to understand the problems.
1) The naive .cpp files use recursion
2) All recursions are mostly done in one format so that it can be re-created on any program easily
3) In all recursive functions,
First, the return conditions are included. (where recursion doesn't continue)
Second, the acceptance conditions are there. (where recursion sub-tree stops)
Third, the recursive function is called.

Example, In a 4x4 Matrix - if a robot can move in all four directions and we have to find the shortest path it can reach reach its
start point (sx, sy), here, (0,0).

	//Global Variables
	int sx=0;
	int sy=0;
	int shortest = INT_MAX;

	void robo(int ar[5][5], int i, int j ,int ct)
	{ 
	// Return conditions
	if(i>4 || j>4 || i<0 || j<0 )
 	return;

	// Accepting when i and j reach the start point
	if(i==sx && j==sy)
  		{
  	 	 if(shortest>ct)
		  	 shortest=ct;   
	   	 return; 
	   }
	     
	//Function call
	robo(ar, i,j-1 , ct+1);
	robo(ar, i-1,j , ct+1) ;
	robo(ar, i,j+1 , ct+1);
	robo(ar, i+1,j , ct+1) ;

	}

	..main()
	{ robo(ar, 4,4, 0);
  	cout<<"The shortes path is: "<<shortest;
	}


...........Dynamic Approach (Top-down approach)
1) Learn how to store the recursive functions
2) Updates to be made
