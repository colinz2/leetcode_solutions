
# [数据流的第 K 大数值](https://leetcode-cn.com/problems/jBjn9C)

## 题目描述

<p>设计一个找到数据流中第 <code>k</code> 大元素的类（class）。注意是排序后的第 <code>k</code> 大元素，不是第 <code>k</code> 个不同的元素。</p>

<p>请实现 <code>KthLargest</code>&nbsp;类：</p>

<ul>
	<li><code>KthLargest(int k, int[] nums)</code> 使用整数 <code>k</code> 和整数流 <code>nums</code> 初始化对象。</li>
	<li><code>int add(int val)</code> 将 <code>val</code> 插入数据流 <code>nums</code> 后，返回当前数据流中第 <code>k</code> 大的元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
[&quot;KthLargest&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;, &quot;add&quot;]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
<strong>输出：</strong>
[null, 4, 5, 5, 8, 8]

<strong>解释：</strong>
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= val &lt;= 10<sup>4</sup></code></li>
	<li>最多调用 <code>add</code> 方法 <code>10<sup>4</sup></code> 次</li>
	<li>题目数据保证，在查找第 <code>k</code> 大元素时，数组中至少有 <code>k</code> 个元素</li>
</ul>

<p>&nbsp;</p>

<p><meta charset="UTF-8" />注意：本题与主站 703&nbsp;题相同：&nbsp;<a href="https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/">https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/</a></p>


## 题解

### cpp [🔗](jBjn9C.cpp) 
```cpp
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (auto n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (pq_.size() < k_) {
            pq_.push(val);
        } else {
            if (pq_.top() < val) {
                pq_.pop();
                pq_.push(val);
            }
        }
        return pq_.top();
    }
private:
    int k_;
    std::priority_queue<int, vector<int>, greater<int>> pq_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```


## 相关话题

- [树](https://leetcode-cn.com/tag/tree) 
- [设计](https://leetcode-cn.com/tag/design) 
- [二叉搜索树](https://leetcode-cn.com/tag/binary-search-tree) 
- [二叉树](https://leetcode-cn.com/tag/binary-tree) 
- [数据流](https://leetcode-cn.com/tag/data-stream) 
- [堆（优先队列）](https://leetcode-cn.com/tag/heap-priority-queue) 


## 相似题目



## Links

- [Prev](../opLdQZ/README.md) 
- [Next](../N6YdxV/README.md) 

