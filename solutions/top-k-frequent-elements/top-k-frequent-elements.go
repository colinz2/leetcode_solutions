// @Title: Top K Frequent Elements
// @Author: colinjxc
// @Date: 2021-05-20T14:18:55+08:00
// @URL: https://leetcode-cn.com/problems/top-k-frequent-elements


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

