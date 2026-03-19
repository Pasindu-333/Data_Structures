#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums;
    nums = {7,12,32,11,1,9,3,5};

    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size()-1-i; j++){
            if(nums[j]>nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }

        for(int i : nums){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}