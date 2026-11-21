class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);

        // Pass 1: Find the closest matching ancestor for each node
        auto dfsFindParents = [&](auto& self, int u) -> void {
            int charIdx = s[u] - 'a';
            int prevAncestor = lastSeen[charIdx];

            if (prevAncestor != -1) {
                newParent[u] = prevAncestor;
            }

            lastSeen[charIdx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            lastSeen[charIdx] = prevAncestor; // Backtrack
        };

        dfsFindParents(dfsFindParents, 0);

        // Build the updated tree
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        // Pass 2: Calculate subtree sizes on the final tree
        vector<int> ans(n, 1);
        auto dfsSubtreeSize = [&](auto& self, int u) -> int {
            for (int v : newAdj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        dfsSubtreeSize(dfsSubtreeSize, 0);
        return ans;
    }
};
