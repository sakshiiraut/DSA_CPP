class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<k) return -1;
        }
        unordered_set<int>s;
        for(int num:nums){
           if(num>k) {
            s.insert(num);
           }
        }
        return s.size();
    }
};