
# [前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements)

## 题目描述

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，请你返回其中出现频率前 <code>k</code> 高的元素。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>nums = [1,1,1,2,2,3], k = 2
<strong>输出: </strong>[1,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>nums = [1], k = 1
<strong>输出: </strong>[1]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>k</code> 的取值范围是 <code>[1, 数组中不相同的元素的个数]</code></li>
	<li>题目数据保证答案唯一，换句话说，数组中前 <code>k</code> 个高频元素的集合是唯一的</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你所设计算法的时间复杂度 <strong>必须</strong> 优于 <code>O(n log n)</code> ，其中 <code>n</code><em> </em>是数组大小。</p>


## 题解

### cpp [🔗](top-k-frequent-elements.cpp) 
```cpp
class Solution {
public:
    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k) {
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);

        int pivot = v[start].second;
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (v[i].second >= pivot) {
                swap(v[++index], v[i]);
            }
        }
        swap(v[start], v[index]);

        if (k <= index - start) {
            // have TOP(index-start+1), big then K
            qsort(v, start, index - 1, ret, k);
        } else {
            // have TOP(index-start+1), but small than K, take them all
            for (int i = start; i <= index; i++) {
                ret.push_back(v[i].first);
            }
            if (k > index - start + 1) {
                qsort(v, index + 1, end, ret, k - (index - start + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (auto& v: nums) {
            freqs[v]++;
        }

        vector<int> ret;
        vector<pair<int, int>> values(freqs.begin(), freqs.end());
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }
};

```
### golang [🔗](top-k-frequent-elements.go) 
```golang
func topKFrequent(nums []int, k int) []int {
	var res []int
	pq := PriorityQueue{}
	heap.Init(&pq)

	m := make(map[int]int)
	for _, n := range nums {
		m[n]++
	}

	for k, v := range m {
		heap.Push(&pq, &Item{
			key:   k,
			value: v,
		})
	}

	for len(res) != k {
		t := heap.Pop(&pq)
		if t == nil {
			break
		}
		item := t.(*Item)
		res = append(res, item.key)
	}
	return res
}

type Item struct {
	key   int
	value int
}

// PriorityQueue 实现堆接口
type PriorityQueue []*Item

func (p *PriorityQueue) Push(x interface{}) {
	*p = append(*p, x.(*Item))
}

func (p *PriorityQueue) Pop() interface{} {
	l := len(*p)
	if l == 0 {
		return nil
	}
	item := (*p)[l-1]
	*p = (*p)[:l-1]
	return item
}

func (p PriorityQueue) Len() int {
	return len(p)
}

func (p PriorityQueue) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p PriorityQueue) Less(i, j int) bool {
	return p[i].value > p[j].value
}

```


## 相关话题

- [数组](../../tags/array.md) 
- [哈希表](../../tags/hash-table.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [桶排序](../../tags/bucket-sort.md) 
- [计数](../../tags/counting.md) 
- [快速选择](../../tags/quickselect.md) 
- [排序](../../tags/sorting.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目

- [数组中的第K个最大元素](../kth-largest-element-in-an-array/README.md)  [Medium] 
- [根据字符出现频率排序](../sort-characters-by-frequency/README.md)  [Medium] 
- [前K个高频单词](../top-k-frequent-words/README.md)  [Medium] 


## Links

- [Prev](../moving-average-from-data-stream/README.md) 
- [Next](../intersection-of-two-arrays/README.md) 

