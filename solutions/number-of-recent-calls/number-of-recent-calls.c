// @Title: Number of Recent Calls
// @Author: colinjxc
// @Date: 2022-01-31T18:19:21+08:00
// @URL: https://leetcode-cn.com/problems/number-of-recent-calls


typedef struct Node {
    struct Node* next;
    struct Node* pre;
    int time;
} Node;

typedef struct {
    struct Node* head;
    struct Node* tail;
    int size;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* c = (RecentCounter*)malloc(sizeof(RecentCounter));
    c->head = (Node*)malloc(sizeof(Node));
    c->tail = (Node*)malloc(sizeof(Node));
    c->head->pre = NULL;
    c->head->next = c->tail;
    c->tail->pre = c->head;
    c->tail->next = NULL;
    c->size = 0;
    return c;
}

int recentCounterPing(RecentCounter* obj, int t) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->time = t;
    node->pre = obj->tail->pre;
    node->next = obj->tail;
    obj->tail->pre->next = node;
    obj->tail->pre = node;
    obj->size++;

    while (obj->head->next->time + 3000 < t && obj->size != 0) {
        obj->size--;
        Node* dnode = obj->head->next;
        obj->head->next = dnode->next;
        dnode->next->pre = obj->head;
        free(dnode);
    }
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    while (obj->head->next != obj->tail) {
        Node* dnode = obj->head->next;
        obj->head->next = dnode->next;
        dnode->next->pre = obj->head;
        free(dnode);
    }
    free(obj->head);
    free(obj->tail);  
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
