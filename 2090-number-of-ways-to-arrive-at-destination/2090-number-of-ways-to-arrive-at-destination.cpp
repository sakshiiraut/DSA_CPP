class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Adjacency list representation
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Min-heap priority queue (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        vector<long long> dist(n, LLONG_MAX);  // Stores shortest time to reach each node
        vector<int> ways(n, 0);  // Stores number of ways to reach each node with shortest time
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node]) continue;  // Skip if outdated entry

            for (auto [neighbor, travelTime] : adj[node]) {
                long long newTime = currTime + travelTime;

                // Found a shorter path to neighbor
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    ways[neighbor] = ways[node];
                    pq.push({newTime, neighbor});
                }
                // Found another way with the same shortest time
                else if (newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};
