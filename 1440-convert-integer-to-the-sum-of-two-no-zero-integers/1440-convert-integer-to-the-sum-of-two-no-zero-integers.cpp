class Solution {
public:
    vector<int> getdigit(int n){
        vector<int>ans;
        while(n>0){int rem=n%10;
        ans.push_back(rem);
        n=n/10;}
        return ans;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>v1;
        vector<int>v2;
        for(int i=1;i<n;i++){
            int a=n-i;
            v1=getdigit(a);
            v2=getdigit(i);
            auto it = std::find(v1.begin(), v1.end(), 0);
            auto it2=std::find(v2.begin(), v2.end(), 0);
            if(it == v1.end() && it2==v2.end()){
                return {a, i};
            }else{
                continue;
            }
        }
       return {};
    }
};