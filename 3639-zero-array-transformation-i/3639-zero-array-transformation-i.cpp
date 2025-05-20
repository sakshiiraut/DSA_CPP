class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n+1);
        vector<int>lineswap(n+1);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            lineswap[l]++;
            lineswap[r+1]--;
        }
         pre[0]=lineswap[0];
        for(int i=1;i<n+1;i++){
            pre[i]=pre[i-1]+lineswap[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pre[i]) return false;
        }
        return true;
    }
};