// @Title: Print in Order
// @Author: colinjxc
// @Date: 2022-02-10T21:13:13+08:00
// @URL: https://leetcode-cn.com/problems/print-in-order


typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool first_ok;
    bool second_ok;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    

    // Initialize user defined data here.
    obj->first_ok = false;
    obj->second_ok = false;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();

    
    obj->first_ok = true;
    pthread_cond_broadcast(&obj->cond);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->mutex);
    while (!obj->first_ok) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();

    obj->second_ok = true;
    pthread_mutex_unlock(&obj->mutex);
    pthread_cond_signal(&obj->cond);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->mutex);
    while (!obj->second_ok) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&obj->mutex);

}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    if (obj != NULL) {
        pthread_mutex_destroy(&obj->mutex);
        pthread_cond_destroy(&obj->cond);
        free(obj);
    }
}
