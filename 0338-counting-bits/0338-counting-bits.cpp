class Solution {
public:
   int countBit(int num){
    int count=0;
    while(num>0){
        count++;
        num=(num&(num-1));
    }
    return count;
   }
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i=0;i<n+1;i++){
            v[i]=countBit(i);
        }
        return v;
    }
};