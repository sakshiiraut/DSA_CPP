class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // if(n==0) return 0;
        // int count=0;
        // int maxcount=0;
        // for(int i=0;i<n-1;i++){
        //     if(nums[i]==nums[i+1]) continue;
        //     else{
        //         if(nums[i]+1==nums[i+1]) {
        //         count++;
        //         maxcount=max(count,maxcount);
        //         }
        //         else count=0;
        //     }
        // }
        // return maxcount+1;

       int n=nums.size();
       int longsb=0;
       int cnt=1;
       set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            int x=it;
            cnt=1;
            if(st.find(x-1)==st.end()){
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
            }
            longsb=max(cnt,longsb);
        }
        return longsb;
    }
};