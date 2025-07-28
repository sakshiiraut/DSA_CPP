class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>mp1,mp2;
        if(word1.size()!=word2.size()) return false;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        } 
        for(auto x:mp1){
            char ch=x.first;
            if(mp2.find(ch)==mp2.end()) return false;
        }
        unordered_map<int,int>m1,m2;
        for(auto it:mp1){
            m1[it.second]++;
        }
        for(auto it:mp2){
            m2[it.second]++;
        }
        for(auto h1:m1){
            int key=h1.first;
            if(m2.find(key)==m2.end()) return false;
            if(m1[key]!=m2[key]) return false;
        }
        return true;
    }
};