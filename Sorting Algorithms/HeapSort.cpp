#include<iostream>
#include<vector>
#include <iterator>
using namespace std;


void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;      
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // for (int i = n - 1; i > 0; i--) {
    //     swap(arr[0], arr[i]);

    //     maxHeapify(arr, i, 0);
    // }
}

int heapMaximum(const vector<int>& A) {
    if (A.empty()) return -1;
    return A[A.size()-1];
}

void printArray(const vector<int>& arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
}

int extractMax(vector<int> &arr){
    if(arr.size() < 1){
        return -1;
    }
    int max = arr[0];

    arr[0] = arr.back();
    arr.pop_back();
    maxHeapify(arr, arr.size(), 0);

    return max;
}

void increaseKey(vector<int>& arr, int i, int key){
    if(key < arr[i]){
        return;
    }
    arr[i] = key;

    while(i>0 and arr[i] > arr[(i-1)/2]){
        swap(arr[i],arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    vector<int> data = {12, 11, 13, 5, 6, 7};
    
    heapSort(data);

    cout << "Sorted array: ";
    printArray(data);

    return 0;
}

