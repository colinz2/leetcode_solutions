
# [最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof)

## 题目描述

<p>输入整数数组 <code>arr</code> ，找出其中最小的 <code>k</code> 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,1], k = 2
<strong>输出：</strong>[1,2] 或者 [2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [0,1,2,1], k = 1
<strong>输出：</strong>[0]</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= arr.length &lt;= 10000</code></li>
	<li><code>0 &lt;= arr[i]&nbsp;&lt;= 10000</code></li>
</ul>


## 题解

### cpp [🔗](zui-xiao-de-kge-shu-lcof.cpp) 
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::vector<int> res;
        if (k == 0) return res;
        std::priority_queue<int, std::vector<int>, std::less<int>> pq;

        for (auto v : arr) {
            if (pq.size() < k) {
                pq.push(v);
            } else {
                if (pq.top() > v) {
                    pq.pop();
                    pq.push(v);
                }
            }
        }
        while (pq.size() > 0) {
            res.emplace_back(pq.top());
            pq.pop();
        }

        return res;      
    }
};
```
### golang [🔗](zui-xiao-de-kge-shu-lcof.go) 
```golang

// max heap
type Pq struct {
    v []int
}

func NewPq(size int) *Pq {
    return &Pq{
        v : make([]int, 1, size + 1),
    }
}

func (p *Pq) shiftUp() {
    cur := len(p.v) - 1
    for {
        if cur == 1 {
            break
        }

        f := cur / 2
        if (p.v[cur] > p.v[f]) {
            p.v[f], p.v[cur] = p.v[cur], p.v[f]
            cur = f
        } else {
            break
        }
    }
}

func (p *Pq) shiftDown() {
    p.v[1] = p.v[p.Size()]
    p.v = p.v[0 : p.Size()]
    curr := 1
    for {
        c := curr << 1
        if c >= p.Size() {
            break
        }

        if p.v[c] < p.v[c + 1] {
            c++
        }

        if p.v[curr] < p.v[c] {
            p.v[curr], p.v[c] = p.v[c], p.v[curr]
            curr = c
        } else {
            break
        }

    }
}

func (p *Pq) Size() int {
    return len(p.v) - 1
}

func (p *Pq) Push(k int) {
    p.v = append(p.v, k)
    p.shiftUp()
}

func (p *Pq) Pop() int {
    v := p.Top()
    p.shiftDown()
    return v
}

func (p *Pq) Top() int {
    return p.v[1]
}

func (q *Pq) Empty() bool {
    return q.Size() == 0
}


func getLeastNumbers(arr []int, k int) []int {
    res := make([]int, 0, k)
    if k == 0 {
        return []int{}
    }
    pq := NewPq(k)

    for _, v := range arr {
        if pq.Size() < k {
            pq.Push(v)
        } else {
            if v < pq.Top() {
                pq.Pop()
                pq.Push(v)
            }
        } 
    }

    for pq.Size() != 0 {
        res = append(res, pq.Pop())
    }

    return res
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [分治](../../tags/divide-and-conquer.md) 
- [快速选择](../../tags/quickselect.md) 
- [排序](../../tags/sorting.md) 
- [堆（优先队列）](../../tags/heap-priority-queue.md) 


## 相似题目



## Links

- [Prev](../shan-chu-lian-biao-de-jie-dian-lcof/README.md) 
- [Next](../lian-xu-zi-shu-zu-de-zui-da-he-lcof/README.md) 

