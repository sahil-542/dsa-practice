class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&visited,vector<int>&pathVis){
        if(pathVis[node]) return true;

        if(visited[node]) return false;
        visited[node] = 1;
        pathVis[node] = 1;

        for(auto adjNode : graph[node]){
            if(dfs(adjNode,graph,visited,pathVis)){
                pathVis[node] = 0;
                 return true;
            }
        }
        pathVis[node] = 0;
        return false;
       
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>safe;
        for(int i =0;i<n;i++){
            vector<int>visited(n,0);
            vector<int>pathVis(n,0);

            if(!dfs(i,graph,visited,pathVis)){
                safe.push_back(i);
            }
        }
        return safe;
    }
};