class Solution {
public:
    int getPivot(vector<int>& nums, int target){
      int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
    }
    int binarySearch(vector<int>& nums, int target,int low,int hi){
         int n=nums.size();
         int result=-1;
          while(low<=hi){
          int mid=low+((hi-low))/2 ;
          if(nums[mid]==target){
              return mid;
          }else if(nums[mid]>target){
              hi=mid-1;
          }else low=mid+1 ;
      }
      return -1;
    }
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        if (n == 0) return -1;
       int pivot=getPivot(nums,target);
       if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, target, pivot, n - 1);
        } else {
            return binarySearch(nums, target, 0, pivot - 1);
        }
    }
};