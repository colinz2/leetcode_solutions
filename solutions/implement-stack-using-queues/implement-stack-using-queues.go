// @Title: Implement Stack using Queues
// @Author: colinjxc
// @Date: 2021-08-11T11:21:07+08:00
// @URL: https://leetcode-cn.com/problems/implement-stack-using-queues


type MyStack struct {
    Stack []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        Stack: make([]int, 0, 100),
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.Stack = append(this.Stack, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    top := this.Top()
    this.Stack = this.Stack[:len(this.Stack) - 1]
    return top
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.Stack[len(this.Stack) - 1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.Stack) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
