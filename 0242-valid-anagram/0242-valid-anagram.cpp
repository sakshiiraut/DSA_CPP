class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t) return true;
        // return false;
        //seccond method-
         if (s.size() != t.size()) return false;
        unordered_map<int,int>mp;
         unordered_map<int,int>mt;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mt[t[i]]++;
        }
       for (auto p : mp) {
            char ch = p.first;
            int count = p.second;
            if (mt[ch] != count) return false;
        }
        return true;
         }
};