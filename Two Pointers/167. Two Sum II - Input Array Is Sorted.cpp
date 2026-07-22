/*
Problem: 167. Two Sum II - Input Array Is Sorted

Platform: LeetCode

Topic:
Two Pointers

Difficulty:
Medium

Approach:
- Initialize two pointers:
  - Left pointer at the beginning of the array.
  - Right pointer at the end of the array.
- Calculate the sum of the elements at both pointers.
- If the sum equals the target, return their 1-based indices.
- If the sum is smaller than the target, move the left pointer
  to increase the sum.
- If the sum is greater than the target, move the right pointer
  to decrease the sum.
- Continue until the pair is found.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                return{i+1,j+1};
            } else if(sum<target){
                i++;
            } else{
                j--;
            }
        }
        return {};
    }
};