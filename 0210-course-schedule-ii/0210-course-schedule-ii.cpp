class Solution {
public:

    bool dfs(int node,
             vector<int>& vis,
             stack<int>& st,
             vector<vector<int>>& adj) {

        vis[node] = 1; // visiting

        for(auto neigh : adj[node]) {

            if(vis[neigh] == 1)
                return true; // cycle found

            if(vis[neigh] == 0) {
                if(dfs(neigh, vis, st, adj))
                    return true;
            }
        }

        vis[node] = 2; // visited
        st.push(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        stack<int> st;

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(dfs(i, vis, st, adj))
                    return {};
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};