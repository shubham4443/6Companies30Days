#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    vector<int> F(n, 0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        F[0] += i * nums[i];
    }

    int ans = F[0];
    for (int i = 1; i < n; i++) {
        F[i] = F[i-1] + sum - (n * nums[n - i]);
        ans = max(ans, F[i]);
    }
    
    return ans;
}