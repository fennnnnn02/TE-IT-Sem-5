vector<int> bellmanFord(vector<vector<int>>,int src, int V){
    
    // Step 1 - Creating a V sized array/vector,
    // and initializing it with a very big value.
    
    vector<int> dis(V,INT_MAX); // Creating a vector dis of size V with values as INT_MAX.
    dis[src] = 0; // Since we are already on source vertex, we can reach it within no time.
    
    // Step 2 - For V-1 times, traversing over,
    // all the edges and checking if a shorter
    // path between any edge u to v is possible. 
    int u,v,wt;
    for(int i=0;i<V-1;i++) // Iterating V-1 times 
    {
        for(int j=0;j<edges.size();j++) // Iterating over all the edges. 
        {
            u = edges[j][0]; // Source vertex.
            v = edges[j][1]; // Destination vertex.
            wt = edges[j][2];// Weight of the edge. 
            
            // If we can reach v from u in less time it 
            // is currently required to reach v then update 
            // the value.
            if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
                dis[v] = dis[u] + wt;
        }
    }
    
    // Step 3 - Checking for negative edge weight cycle, 
    // by checking if the underliying condition satifies.
    for(int j=0;j<edges.size();j++)
    {
        u = edges[j][0];
        v = edges[j][1];
        wt = edges[j][2];
        // If the below condition satisfies, it means negative 
        // edge weight cycle exists. Because traversing again 
        // is reducing the cost and in order to minimize the 
        // cost we can traverse till infinity and hence a proper 
        // answer can't be calculated. 
        if(dis[u]!=INT_MAX && dis[v] > dis[u] + wt)
            return {};
    }
    return dis; // returning our answer vector/array.
}