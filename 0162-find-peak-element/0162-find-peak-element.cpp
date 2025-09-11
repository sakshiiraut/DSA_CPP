class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    //     int n=nums.size();
    //     if (n == 1) return 0; 
    //     int ans=-1;
    //     for(int i=1;i<n-1;i++){
    //        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
    //         ans=i;
    //         break;
    //        }
    //     }
    //     if(ans==-1){
    //         if(nums[0]>nums[1]) return 0;
    //         else if(nums[n-1]>nums[n-2]) return n-1;
    //     }
    //   return ans;
    int n=nums.size();
    int i=1;
    int j=n-2;
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    while(i<=j){
        int mid=i+(j-i)/2 ;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
        else if(nums[mid]>nums[mid-1]) i=mid+1;
        else j=mid-1;
    }
    return -1;
    }
};