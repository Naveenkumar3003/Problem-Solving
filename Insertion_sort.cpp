#include <bits/stdc++.h>
using namespace std;
void i_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
int main() {
    vector<int> arr={4,2,7,1,8,3};
    i_sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//TC - O(n) best , O(n^2) avg and worst , SC -O(1)
