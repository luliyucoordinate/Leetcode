class Node 
{
public:
    Node() : wordId(-1) {}
    ~Node()
    {
        for (const auto& item : next) 
            delete item.second; 
    }

    unordered_map<char, Node*> next;
    int wordId;
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        r = board.size(), c = board[0].size();
        Node* root = new Node();
        for (int i = 0; i < words.size(); i++)
        {
            auto node = root;
            for (auto ch : words[i])
            {
                if (!node->next.count(ch)) node->next[ch] = new Node();
                node = node->next[ch];
            }
            node->wordId = i;
        }
        
        
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                dfs(i, j, root, board, words);
            }
        }
        return res;
    }
    
private:
    int r, c;
    vector<string> res;
    const int dire[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(int i, int j, Node* node, vector<vector<char>>& board, vector<string>& words)
    {
        if (i < 0 || i >= r || j < 0 || j >= c ||
           !node->next.count(board[i][j])) return;
        auto tmp = board[i][j];
        board[i][j] = '$';
        node = node->next[tmp];
        if (node->wordId != -1) {
            res.push_back(words[node->wordId]);
            node->wordId = -1;
        }

        for (auto& it : dire) {
            int nx = it[0] + i, ny = it[1] + j;
            dfs(nx, ny, node, board, words);
        }
        board[i][j] = tmp;
    }
};