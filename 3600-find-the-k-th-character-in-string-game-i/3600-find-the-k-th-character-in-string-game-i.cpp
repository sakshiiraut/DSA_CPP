// class Solution {
// public:
//     char kthCharacter(int k) {
//     string s="a";
//     while(s.size()<=k){
//         string temp="";
//         for(int i=0;i<s.size();i++){
//            if(s[i]<'z') temp+=char(s[i] + 1);
//            else temp+='a';
//         }
//         s+=temp;
//     } 
//     return s[k-1];
//     }
// };
class Solution {
public:
    char kthCharacter(int k) {
       int x=__builtin_popcount(k-1);
       return 'a'+x;
    }
};