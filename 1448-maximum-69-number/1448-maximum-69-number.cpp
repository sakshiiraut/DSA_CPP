class Solution {
public:
    int maximum69Number (int num) {
       string str=to_string(num);
       string ans="";
       int count=0;
       for(int i=0;i<str.size();i++){
            if(count<1 && str[i]=='6'){
                ans+='9';
                count++;
            }
            else{
                ans+=str[i];
            }
       }
       int n=stoi(ans);
       return n; 
    }
};