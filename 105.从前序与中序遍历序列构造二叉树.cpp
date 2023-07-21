// 每一个先序遍历中的元素都可以当作root结点，然后再中序遍历中寻找此root结点所在的位置(index)，以root结点分离左右子树
// 再每个类的元素加上“this->”可以极大的运行效率
class Solution {
public:
    // 前序遍历的迭代器
    int pre_idx = 0;
	// 拷贝一份先序遍历数组，之后会用
    vector<int> pre;
	// idx_map存放中序遍历 元素->元素索引 的映射
    map<int,int> idx_map;
    TreeNode* helper(int in_left,int in_right)
    {
        // 中序遍历不能再依靠index分离出左右子树
        if(in_left == in_right)
            return NULL;
        
		// root结点的值
		int root_val = this->pre[this->pre_idx];
		// 构造root结点
		TreeNode* root = new TreeNode(root_val);


		// 找到index
		auto iter = idx_map.find(root_val);
		int index = iter->second;
        
		// 下一个root
        pre_idx++;

		// 分别构造左右子树，index为root结点
        root->left = helper(in_left,index); // [in_left, index)
        root->right = helper(++index,in_right); // [index+1, right)
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;        
        
        // 构造map，储存中序遍历的值和位置
        int idx = 0;
        for(auto i = inorder.begin(); i!=inorder.end(); i++){
            idx_map.insert(pair<int,int>(*i,idx++));
        }        
        return helper(0,inorder.size());        
    }
};