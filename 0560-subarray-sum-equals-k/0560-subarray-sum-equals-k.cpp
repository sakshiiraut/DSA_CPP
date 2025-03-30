class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                if(sum+nums[j]==k){
                    count++;
                }
                sum+=nums[j];
            }
        }
        return count;
    }
};