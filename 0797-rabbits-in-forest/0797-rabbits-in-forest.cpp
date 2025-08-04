class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int>mp;
       int n=answers.size();
       for(int i=0;i<n;i++){
        mp[answers[i]]++;
       } 
       int ans=0;
       for(auto it:mp){
        int x=it.first;
        int freq=it.second;
        int groupSize=x+1;
        int groups=(freq+x)/groupSize ;
        ans+=groupSize*groups; 
       }
      return ans;
    }
};