class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        int j=0;
        string str="";
        string t="";
        for(int i=0;i<n;i++){
          if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
            str.push_back(s[i]);
          }
        }
        sort(str.begin(),str.end());
        for(int i=0;i<n;i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U'){
              t.push_back(str[j]);
              j++;
          }else{
            t.push_back(s[i]);
          }
        }
        return t;
    }
};