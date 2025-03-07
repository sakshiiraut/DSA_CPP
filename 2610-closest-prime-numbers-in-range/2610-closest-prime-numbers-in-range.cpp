class Solution {
public:
 bool primeNo(int n){
    bool flag=true;
    if (n <= 1) return false;
    if(n==2) return true;
    for(int i=2;i * i <= n;i++){
        if(n%i==0){
           return false;
        }
    }
    return true;
 }
    vector<int> closestPrimes(int left, int right) {
        vector<int>v;
        int minGap=INT_MAX;
        int Gap=INT_MAX;
        int l=-1,r=-1,prev=-1;
        for(int i=left;i<=right;i++){
            if (primeNo(i)) {
                if (prev != -1) { // Ensure there is a previous prime to compare with
                    int gap = i - prev;
                    if (gap < minGap) {
                        minGap = gap;
                        l = prev;
                        r = i;
                    }
                }
                prev = i;
            }
        }
        if(l!=-1 && r!=-1){
            v.push_back(l);
             v.push_back(r);
        }else {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};