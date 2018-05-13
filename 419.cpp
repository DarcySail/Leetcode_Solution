class Solution {
public:
	vector<vector<bool>> visited;

    int countBattleships(vector<vector<char>>& board) 
	{
		int result = 0;
		for(int i = 0; i < board.size(); ++i)
		{
			visited.push_back(vector<bool>());
			for(int j = 0; j < board[i].size(); ++j)
			{
				if(board[i][j] == 'X')
					visited[i].push_back(true);
				else
					visited[i].push_back(false);
			}
		}

		for(int i = 0; i < board.size(); ++i)
			for(int j = 0; j < board[i].size(); ++j)
				result += dfs(i, j);
		return result;
    }

	int dfs(int x, int y)
	{
		if(!visited[x][y])
			return 0;
		visited[x][y] = false;
		if(x > 0)
			dfs(x - 1, y);
		if(x < visited.size() - 1)
			dfs(x + 1, y);
		if(y > 0)
			dfs(x, y - 1);
		if(y < visited[x].size() - 1)
			dfs(x, y + 1);
		return 1;
	}

};