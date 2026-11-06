class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){
            return a[1]>b[1];
        });

        int total=0;
        for(int i=0;i<boxTypes.size();i++){
            int boxes=boxTypes[i][0];
            int units=boxTypes[i][1];
            int take=min(boxes,truckSize);
            total+=take*units;
            truckSize-=take;
        }
        return total;
    }
};