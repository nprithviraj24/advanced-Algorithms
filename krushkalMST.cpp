#include<stdio.h>
#include<iostream>
#include<climits>

using namespace std;

int parent[10]={0};

int find(int k){
	while(parent[k] != 0){
		k = parent[k];
	}
	return k;
}

int main(){

	int i,nVertices, nEdges, cost=0, mat[20][20]={0}, a,b,j,d=1,v,u;
	cout<<"Enter the number of vertices: ";
	cin>>nVertices;

	cout<<"\n Enter the number of edges: ";
	cin>>nEdges;
	cout<< "From"<< "-To-"<< "Weight"<<endl;
	for(i=1; i<=nEdges; i++){
		cin>>a;
		cin>>b;
		cin>>mat[a][b];
		mat[b][a]=mat[a][b];
	}

	cout<<"\n The adjacency matrix is: "<<endl;

	for(i = 1; i<= nVertices; i++){
		cout<<i<<":   ";
		for(j=1; j<=nVertices; j++){
			cout<<mat[i][j]<<" ";
			if(mat[i][j] == 0){
				mat[i][j] = INT_MAX;
			}
		}
		cout<<endl;
	}

	while(d<nVertices){
		int min = INT_MAX;
		for(i = 1; i<= nVertices; i++){
                	for(j=1; j<=nVertices; j++){
                        	//cout<<mat[i][j]<<" ";
                        	if(mat[i][j] < min){
					min = mat[i][j];
					u=a=i;
					v=b=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		//prevents us from forming a cycle i.e it shouldn't have a common ancestor
		if(u !=v){
			cout<<"Edge "<<d++<<" is "<<a<<"."<<b<<" with cost = "<<min<<endl;
			cost += min;
			parent[v]=u;
		}
		mat[a][b] = INT_MAX;
	}

	cout<<"\n The total cost is "<<cost<<endl;

return 0;
}
