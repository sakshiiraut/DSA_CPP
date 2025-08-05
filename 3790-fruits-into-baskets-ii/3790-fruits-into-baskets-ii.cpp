class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();
        vector<int>isvisited(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isvisited[j]==0 && baskets[j]>=fruits[i]){
                 { isvisited[j]=1;
                 break;}   
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(isvisited[i]==0) count++;
        }
        return count;
    }
};