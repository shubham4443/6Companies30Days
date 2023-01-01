#include<bits/stdc++.h>
using namespace std;

void backtrack(int curr, vector<int> temp, int k, int n, vector<vector<int>> &res) {
    if (temp.size() == k) {
        int sum = 0;
        for (int x : temp) {
            sum += x;
        }
        if (sum == n) {
            res.push_back(temp);
        }
        return;
    }
    for (int i = curr + 1; i <= 9; i++) {
        temp.push_back(i);
        backtrack(i, temp, k, n, res);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    backtrack(0, vector<int>(), k, n, res);
    return res;
}