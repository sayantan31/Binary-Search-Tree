/*
Given a binary tree, return all root-to-leaf paths.
*/

/*
vector<string> BTree::binaryTreePaths() {

        return binaryTreePaths(root);
}

vector<string> BTree::binaryTreePaths(TreeNode* node) {

        string tmp;
        vector<string> result;
        
        buildString(node, tmp, result);

        return result;        

}

void BTree::buildString(TreeNode* node, string tmp, vector<string>& result) {

        if(root == NULL) {
                return;
        }

        if(tmp.empty()) {
                tmp = to_string(root->val);
        }
        else {
                tmp = tmp + "->" + to_string(node->val);
        }

        if(node->left == NULL && node->right == NULL) {
                result.push_back(tmp);
        }

        buildString(node->left,tmp,result); 
        buildString(node->right,tmp,result); 
} 
*/ 
 

