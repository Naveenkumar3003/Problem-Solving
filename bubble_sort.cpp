#include <bits/stdc++.h>
using namespace std;
void bs(vector<int> &arr){
    int didSwap=0;
    int n=arr.size();
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
        if(didSwap==0){
            break;
        }
    }
}
int main() {
    vector<int> arr={4,2,7,1,8,3};
    bs(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
