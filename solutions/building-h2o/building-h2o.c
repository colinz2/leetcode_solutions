// @Title: Building H2O
// @Author: colinjxc
// @Date: 2022-02-12T15:24:25+08:00
// @URL: https://leetcode-cn.com/problems/building-h2o


typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mu;
    pthread_cond_t cond;
    int h_left;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    obj->h_left = 0;
    pthread_mutex_init(&obj->mu, NULL);
    pthread_cond_init(&obj->cond, NULL);
    return obj;
}

void hydrogen(H2O* obj) {
    pthread_mutex_lock(&obj->mu);
    while (obj->h_left == 2) {
      pthread_cond_wait(&obj->cond, &obj->mu);
    }
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    obj->h_left++;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mu);
}

void oxygen(H2O* obj) {
    pthread_mutex_lock(&obj->mu);
    while (obj->h_left < 2) {
        pthread_cond_wait(&obj->cond, &obj->mu);
    }
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    obj->h_left = 0;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mu);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    if (obj) {
      pthread_mutex_destroy(&obj->mu);
      pthread_cond_destroy(&obj->cond);
      free(obj);
    }
}
