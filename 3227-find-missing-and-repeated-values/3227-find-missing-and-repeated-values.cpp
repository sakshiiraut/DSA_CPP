class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         int n = grid.size();
    int N = n * n;
    
    unordered_set<int> seen;
    int sum_actual = 0, sum_expected = (N * (N + 1)) / 2;
    int repeated = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            if (seen.count(val)) {
                repeated = val;
            }
            seen.insert(val);
            sum_actual += val;
        }
    }
    
    int missing = sum_expected - (sum_actual - repeated);
    return {repeated, missing};
    }
};