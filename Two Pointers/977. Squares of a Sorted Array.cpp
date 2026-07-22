/*
Problem: 977. Squares of a Sorted Array

Platform: LeetCode

Topic:
Two Pointers

Difficulty:
Easy

Approach:
- Traverse the sorted array and compute the square of each element.
- Store the squares of negative numbers in one vector and the squares
  of non-negative numbers in another vector.
- Reverse the vector containing squared negative numbers since their
  squares are in decreasing order.
- Merge the two sorted vectors using the two-pointer technique to
  obtain the final sorted array of squared values.
- Append any remaining elements from either vector to the result.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> neg;
      vector<int> pos;
      for(int i=0;i<nums.size();i++){
        int sq=nums[i]*nums[i];
        if(nums[i]<0)
            neg.push_back(sq);
         else
            pos.push_back(sq);
       
      }
       reverse(neg.begin(),neg.end());

      vector<int> ans;
      int i=0;
      int j=0;
      while(i<neg.size() && j<pos.size()){
        if(neg[i]<pos[j]){
            ans.push_back(neg[i]);
            i++;
        } else{
            ans.push_back(pos[j]);
            j++;
        }
        
      }
      
while(i < neg.size()) {
    ans.push_back(neg[i]);
    i++;
}

while(j < pos.size()) {
    ans.push_back(pos[j]);
    j++;
}
      return ans;
    }



};