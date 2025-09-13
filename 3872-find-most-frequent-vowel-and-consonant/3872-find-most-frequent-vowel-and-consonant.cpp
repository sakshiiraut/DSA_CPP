class Solution {
public:
    int maxFreqSum(string s) {
     unordered_map<char,int>mp1;
     unordered_map<char,int>mp2;
     for(int i=0;i<s.size();i++){
        if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
            mp1[s[i]]++;
        }else{
             mp2[s[i]]++;
        }
    }
    int max1=0;
    int max2=0;
        for(auto it:mp1){
            if(it.second>max1) max1=it.second ;
        }
        for(auto it:mp2){
            if(it.second>max2) max2=it.second ;
        }
        return max1+max2;
    }
};