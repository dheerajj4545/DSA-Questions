class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<long long>ans(n,-1);
        vector<int>cnt(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(auto& [v, d] : adj[0]) {
            pq.push({d, v});
        }
        ans[0]=0;
        while(!pq.empty()){
            auto [t,v]=pq.top();
            pq.pop();
            if(ans[v] != -1) continue;
            cnt[v]++;
            if(cnt[v] >= requiredSignals[v]){
                ans[v] = t;

                for(auto [w, d] : adj[v]){
                    if(ans[w] == -1 ) pq.push({t + d, w});
                }
            }
        }
        return ans;
    }
};