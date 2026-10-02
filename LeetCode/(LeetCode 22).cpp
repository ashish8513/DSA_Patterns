// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        auto dfs = [&](this auto&& dfs, int l, int r, string t) -> void {
            if (l > n || r > n || l < r) {
                return;
            }
            if (l == n && r == n) {
                ans.push_back(t);
                return;
            }
            dfs(l + 1, r, t + "(");
            dfs(l, r + 1, t + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
};