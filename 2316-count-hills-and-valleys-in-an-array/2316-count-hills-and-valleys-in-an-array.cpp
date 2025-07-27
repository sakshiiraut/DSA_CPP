class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] == nums[i-1]) continue;
            int j = i - 1;
            while(j >= 0 && nums[j] == nums[i]) j--;
            if(j < 0) continue;
            
            int k = i + 1;
            while(k < n && nums[k] == nums[i]) k++;
            if(k >= n) continue;
            
            if(nums[i] > nums[j] && nums[i] > nums[k]) count++; 
            else if(nums[i] < nums[j] && nums[i] < nums[k]) count++; 
        }
        
        return count;
    }
};
