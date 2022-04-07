
# [](https://leetcode-cn.com/problems/house-robber-iii)

## 题目描述



## 题解

### python3 [🔗](house-robber-iii.py) 
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        def rob_(root):
            if root == None:
                return 0, 0
            ls, ln = rob_(root.left)
            rs, rn = rob_(root.right)
            return root.val + ln + rn, max(ls, ln) + max(rs, rn)

        return max(rob_(root))    

```


## 相关话题



## 相似题目



## Links

- [Prev](../odd-even-linked-list/README.md) 
- [Next](../counting-bits/README.md) 

