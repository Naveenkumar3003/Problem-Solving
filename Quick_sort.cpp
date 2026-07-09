#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int low, int high){
    int i=low,j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}
void qs(vector<int> &arr,int low,int high){
    int p;
    if(low<high){
        p=partition(arr,low,high);
        qs(arr,low,p-1);
        qs(arr,p+1,high);
    }
}
int main() {
    vector<int> arr={4,2,7,1,8,3};
    qs(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//TC - O(nlogn) SC - O(1)
