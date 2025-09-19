class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string sr=strs[i];
            sort(sr.begin(),sr.end());
            if(mp.find(sr) == mp.end()){
                vector<string>res;
                res.push_back(strs[i]);
                mp[sr]=res;
            }else{
                mp[sr].push_back(strs[i]);
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            vector<string>v;
            v=it.second;
            ans.push_back(v);
        }
        return ans;
    }
};