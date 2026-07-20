/*
Problem: 1047. Remove All Adjacent Duplicates In String

Platform: LeetCode

Topic:
Stack

Difficulty:
Easy

Approach:
- Traverse the string from left to right.
- Use a stack to keep track of characters.
- If the current character is the same as the top of the stack,
  remove the top element (adjacent duplicate found).
- Otherwise, push the current character onto the stack.
- After processing the entire string, the stack contains the final
  string without adjacent duplicates.
- Pop all characters from the stack, reverse the result, and return it.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char>st;
        int i;
        string res;
        for(i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
}        
           while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            reverse(res.begin(),res.end());
         return res;
    }
};