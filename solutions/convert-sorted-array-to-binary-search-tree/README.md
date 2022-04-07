
# [](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree)

## 题目描述



## 题解

### cpp [🔗](convert-sorted-array-to-binary-search-tree.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = (l+r)/2;
        auto node = new TreeNode(nums[m]);
        node->right = dfs(nums, m+1, r);
        node->left = dfs(nums, l, m-1);
        return node;
    }
};
```
### python3 [🔗](convert-sorted-array-to-binary-search-tree.py) 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def build(nums:List[int], l:int, r:int) -> TreeNode:
            if l > r:
                return None
            m = (l+r)>>1
            return TreeNode(nums[m], build(nums, l, m-1), build(nums, m+1, r))
        
        return build(nums, 0, len(nums)-1)
```


## 相关话题



## 相似题目



## Links

- [Prev](../binary-tree-level-order-traversal-ii/README.md) 
- [Next](../convert-sorted-list-to-binary-search-tree/README.md) 

