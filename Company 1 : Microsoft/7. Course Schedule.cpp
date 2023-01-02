#include<bits/stdc++.h>
using namespace std;

vector<int> adj[2000];
bool vis[2000];
bool recStack[2000];
bool found = false;
void dfs(int node) {
    if (found == true) {
        return;
    }
    vis[node] = true;
    recStack[node] = true;
    for (int child : adj[node]) {
        if (vis[child] != true) {
            dfs(child);
        }
        else if (recStack[child] == true) {
            found = true;
        }
    }
    recStack[node] = false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for (int i = 0; i < prerequisites.size(); i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b].push_back(a);
    }

    for (int i = 0; i < numCourses; i++) {
        if (vis[i] != true) {
            dfs(i);
        }
    }
    return !found;
}