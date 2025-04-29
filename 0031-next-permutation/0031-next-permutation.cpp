#include <vector>
#include <algorithm>
#include<iostream>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        
        // Step 1: Find the largest index 'idx' such that nums[idx] < nums[idx + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        
        // Step 2: If no such index exists, the permutation is the last permutation. Reverse to get the first permutation.
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Find the largest index 'j' greater than 'idx' such that nums[idx] < nums[j]
        for (int j = n - 1; j > idx; j--) {
            if (nums[j] > nums[idx]) {
                swap(nums[idx], nums[j]);
                break;
            }
        }
        
        // Step 4: Reverse the subarray nums[idx + 1, n)
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
