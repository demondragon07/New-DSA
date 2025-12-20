class Solution {
public:
bool static cmp(vector<int>&a, vector<int>&b){
    return a[1]>b[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int n=boxTypes.size();
        int Totalval=0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                Totalval+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }else{
                Totalval+=boxTypes[i][1]*truckSize;
                break;
            }
        }
        return Totalval;
    }
};