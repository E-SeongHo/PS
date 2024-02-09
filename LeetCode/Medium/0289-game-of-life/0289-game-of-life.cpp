class Solution {
public:
    vector<int> dx = {-1, 0, +1, -1, +1, -1, 0, +1};
    vector<int> dy = {-1, -1, -1, 0, 0, +1, +1, +1};
    int m, n;
    
    int countNeighbors(int y, int x, vector<vector<int>>& board)
    {
        int cnt = 0;
        for(int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < m && nx >= 0 && nx < n)
            {
                if(board[ny][nx] == 1) cnt++;
            }
        }
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        m = board.size(); n = board[0].size();
        
        vector<vector<int>> next(m, vector<int>(n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cnt = countNeighbors(i, j, board);
                bool live = board[i][j];
                
                auto& state = next[i][j];
                if(live)
                {
                    if(cnt < 2 || cnt > 3) state = 0;
                    else state = 1;
                }
                else
                {
                    if(cnt == 3) state = 1;
                }
            }
        }
        
        board = next;
    }
};