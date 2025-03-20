class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
 vector<vector<pair<int, int>>> adj(n);
        vector<int> component(n, -1);
        vector<int> minAndCost(n, INT_MAX);

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Find connected components and compute minimum AND cost per component
        int compId = 0;
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                queue<int> q;
                q.push(i);
                component[i] = compId;
                int andValue = INT_MAX;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto& [neighbor, weight] : adj[node]) {
                        if (component[neighbor] == -1) {
                            component[neighbor] = compId;
                            q.push(neighbor);
                        }
                        andValue &= weight;  // Compute minimum AND cost in the component
                    }
                }

                minAndCost[compId] = andValue;
                compId++;
            }
        }

        // Answer queries in O(1)
        vector<int> result;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] == component[t]) {
                result.push_back(minAndCost[component[s]]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};