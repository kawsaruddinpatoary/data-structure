#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void insert(vector<int>& arr, int n){
    int i = n;
    int temp = arr[i];
    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i=i/2;
    }
    arr[i] = temp;
}

int deleteMax(vector<int>& arr, int n){
    int val = arr[1];
    int x = arr[n];
    arr[1] = x;
    arr[n] = val;
    int i=1, j=i*2;
    while(j<=n-1){
        if(arr[j+1]>arr[j] && j<n-1) j=j+1;
        if(arr[i]<arr[j]){
            swap(arr[i], arr[j]);
            i=j;
            j=i*2;
        }else{
            break;
        }
    }
    return val;
}

int main(){
    vector<int> heap({0, 30, 35, 15, 18, 40, 20, 25});
    for(int i=2; i<7; i++){
        insert(heap, i);
    }
    for(int i=7; i>1; i--){
        deleteMax(heap, i);
    }
    for(int i=1; i<=7; i++){
        cout << heap[i] << " ";
    }
}