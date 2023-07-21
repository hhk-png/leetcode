// ÿһ����������е�Ԫ�ض����Ե���root��㣬Ȼ�������������Ѱ�Ҵ�root������ڵ�λ��(index)����root��������������
// ��ÿ�����Ԫ�ؼ��ϡ�this->�����Լ��������Ч��
class Solution {
public:
    // ǰ������ĵ�����
    int pre_idx = 0;
	// ����һ������������飬֮�����
    vector<int> pre;
	// idx_map���������� Ԫ��->Ԫ������ ��ӳ��
    map<int,int> idx_map;
    TreeNode* helper(int in_left,int in_right)
    {
        // �����������������index�������������
        if(in_left == in_right)
            return NULL;
        
		// root����ֵ
		int root_val = this->pre[this->pre_idx];
		// ����root���
		TreeNode* root = new TreeNode(root_val);


		// �ҵ�index
		auto iter = idx_map.find(root_val);
		int index = iter->second;
        
		// ��һ��root
        pre_idx++;

		// �ֱ�������������indexΪroot���
        root->left = helper(in_left,index); // [in_left, index)
        root->right = helper(++index,in_right); // [index+1, right)
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;        
        
        // ����map���������������ֵ��λ��
        int idx = 0;
        for(auto i = inorder.begin(); i!=inorder.end(); i++){
            idx_map.insert(pair<int,int>(*i,idx++));
        }        
        return helper(0,inorder.size());        
    }
};