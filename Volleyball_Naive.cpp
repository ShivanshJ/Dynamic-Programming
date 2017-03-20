#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

/*
Tatyana is a big sports fan and she likes volleyball a lot! She writes down the final scores of the game after it has ended in her notebook.
If you are not familiar with the rules of volleyball, here’s a brief:
2 teams play in total
During the course of the game, each team gets points, and thus increases its score by 1.
The initial score is 0 for both teams.
The game ends when
One of the teams gets 25 points and another team has < 24 points ( strictly less than 24).
If the score ties at 24:24, the teams continue to play until the absolute difference between the scores is 2.
Given the final score of a game in the format A:B i.e., the first team has scored Apoints and the second has scored B points, can you print the number of different sequences of getting points by teams that leads to this final score?
Input Format
The first line contains A and the second line contains B.
Constraints
0 = A , B = 109
Output Format
Output the number of different sequences of getting points by the teams that leads to the final score A : B. Final means that the game should be over after this score is reached. If the number is larger than 109+7, output number modulo 109 + 7. Print 0 if no such volleyball game ends with the given score.
Example input #00
3
25
Example output #00
2925
Example input #01
24
17
Example output #01
0
Explanation #01
There’s no game of volleyball that ends with a score of 24 : 17.
*/

int flag=0;
long u,v;
long ct=0;

int volley(long a , long b)
{ if(flag==0)
	{ 
	
	  
	
		if(a<b)
		{long x=a; 
		a=b;
		 b=x; } //
		 
	flag=1;
	u=a; v=b;	
	printf("Value of u,v : %d ,%d \n",u,v);
	
	}
		


//Return	
if( ( a==0 && b>0 ) || a<0 || b<0)
return 0;


//Give answer
if(a==0 && b==0)
{
ct=ct+1;
return ct;
}


//recursion
if(u==25 && v<24)
{
volley(a-1,b);
volley(a ,b-1);
}

else if(u>24 && v>=24 && (u-v)==3) //Look : v>= 
{	//go back; here
	cout<<"a , b : "<<a<<" "<<b<<endl;
	if( (a<24 && b>24) || (a>24 && b<24))
	return 0;

	//recursion
	if(a==u && b==v) //Important, happens only once cuz of when a & b are original
		{
		volley(a-1,b);
		}
	else if(a>=24 && b>=24 && fabs(a-b)<3)
	{
	volley(a-1,b);
	volley(a ,b-1);
	}
	else if(a<=24 && b<=24)
	{volley(a-1,b);
	volley(a ,b-1);
	}
	
	else 
	return ct;
}

else return 0;

return ct;

}

int main()
{ long a,b;
cin>>a>>b;

cout<<volley(a,b);
return 0;
}
