#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &arr, int mid, int l, int r){

    int n1 = mid-l+1;
    int n2 = r-mid;

    int lArr[n1];
    int rArr[n2];

    for(int x=0; x<n1; x++){
        lArr[x] = arr[x+l];
    }

    for(int x=0; x<n2; x++){
        rArr[x] = arr[mid+1+x];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){

        if(lArr[i] <= rArr[j]){
            arr[k] = lArr[i];
            i++;
        }
        else{
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = lArr[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = rArr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int l, int r){

    if(l<r){

        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);

        merge(arr, mid, l, r);
    }
}


int main(){

    vector<int> arr = {3, 5, 1, 4, 6, 2};

    for(int n : arr){
        cout << n << " ";
    }
    cout << endl;

    mergesort(arr, 0, arr.size()-1);

    for(int n : arr){
        cout << n << " ";
    }

    return 0;

}