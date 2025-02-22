class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLength=INT_MAX;
        int i=0;
        int sum=0;
         int startIdx=0;
         int len=0;
        while(i<n){
            sum+=nums[i];
           while(sum>=target){
            len = i-startIdx+1;
            minLength=min(minLength, len);
            sum-=nums[startIdx];
            startIdx++; 
           }
            i++;
        }
        if(minLength==INT_MAX) return 0;
        else return minLength;
    }
};