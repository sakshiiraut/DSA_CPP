class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        if(nums[i]+nums[i+1]<=nums[i+2] ||nums[i+1]+nums[i+2]<=nums[i] ||nums[i]+nums[i+2]<=nums[i+1]) return "none";
        else if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2] && nums[i]==nums[i+2]) return "equilateral";
        else if(nums[i]==nums[i+1] || nums[i+1]==nums[i+2] || nums[i]==nums[i+2]) return "isosceles";
        else return "scalene";

    }
};