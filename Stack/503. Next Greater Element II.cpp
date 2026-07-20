class Solution {
/*
Problem: 503. Next Greater Element II

Platform: LeetCode

Topic:
Monotonic Stack

Difficulty:
Medium

Approach:
- Since the array is circular, traverse it twice from right to left
  (from index 2*n-1 to 0).
- Use a monotonic decreasing stack to store potential next greater elements.
- While the top of the stack is less than or equal to the current element,
  remove it because it cannot be the next greater element.
- During the second pass (when i < n), if the stack is not empty,
  the top of the stack is the next greater element for the current index.
- Push the current element onto the stack before moving to the next index.

Time Complexity:
O(n)
(Each element is pushed and popped from the stack at most once.)

Space Complexity:
O(n)
(Stack used to store candidate next greater elements.)
*/
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
          int n=nums.size();
        vector<int> res(n,-1);
      
        
        stack<int>st;
        
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty())
                res[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};