/*
Problem: 20. Valid Parentheses

Platform: LeetCode

Topic:
Stack

Difficulty:
Easy

Approach:
- Traverse the string from left to right.
- Push every opening bracket ('(', '{', '[') onto the stack.
- For every closing bracket, first check if the stack is empty.
  - If it is empty, the string is invalid.
- Otherwise, compare the closing bracket with the top of the stack.
  - If they form a matching pair, pop the opening bracket.
  - Otherwise, return false.
- After processing all characters, the stack should be empty.
  - If it is empty, all brackets were matched correctly.
  - Otherwise, the string is invalid.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }
            else{
            if(st.empty())
                return false;
            
            if(s[i]==')' && st.top()=='(')
                st.pop();
            
            else if(s[i]=='}' && st.top()=='{')
                st.pop();
            
            else if(s[i]==']' && st.top()=='[')
                st.pop();
            
            else
            return false;
            }
            
        }
         if(!st.empty())
            return false;
        
       return true;
    }
};