#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    int cows = 0;
    int bulls = 0;
    unordered_map<char,int> mp;
    for (char c : secret) {
        mp[c]++;
    }
    for (char c : guess) {
        if (mp.find(c) != mp.end()) {
            cows++;
            mp[c]--;
            if (mp[c] == 0) {
                mp.erase(c);
            }
        }
    }
    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
            cows--;
        }
    }
    string res = to_string(bulls) + 'A' + to_string(cows) + 'B';
    return res;
}