class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int count=1;
        string ans="";
        ans+=s[0];
        for(int i=1;i<n;i++){
               if(s[i-1]==s[i]){
                if(count>=2) continue;
                else{
                    ans+=s[i];
                    count++;
                }
               } else{
                count=1;
                ans+=s[i];
               }
        }
        return ans;
    }
};