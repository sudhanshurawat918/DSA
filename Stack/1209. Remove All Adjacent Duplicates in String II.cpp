/*
Problem: 1209. Remove All Adjacent Duplicates in String II

Platform: LeetCode

Topic:
Stack

Difficulty:
Medium

Approach:
- Use a stack to store pairs of (character, frequency).
- Traverse the string one character at a time.
- If the stack is empty or the current character is different from
  the top character, push the character with a frequency of 1.
- If the current character matches the top of the stack:
  - Increment its frequency.
  - If the frequency becomes equal to k, remove the pair from the stack,
    effectively deleting those k adjacent duplicate characters.
- After processing the entire string, reconstruct the final string by
  popping all pairs from the stack and appending each character according
  to its stored frequency.
- Reverse the constructed string before returning it since elements are
  retrieved from the stack in reverse order.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(st.empty()){
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                st.push({c,1});
                continue;
            }
            if(st.top().second < k-1){
                pair<char,int>p =st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }
            st.pop();
        }
        string res="";
        while(!st.empty()){
            pair<char,int> p=st.top();
            st.pop();

            while(p.second--){
                res.push_back(p.first);
            }
        }
          reverse(res.begin(),res.end());
        return res;
      
    }
};