class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        preOrder(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        stringstream in(data);
        return deOrder(in);
    }
private:
    string res;
    
    void preOrder(TreeNode* root)
    {
        if (root == nullptr) 
        {
            res += "# "; return ;
        }
        res += to_string(root->val) + ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
    
    TreeNode* deOrder(stringstream& in) 
    {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deOrder(in);
        root->right = deOrder(in);   
        return root;
    }
};