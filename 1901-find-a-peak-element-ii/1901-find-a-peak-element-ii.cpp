class Solution {
public:

    int maxelement(vector<vector<int>>& arr, int row)
    {
        int m = arr[0].size();
        int maxel = INT_MIN;
        int index = -1;

        for(int i = 0; i < m; i++)
        {
            if(arr[row][i] > maxel)
            {
                maxel = arr[row][i];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int low = 0, high = n - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int col = maxelement(arr, mid);

            int up    = (mid - 1 >= 0) ? arr[mid - 1][col] : INT_MIN;
            int down  = (mid + 1 < n)  ? arr[mid + 1][col] : INT_MIN;
            if(arr[mid][col] > up && arr[mid][col] > down)
            {
                return {mid, col};
            }
            else if(up > arr[mid][col])
            {
                high = mid - 1;  
            }
            else
            {
                low = mid + 1;  
            }
        }

        return {-1, -1};
    }
};
