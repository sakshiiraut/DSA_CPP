class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res="1";
        for(int i=2;i<=n;i++){
            string curr="";
            int count=1;
            for(int j=1;j<res.size();j++){
                if(res[j]==res[j-1]){
                    count++;
                }else{
                    curr += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            curr += to_string(count) + res.back();
            res=curr;
        }
        return res;
    }
};