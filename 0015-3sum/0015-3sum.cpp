class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n=nums.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     set<int>s;
        //     for(int j=i+1;j<n;j++){
        //          int target=-(nums[i]+nums[j]);
        //          if(s.find(target)!=s.end()){
        //            vector<int> temp = {nums[i], nums[j], target};
        //            sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //          }
        //          s.insert(nums[j]);
        //     }
        // }
        // return vector<vector<int>>(st.begin(), st.end());
        int n=nums.size();
        int sum=0;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int>a1={nums[i],nums[j],nums[k]};
                    ans.push_back(a1);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};