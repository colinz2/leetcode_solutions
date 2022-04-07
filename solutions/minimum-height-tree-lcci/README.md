
# [最小高度树](https://leetcode-cn.com/problems/minimum-height-tree-lcci)

## 题目描述

<p>给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。</p><strong>示例:</strong><pre>给定有序数组: [-10,-3,0,5,9],<br><br>一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：<br><br>          0 <br>         / &#92 <br>       -3   9 <br>       /   / <br>     -10  5 <br></pre>

## 题解

### cpp [🔗](minimum-height-tree-lcci.cpp) 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size(), nums);
    }

    TreeNode* helper(int left, int right, vector<int>& nums) {
        if (left >= right) return nullptr; 
        int mid = (left + right) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(left, mid, nums);
        node->right = helper(mid+1, right, nums);

        return node;
    }
};
```


## 相关话题

- [树](../../tags/tree.md) 
- [二叉搜索树](../../tags/binary-search-tree.md) 
- [数组](../../tags/array.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [二叉树](../../tags/binary-tree.md) 


## 相似题目



## Links

- [Prev](../linked-list-cycle-lcci/README.md) 
- [Next](../sum-lists-lcci/README.md) 

