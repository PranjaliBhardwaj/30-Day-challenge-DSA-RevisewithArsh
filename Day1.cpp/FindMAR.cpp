
class Solution {
public:
    vector<int> findTwoElement(vector<vector<int>>& grid) {
        int n = grid.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[grid[i][j]]++;
        }
    }

    int miss, repeat;
    for (int i = 1; i <= n * n; i++) {
        if (mp[i] == 2)
            repeat = i;
        if (mp[i] == 0)
            miss = i;
    }

    return {repeat, miss};
    }
};
