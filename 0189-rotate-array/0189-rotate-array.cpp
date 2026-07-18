class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k = k % n;
        vector<int>temp(k+1);
        for (int i = n - k; i < n; i++) {
            temp[i - n + k] = arr[i];
        }
        for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    
    }
};