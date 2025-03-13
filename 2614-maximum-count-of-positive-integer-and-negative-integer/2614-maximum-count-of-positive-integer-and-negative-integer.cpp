class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
       int pos=0,negs=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0) negs++;
            else if(nums[i]>0) pos++;
        }
        return (pos>negs)?pos:negs ;
    }
};