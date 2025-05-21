class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

         vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        for(; i<n ; i++){
            // case 1 
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }

        res.push_back(newInterval);

        for(; i < n ; i++){
            res.push_back(intervals[i]);

        }

        return res;
        
    }
};