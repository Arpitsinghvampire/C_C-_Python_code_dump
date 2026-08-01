vector<int> bellman(vector<vector<pair<int,int>>> &adj)
{
    int V = adj.size();

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int wt = edge.second;

                if (dist[u] != INT_MAX &&
                    dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Negative cycle detection
    for (int u = 0; u < V; u++)
    {
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if (dist[u] != INT_MAX &&
                dist[u] + wt < dist[v])
            {
                cout << "Negative weight cycle exists\n";
            }
        }
    }

    return dist;
}
