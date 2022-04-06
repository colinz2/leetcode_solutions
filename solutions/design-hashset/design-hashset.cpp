// @Title: Design HashSet
// @Author: colinjxc
// @Date: 2022-01-22T17:53:44+08:00
// @URL: https://leetcode-cn.com/problems/design-hashset


class MyHashSet {
public:
    const size_t Kcap = 4096;

    int hash(int key) {
        return key % Kcap;
    }

public:
    MyHashSet() {
        v_.resize(Kcap);
    }
    
    void add(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                return;
            }
        }
        list.push_front(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                list.erase(it);
                break;
            }
        }
        // 可以用 erase 删除 iterator
        //list.remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        auto& list = v_[index];
        for (auto it = list.begin(); it != list.end(); it++) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }
private:
    std::vector<std::list<int>> v_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
