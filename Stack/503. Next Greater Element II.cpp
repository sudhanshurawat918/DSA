class Solution {
/*
Problem: 503. Next Greater Element II

Platform: LeetCode

Topic:
Monotonic Stack

Difficulty:
Medium

Approach:
- Since the array is circular, traverse it from n-2 to 0 to push the every element in stack except the last index.
  (from index n-2 to 0).
- now traverse from last index to 0th index.
- while stack is not empty and st.top <= nums[i], st.pop.
  if stack is empty then push the index of array res with -1,
else push st.top in res[i];
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
        vector<int> res(n)
      
        
        stack<int>st;
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <=nums[i]){
                st.pop();
            }
            if(st.empty()){
                
                res[i]=-1
            }else{
                res[i]=st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
};
