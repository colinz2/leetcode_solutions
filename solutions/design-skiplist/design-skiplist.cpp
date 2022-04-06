// @Title: Design Skiplist
// @Author: colinjxc
// @Date: 2022-03-14T12:03:22+08:00
// @URL: https://leetcode-cn.com/problems/design-skiplist


#define kMaxLevel 16
#define N 999

struct Node {
  int key;
  vector<Node*> next;

  Node* Next(int level) {
      return next[level];
  }

  void SetNext(int level, Node* node) {
      next[level] = node;
  }

  int NextSize() {
      return next.size();
  }

  Node(int val, int maxlevel) : key(val), next(maxlevel, nullptr) {};
};

class Skiplist {
 private:
  int max_height_;
  Node* head_;

 public:
  Skiplist() : max_height_(1) {
    head_ = new Node(0, kMaxLevel);
    srand(0);
  }

  Node* findGreaterOrEqual(const int key, Node* prev[] = nullptr) {  // for insert
    Node* ptr = head_;
    int level = max_height_ - 1;
    while (true) {
      Node* next = ptr->Next(level);
      if (next != nullptr && next->key < key) {
        // same level
        ptr = next; 
      } else {
        if (prev != nullptr) prev[level] = ptr;
        if (level == 0) {
          return next;
        } else {
          level--;
        }
      }
    }
  }

  int getRandLevel(float factor = 0.5) {
    int level = 1;
    while ((rand() % N) / N > factor && level < kMaxLevel) {
      level++;
    }
    return level;
  }

  bool search(int target) {
    Node* temp = findGreaterOrEqual(target);
    if (temp && temp->key == target) {
      return true;
    } else {
      return false;
    }
  }

  void add(int num) {
    Node* prev[kMaxLevel];
    findGreaterOrEqual(num, prev);
    int randlevel = getRandLevel();
    if (randlevel > max_height_) {
      for (int i = max_height_ - 1; i < randlevel; i++) {
        prev[i] = head_;
      }
      max_height_ = randlevel;
    }
    Node* newNode = new Node(num, randlevel);
    for (int i = 0; i < max_height_; i++) {
      newNode->SetNext(i, prev[i]->Next(i));
      prev[i]->SetNext(i, newNode);
    }
  }

  bool erase(int num) {
    Node* prev[kMaxLevel];
    Node* temp = findGreaterOrEqual(num, prev);
    if (temp == nullptr || temp->key != num) {
      return false;
    }

    for (int i = 0; i < temp->NextSize(); i++) {
      prev[i]->SetNext(i, temp->Next(i));
    }
    delete temp;
    while (max_height_ > 1 && head_->Next(max_height_ - 1) == nullptr) {
        max_height_--; 
    }
    return true;
  }
};

