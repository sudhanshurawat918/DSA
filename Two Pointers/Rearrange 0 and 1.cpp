/*
Problem: Segregate 0s and 1s

Platform: GeeksforGeeks

Topic:
Two Pointers

Difficulty:
Easy

Approach:
- Initialize two pointers:
  - Left pointer (i) at the beginning of the array.
  - Right pointer (j) at the end of the array.
- If the left element is 0, it is already in the correct position,
  so move the left pointer forward.
- If the right element is 1, it is already in the correct position,
  so move the right pointer backward.
- Otherwise, the left element is 1 and the right element is 0.
  Swap them, then move both pointers.
- Continue until the two pointers meet or cross.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(arr[i]==0){
                i++;
            } else if(arr[j]==1){
                j--;
            } else{
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            }
    }
};