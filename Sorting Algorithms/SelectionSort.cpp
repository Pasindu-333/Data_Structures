#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> arr = {12,1,32,9,1,2,22,7};

    for(int n : arr){
        cout<< n << " ";
    }
    cout<<endl;

    for(int i=0; i<arr.size(); i++){
        int min_index = i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        for(int n : arr){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}