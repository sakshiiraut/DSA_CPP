class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         int i=0;
         int j=0;
         vector<vector<int>>v;
         for(int i=0;i<numRows;i++){
            vector<int>ans;
            for(int j=0;j<i+1;j++){
                if(i==j || j==0){
                    ans.push_back(1);
                }
                else ans.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v.push_back(ans);
         }
         return v;
    }
};