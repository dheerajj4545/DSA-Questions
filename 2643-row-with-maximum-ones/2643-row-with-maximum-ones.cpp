class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_ones = 0;
        int index = 0;

        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                cnt += mat[i][j];
            }

            if (cnt > max_ones) {
                max_ones = cnt;
                index = i;
            }
        }

        return {index, max_ones};
    }
};