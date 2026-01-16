#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//bubble sort

void bS(vector<int>&nums){
    int n = nums.size();
    bool isSwap = false;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
                isSwap = true;
            }
        }
    }

    if(!isSwap) return;
}

void sS(vector<int>&nums){
    int n = nums.size();

    for(int i = 0 ; i < n-1 ; i++){
        int SI = i;
        for(int j = i+1 ; j < n ; j++){
            if(nums[j] < nums[SI]){
                SI = j;
            }
        }
        swap(nums[i],nums[SI]);
    }
}


void iS(vector<int>&nums){
    int n = nums.size();

    for(int i = 0 ; i < n ; i++){
        int j = i;

        while(j > 0 && nums[j-1] > nums[j]){
            swap(nums[j],nums[j-1]);
            j--;
        }
    }
}

int main(){
    vector<int>nums = {4,1,5,2,3};
    // bS(nums);
    // sS(nums);
    iS(nums);
    for(int num : nums){
        cout<<num<<' ';
    }
    cout<<endl;
    return 0;
}