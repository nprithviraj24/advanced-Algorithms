#include<stdio.h>
#include<iostream>
#include<climits>
#define Max 10

using namespace std;

int splitAt[Max][Max];

int split(int start, int end){
	int s = splitAt[start][end];
	if (s != 0){
		cout<<" (";

		if(start == s)
			cout<<" a["<<start<<"]";

		split(start, s);
		cout<<"*";

		if(s+1 == end)
			cout<<" a["<<s+1<<"] ";

		split(s+1, end);
		cout<<") ";
	}
}

int ChainOrder(int p[], int n){
	long m[n][n];
	long q;
	int i,j,k,l;

	for(i = 1; i<=n; i++)
		m[i][i]= 0;

	// l signigies the length of the chain. It starts from 2 because we have already defined chain length of 1
	for(l=2; l<=n; l++){
		//i is the row number.
		for(i=1; i<=n-l+1; i++){
			//
			j=i+l-1;
			m[i][j]= INT_MAX;
			for(k=i; k<=j-1; k++){
				//q = cost of scalar multiplications
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

				if(q<m[i][j]){
					m[i][j] = q;
					splitAt[i][j] = k;
				}
			}
			cout<<"Cost of "<<i<<" to "<<j<<" is: "<<m[i][j]<< " and they splitAt: "<<splitAt[i][j] <<"\t";
			split(i,j);
			cout<<"\n";
		}
	}
return m[1][n];
}

int main(){
  int n;

  cout<<"\n Enter the number of  matrices: ";
  cin>>n;
  int p[n+1];
  cout<<"\n Enter the sequence numbers: ";
  for(int i = 0; i<=n; i++){
	cin>>p[i];
  }


int totalCost = ChainOrder(p, n);
cout<<"\n\n Split: ";
split(1,n);

cout<<"\n total cost: "<<totalCost<<" \n";

}
