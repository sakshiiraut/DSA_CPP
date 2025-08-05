class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int maxProduct=nums[0];
      int currMax=nums[0];
      int currMin=nums[0];
      int n=nums.size();
      for(int i=1;i<n;i++){
        if(nums[i]<0) swap(currMax,currMin);
        currMax=max(nums[i],nums[i]*currMax);
        currMin=min(nums[i],nums[i]*currMin);
         maxProduct = max(maxProduct, currMax); 
      }   
      return maxProduct;

    }
};