class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int t;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2 ;
            if(nums[mid]<=target){
                if(nums[mid]==target) return mid;
                lo=mid+1;
                t = mid+1;
            }else if(nums[mid]>target){
                 hi=mid-1;
            }
        }
        return t;
    }
};