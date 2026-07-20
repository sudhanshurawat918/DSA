/*
Problem: 739. Daily Temperatures

Platform: LeetCode

Topic:
Monotonic Stack

Difficulty:
Medium

Approach:
- Traverse the temperature array from right to left.
- Use a stack to store the indices of days with higher temperatures.
- While the stack is not empty and the temperature at the top index
  is less than or equal to the current temperature, pop it.
- If the stack becomes empty, there is no warmer day ahead, so the answer is 0.
- Otherwise, the difference between the top index of the stack and the
  current index gives the number of days until a warmer temperature.
- Push the current index onto the stack for future comparisons.

Time Complexity:
O(n)
(Each index is pushed and popped from the stack at most once.)

Space Complexity:
O(n)
(Stack used to store indices.)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>res(n);
       res[n-1]=0;
       st.push(n-1);

       for(int i=n-2;i>=0;i--){
        while(!st.empty() &&  temperatures[st.top()] <= temperatures[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]=0;
        } else{
            res[i]=st.top()-i;
        }
        st.push(i);
       }
       return res;
    }
};