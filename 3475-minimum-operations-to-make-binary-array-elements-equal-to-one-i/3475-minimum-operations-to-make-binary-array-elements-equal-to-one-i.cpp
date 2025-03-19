class Solution {
        public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0, flipEffect = 0;
        queue<int> q; // Stores indices where flips expire

        for (int i = 0; i < n; i++) {
            // Remove expired flips
            if (!q.empty() && q.front() == i) {
                q.pop();
                flipEffect ^= 1; // Undo the effect of a past flip
            }

            // If nums[i] needs to be flipped (0 → 1)
            if ((nums[i] ^ flipEffect) == 0) {
                if (i + 2 >= n) return -1; // Impossible to flip a window of 3
                
                flips++;               // Perform a flip
                flipEffect ^= 1;       // Toggle flip effect
                q.push(i + 3);         // Flip effect ends at index i+3
            }
        }
        
        return flips;
    }
};