class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(101,0);
        for(int i=0;i<logs.size();i++){
            diff[logs[i][0]-1950]++;
            diff[logs[i][1]-1950]--;
        }
        int ans=1950,maxpop=diff[0];
        for(int i=1;i<101;i++){
             diff[i]+=diff[i-1];
             if(diff[i]>maxpop){
                maxpop=diff[i];
                ans=1950+i;
             }
        }
        return ans;
    }
};