class Solution {
public:

    void bfs(int i,vector<int> Lst[], vector<int>& visited){
      queue<int> q;
      q.push(i);
      visited[i]=1;
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:Lst[node]){
              if(!visited[it]){
                  q.push(it);
                  visited[it]=1;
              }
          }
      }
  }      
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> Lst[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    Lst[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,Lst,vis);
                count++;
            }
        }
        return count;
    }
};
