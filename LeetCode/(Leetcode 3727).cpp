// 3727. Maximum Alternating Sum of Squares

// You are given an integer array nums. You may rearrange the elements in any order.

// The alternating score of an array arr is defined as:

// score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
// Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& x : nums) {
            x = x * x;
        }
        ranges::sort(nums);
        long long ans = 0;
        int m = nums.size() >> 1;
        for (int i = 0; i < nums.size(); ++i) {
            ans += i < m ? -nums[i] : nums[i];
        }
        return ans;
    }
};