class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
         vector<vector<int>>res;
        int k=0;
        while(i<n && j<m){
               if(nums1[i][0]<nums2[j][0]) {
                res.push_back({nums1[i][0],nums1[i][1]});
                i++;
                }
               else if(nums1[i][0]==nums2[j][0]) {
                res.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                 j++;
               }else{
                res.push_back({nums2[j][0],nums2[j][1]});
                j++;
               }
        }
      if(i==n){
        while(j<m){
             res.push_back({nums2[j][0],nums2[j][1]});
                j++;
        }
      }
      if(j==m){
        while(i<n){
       res.push_back({nums1[i][0],nums1[i][1]});
       i++;
        }
      }
       return res;
    }
};