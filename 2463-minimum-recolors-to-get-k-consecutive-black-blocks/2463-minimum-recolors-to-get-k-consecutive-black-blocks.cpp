class Solution {
public:
    int minimumRecolors(string blocks, int k) {
         int n=blocks.size();
         int minCount=INT_MAX;
         for(int i=0;i<=n-k;i++){
              int count=0;
             for(int j=i;j<i+k;j++){
                if(blocks[j]=='W'){ 
                count++;
                }
             }
             minCount=min(count,minCount);
         }
         return minCount;
     }
};