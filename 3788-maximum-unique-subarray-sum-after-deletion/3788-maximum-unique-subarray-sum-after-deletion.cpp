class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int Sum=0;
        for(auto s:st){
            if(s>0) Sum+=s;
        }
        if(Sum==0){
           int maxEle=INT_MIN;
            for(auto s:st){
              maxEle=max(s,maxEle);
        }
        return maxEle;
        }
         return Sum;
    }
};