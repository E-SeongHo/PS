class Solution {
public:
    int N;
    
    pair<int, int> getCoords(int n)
    {
        n = n-1;
        int row = n / N;
        int column = n % N;
        
        pair<int, int> ret;
        if(row % 2 == 0) ret = make_pair(N-1-row, column);
        else ret = make_pair(N-1-row, N-1-column);
        
        return ret;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        N = board.size();
        queue<pair<int, int>> q; // {dist, n}
        q.push({0, 1});
        
        vector<bool> visited(N*N+1, false);
        visited[1] = true;
        
        while(!q.empty())
        {
            auto elem = q.front(); q.pop();
            int dist = elem.first;
            int num = elem.second;
            
            if(num == N*N) return dist;
            
            for(int i = 1; i <= 6; i++)
            {
                int next = num + i;
                if(next > N*N) break;
                
                auto coords = getCoords(next);
                if(board[coords.first][coords.second] != -1)
                {
                    next = board[coords.first][coords.second];
                }
                
                if(!visited[next])
                {
                    q.push({dist+1, next});
                    visited[next] = true;
                }
            }
        }
        
        return -1;
    }
};