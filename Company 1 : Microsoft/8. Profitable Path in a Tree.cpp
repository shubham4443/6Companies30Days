#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis;
int ans = INT_MIN;

void dfs_parent(int node, int par) {
    parent[node] = par;
    for (int x : adj[node]) {
        if (x != par) {
            dfs_parent(x, node);
        }
    }
}

void dfs_start(int alice, int bob, vector<int>&amount, int sum) {

    // Calculate alice's sum.
    if (vis[alice] == false) {
        if (alice == bob) {
            sum += amount[alice] / 2;
        } else {
            sum += amount[alice];
        }
        vis[alice] = true;
    }

    // Bob has an unique path.
    // Bob has to move only up through its parent.
    int new_bob = -1;
    if (bob != -1) {
        new_bob = parent[bob];
        vis[bob] = true;
    }

    for (int x : adj[alice]) {
        if (x != parent[alice]) {
            dfs_start(x, new_bob, amount, sum);
        }
    }
    
    if (new_bob != -1) vis[new_bob] = false;

    if (parent[alice] != -1 and adj[alice].size() <= 1) {
        ans = max(ans, sum);
    }
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = edges.size();
    adj.resize(n+1);
    parent.resize(n+1, -1);
    vis.resize(n+1, false);

    for (int i = 0; i < n; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Mark parents of each node.
    // Node 0's parent will be -1.
    // Since its a tree, each node will have an unique parent.
    dfs_parent(0, -1);

    // Start moving alice and bob.
    dfs_start(0, bob, amount, 0);

    return ans;
}