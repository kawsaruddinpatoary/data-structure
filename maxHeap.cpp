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

void heapify(vector<int>& arr, int n, int i){
    int temp = arr[i];
    int j=i*2;
    if(i*2>n) return;
    if(j<n && arr[j+1]>arr[j]){
        j=j+1;
    }
    if(temp<arr[j]){
        swap(arr[i], arr[j]);
        heapify(arr, n, j);
    }
}

void deleteMax(vector<int>& arr, int n){
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
}

int main(){
    vector<int> heap({0, 11, 7, 9, 45, 8, 34, 90});
    int n=7;
    for(int i=n/2; i>=1; i--){
        heapify(heap, n, i);
    }
    for(int i=7; i>1; i--){
        deleteMax(heap, i);
    }
    for(int i=1; i<=7; i++){
        cout << heap[i] << " ";
    }
}