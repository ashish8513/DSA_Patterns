// 1190. Reverse Substrings Between Each Pair of Parentheses
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string s that consists of lower case English letters and brackets.

// Reverse the strings in each pair of matching parentheses, starting from the innermost one.

// Your result should not contain any brackets.

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
               
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {
                
                reverse(curr.begin(), curr.end());

               
                curr = st.top() + curr;
                st.pop();
            }
            else {
               
                curr += ch;
            }
        }

        return curr;
    }
}; 