class Solution {
public:
bool exist(vector<vector<char>>& board, string word) 
{
		if(board.empty())
			return false;
    
		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[0].size(); j++)
			{
				if(dfs(board, 0, i, j, word))
					return true;
			}
		}
    
    return false;
}

bool dfs(vector<vector<char>>&board, int idx, int i, int j, string& word)
{
    if(word.size() == idx)
        return true;
    
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx])
	return false;

    char temp = board[i][j];
    board[i][j] = ' '; //To show that we have visited this node
    
    bool res = dfs(board, idx+1, i+1, j, word) || dfs(board, idx+1, i-1, j, word) || dfs(board, idx+1, i, j+1, word) ||dfs(board, idx+1, i, j-1, word); //
    board[i][j] = temp;
    return res;
}
};