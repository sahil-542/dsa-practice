class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> color(V, -1);

        queue<int>q;

        for(int i =0;i<graph.size();i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;
                while(!q.empty()){

                    int node = q.front();
                    q.pop();

                    for(int i=0;i<graph[node].size();i++){
                        if(color[graph[node][i]] == -1){
                            color[graph[node][i]] = (color[node]+1)%2;
                            q.push(graph[node][i]);
                        }
                        else{
                            if(color[node] == color[graph[node][i]]) return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};