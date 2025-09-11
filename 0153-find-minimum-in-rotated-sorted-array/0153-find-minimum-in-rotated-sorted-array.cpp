class Solution {
public:
int getpivot(vector<int>&nums){
    int i=0;
    int n=nums.size();
    int j=nums.size()-1;
    while(i<j){
        int mid=i+(j-i)/2 ;
        if(nums[mid]>nums[n-1]){
            i=mid+1;
        }else{
            j=mid;
        }
    }
    return i;
}
    int findMin(vector<int>& nums) {
        int pivot=getpivot(nums);
        return nums[pivot];
    }
};