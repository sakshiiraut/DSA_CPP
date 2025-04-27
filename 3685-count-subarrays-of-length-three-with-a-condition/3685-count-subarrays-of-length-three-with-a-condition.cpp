class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int i=0;
        int j=i+1;
        int k=i+2;
       while(k<nums.size()){
             if(nums[i]+nums[k]==((double(nums[j]))/2)) count++;
             i++;
             j++;
             k++;
       } 
      return count; 
    }
};