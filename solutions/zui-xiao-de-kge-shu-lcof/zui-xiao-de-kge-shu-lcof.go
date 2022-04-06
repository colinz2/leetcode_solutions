// @Title: 最小的k个数  LCOF
// @Author: colinjxc
// @Date: 2021-11-02T21:02:26+08:00
// @URL: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof



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
