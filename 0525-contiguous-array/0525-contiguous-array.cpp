class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;//particu;ar sum occured for the first time at which index
       int ans=0,sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) sum-=1;
            else sum+=1;
            if(sum==0){
                 ans=i+1;
            }else{
                if(mp.find(sum)!=mp.end()){
                    ans=max(ans,i-mp[sum]);
                }else{
                    mp[sum]=i;
                }
            }
        }
        return ans;
    }
};