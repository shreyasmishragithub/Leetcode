class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size (), m = matrix[0].size ();
        vector<vector<int>> mat (n, vector<int> (m));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += matrix[i][j];
                mat[i][j] = sum;
            }
        }
        
        int ans = INT_MIN;
        for (int k = 0; k < n; k++) {            
            for (int i = k; i < n; i++) {
                        
                vector<int> vec;
                for (int j = 0; j < m; j++) {
                    if (k > 0) {
                        mat[i][j] -= mat[k-1][j];
                    }
                    vec.push_back (mat[i][j]);
                }
                set<int> st;
                int sum = 0;
                for (int i = 0; i < vec.size (); i++) {
                    
                    sum += vec[i];
                    
                    if (sum <= target) {
                        //cout << sum << " ";
                        ans = max (ans, sum);
                    }
                    auto it = st.lower_bound (sum-target);
                    if (it != st.end ()) {
                        //cout << sum-(*it);
                        ans = max (ans, sum-(*it));
                    }
                    st.insert (sum);
                }
                //cout << endl;
            }
        }
        return ans;
    }
};