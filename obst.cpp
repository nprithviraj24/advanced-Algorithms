// Dynamic Programming code for Optimal Binary Search 
// Tree Problem
#include<iostream>
#include <stdio.h>
#include <limits.h>
#define Max_Value 10


// A utility function to get sum of array elements 
// freq[i] to freq[j]
using namespace std;
//int n;

int sum(int freq[], int i, int j);

typedef struct E_Cost{
   int cost;
  int root_index;

} EachCost; 

//EachCost CostMat[][];


/* A Dynamic Programming based function that calculates
  minimum cost of a Binary Search Tree. */
int optimalSearchTree(int keys[], int freq[], int n)
{
    /* Create an auxiliary 2D matrix to store results 
      of subproblems */
  EachCost CostMat[n][n];
      //int cost[n][n];
 
    /* cost[i][j] = Optimal cost of binary search tree
       that can be  formed from keys[i] to keys[j].
       cost[0][n-1] will store the resultant cost */
 
    // For a single key, cost is equal to frequency of the key
  for (int i = 0; i < n; i++){
      CostMat[i][i].cost= freq[i];
      CostMat[i][i].root_index = i;
  }
    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L=2; L<=n; L++)
    {
        // i is row number in cost[][]
        for (int i=0; i<n-L+1; i++)
        {
            // Get column number j from row number i and 
            // chain length L
            int j = i+L-1;
            CostMat[i][j].cost = INT_MAX;
	    //CostMat[i][j].root_index = null;
	    cout<<"\n";
            // Try making all keys in interval keys[i..j] as root
            for (int r=i; r<=j; r++)
            {
               // c = cost when keys[r] becomes root of this subtree
               int c = ((r > i)? CostMat[i][r-1].cost:0) + 
                       ((r < j)? CostMat[r+1][j].cost:0) + 
                       sum(freq, i, j);
               if (c < CostMat[i][j].cost){
                 CostMat[i][j].cost = c;
		 CostMat[i][j].root_index = r;
		 // cout<<"\t\t r value:"<<r<<"\n";
	       }	  
            }
	    cout<<"The Cost of Optimal substructure from index "<<i<<" to "<< j<< " is: "<<CostMat[i][j].cost<<" \n";
            cout<<"Root of the substructure: "<<keys[CostMat[i][j].root_index]<<"\n";
	    
        }
    }
    //cout<<"\n\n Root of the structure is: "<<r;
    return CostMat[0][n-1].cost;
}


// A utility function to get sum of array elements 
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}
 
// Driver program to test above functions
int main()
{
  int keys[] = {12,15,20,25};
  int freq[] = {4,3,6,2};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", 
                 optimalSearchTree(keys, freq, n));
    return 0;
}
