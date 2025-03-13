class Solution {
public:
 bool canMakeZero(vector<int> nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 2, 0); // Difference array

        // Apply first k queries using difference array
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] -= val;
            diff[r + 1] += val;
        }

        // Apply difference array to nums
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i]; // Apply difference array
            nums[i] += sum; // Apply to nums
            if (nums[i] > 0) return false; // If any number is positive, fail
        }
         return true;
 }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      int left = 0, right = queries.size(), answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(nums, queries, mid)) {
                answer = mid;  // Found a valid k, try for a smaller one
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    
 }
};