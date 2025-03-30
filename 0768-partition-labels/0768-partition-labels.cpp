#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        vector<int> result;

        // Step 1: Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        // Step 2: Iterate and partition
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastIndex[s[i]]); // Expand partition
            if (i == end) { // If end of partition reached
                result.push_back(end - start + 1);
                start = i + 1; // Start new partition
            }
        }
        
        return result;
    }
};