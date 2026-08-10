/*
Problem: Sort an Array
LeetCode: 912

Approach:
- Use Merge Sort to divide the array into smaller subarrays.
- Recursively sort the left and right halves.
- Merge the two sorted halves using a temporary array.
- Copy the merged elements back into the original array.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
void mergeBoth(vector<int>&arr, int low, int mid, int high){
    vector<int>temp;
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=high){
        temp.push_back(arr[j++]);
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>&arr, int i, int j){
    if(i >= j) return;
    int mid=i+(j-i)/2;
    mergeSort(arr,i,mid);
    mergeSort(arr,mid+1,j);
    mergeBoth(arr, i,mid,j); 
}
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==0) return {};
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
