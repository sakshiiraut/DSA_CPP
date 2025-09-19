class Solution {
public:
    bool ispallindrome(string ans){
        int left=0;
        int right=ans.size()-1;
        while(left<=right){
            if(ans[left]==ans[right]) {
                left++;
                right--;
            }else return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
       int n=s.size();
       string ans="";
       for(int i=0;i<n;i++){
        if(((int(s[i])>=97) && (int(s[i])<=122)) ||((int(s[i])>=48) && (int(s[i])<=57))  ) ans+=s[i];
        else if((int(s[i])>=65) && (s[i]<=90)){
             int it=int(s[i])+32;
             ans+=char(it);
        }else continue;
       }  
       return ispallindrome(ans);
    }
};