class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
         int left = 0, usedBits = 0, maxLength = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while ((usedBits & nums[right]) != 0) {
                usedBits ^= nums[left];
                left++;
            }
            usedBits |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};