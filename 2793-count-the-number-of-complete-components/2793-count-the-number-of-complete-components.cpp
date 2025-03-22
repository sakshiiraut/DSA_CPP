#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int completeComponents = 0;
        
        // Function to perform BFS and check if component is complete
        auto bfs = [&](int start) {
            queue<int> q;
            q.push(start);
            visited[start] = true;
            unordered_set<int> component;
            component.insert(start);
            
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        component.insert(neighbor);
                    }
                }
            }
            
            // Check if the component is a complete graph
            int size = component.size();
            for (int node : component) {
                if (adj[node].size() != size - 1) return false;
            }
            return true;
        };
        
        // Iterate over all nodes and process unvisited ones
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (bfs(i)) completeComponents++;
            }
        }
        
        return completeComponents;
    }
};

