// 1614. Maximum Nesting Depth of the Parentheses

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                ans = max(ans, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return ans;
    }
};
