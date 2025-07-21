class Solution {
public:
int rev(int n){
    int rem=0;
    while(n>0){
        rem*=10;
        rem+=n%10;
        n=n/10;
    }
    return rem;
}
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]-=rev(nums[i]);
        }
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<n;i++){
           if(mp.find(nums[i])!=mp.end()){
            count = count%1000000007;
            count+=mp[nums[i]];
            mp[nums[i]]++;
           }
           else mp[nums[i]]++; 
        }
        return count%1000000007;
    }
};