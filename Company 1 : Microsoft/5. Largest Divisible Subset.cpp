#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 0);
    for (int i = 1; i < n; i++) {
        hash[i] = i;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }
    int max_index = -1;
    int max_so_far = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max_so_far) {
            max_so_far = dp[i];
            max_index = i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[max_index]);
    while (hash[max_index] != max_index) {
        max_index = hash[max_index];
        ans.push_back(nums[max_index]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}