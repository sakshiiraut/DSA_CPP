class Solution {
public:
   vector<vector<int>>ans;
   void helper(vector<int>&nums,int idx,vector<int>&subset,int n){
     if(idx>=n){
        ans.push_back(subset);
        return;
     }
     helper(nums,idx+1,subset,n);
     subset.push_back(nums[idx]);
     helper(nums,idx+1,subset,n);
     subset.pop_back();

   }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int>subset;
        helper(nums,0,subset,nums.size());
        return ans;
    }
};