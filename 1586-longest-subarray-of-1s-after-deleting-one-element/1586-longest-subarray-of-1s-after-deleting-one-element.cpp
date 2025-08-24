class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) prev++;
            else{
                ans =max(ans,curr+prev);
                curr=prev;
                prev=0;
            }  
        }
         ans = max(ans, curr+prev);
         return ans==n?ans-1:ans;
    }
};