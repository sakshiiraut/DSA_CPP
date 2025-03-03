class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans1;
        vector<int>ans2;
        vector<int>ans3;
        int n=nums.size();
        for(int i=0;i<n;i++){
                if(nums[i]<pivot){
                    ans1.push_back(nums[i]);
                }else if(nums[i]>pivot){
                    ans2.push_back(nums[i]);
                } else{
                    ans3.push_back(nums[i]);
            }
        }
        int n1=ans1.size();
        int n2=ans2.size();
        int n3=ans3.size();
        for(int i=0;i<n3;i++){
            ans1.push_back(ans3[i]);
        }
        for(int i=0;i<n2;i++){
            ans1.push_back(ans2[i]);
        }
        return ans1;
    }
};