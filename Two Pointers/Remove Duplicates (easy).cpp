/*
Problem: 26. Remove Duplicates from Sorted Array

Platform: LeetCode

Topic:
Two Pointers

Difficulty:
Easy

Approach:
- Since the array is sorted, duplicate elements appear next to each other.
- Use two pointers:
  - Pointer 'i' keeps track of the last unique element.
  - Pointer 'j' scans the array from left to right.
- Whenever nums[j] is different from the previous element,
  increment 'i' and place nums[j] at index 'i'.
- After traversing the array, the first (i + 1) elements contain
  all the unique elements in sorted order.
- Return (i + 1) as the number of unique elements.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        int i=0;
        int n=nums.size();
        for(int j=i+1;j<n;j++){
           if(nums[j-1]!=nums[j]){
            i++;
            nums[i]=nums[j];
           }
        }
        return i+1;
    }
};