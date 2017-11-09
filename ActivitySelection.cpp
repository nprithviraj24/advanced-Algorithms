#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct ACTIVITY {
	int start;
	int finish;
} activity;



bool activitySort(activity s1, activity s2){
	return (s1.finish < s2.finish);
}


void SelectActivities(activity arr[], int n){
	int i=0;
	//First get selected
	cout<<"\n"<<i+1<<". ("<<arr[i].start<<" - "<<arr[i].finish<<"), ";

	for(int j=1; j<n; j++){
		if(arr[j].start >= arr[i].finish){
			cout<<"\n"<<j+1<<". ("<<arr[j].start<<" - "<<arr[j].finish<<")";
			i = j;
		}
	}

}

int main(){
	int n;

	cout<<"Enter the number of activities: ";
	cin>>n;
	activity arr[n];
	cout<<endl;
	cout<<"Enter starting time finishing time of each activity: ";
	cout<<"\n\nStart-End"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i].start;
		cin>>arr[i].finish;
	}
	cout<<"\n Sorted first: "<<endl;

	//using inbuilt sort function, parameters start and end, third one specifies the curtailment
	sort(arr, arr+n, activitySort);

	SelectActivities(arr, n);

	cout<<endl;
}
