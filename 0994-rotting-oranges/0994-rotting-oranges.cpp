class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j <m ;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty() && fresh){
            int sz = q.size();
            cnt++;
            while(sz--){
                auto [i,j] = q.front(); q.pop();
                for(auto& d:dir){
                    int ni = i + d.first;
                    int nj= j +d.second;
                

                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        q.push({ni,nj});
                        fresh--;
                    }
                }
            }
        }
        if(fresh == 0){
            return cnt;
        }
        return -1;

    }
};