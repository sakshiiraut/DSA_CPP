bool cmp(vector<int>&p1,vector<int>&p2){
  return p1[1]>p2[1] ;
}
class Solution {
public:
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(),boxTypes.end(),cmp);
      int n=boxTypes.size();
      int result=0;
      for(int i=0;i<n;i++){
        if(boxTypes[i][0]<=truckSize){
            result+=boxTypes[i][0]*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
        }else{
            result+=truckSize*boxTypes[i][1];
            truckSize=0;
        }
       if(truckSize==0) break;
      }
      return result;
    }
};