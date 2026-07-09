#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        swap(arr[mini],arr[i]);
    }
}
int main() {
    vector<int> arr={4,2,7,1,8,3};
    selection_sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
