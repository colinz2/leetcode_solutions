// @Title: Design Circular Queue
// @Author: colinjxc
// @Date: 2022-01-22T20:24:47+08:00
// @URL: https://leetcode-cn.com/problems/design-circular-queue


class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        cap_ = k;
        read_index_ = 0;
        write_index_ = 0;
        data_.resize(cap_);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        int index = write_index_++ % cap_;
        data_[index] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        read_index_++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        int index = read_index_ % cap_;
        return data_[index];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int index = (write_index_ - 1) % cap_;
        return data_[index];
    }
    
    bool isEmpty() {
        return read_index_ == write_index_;
    }
    
    bool isFull() {
        return write_index_ - read_index_ == cap_;
    }
private:
    int cap_;
    int read_index_;
    int write_index_;
    vector<int> data_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
