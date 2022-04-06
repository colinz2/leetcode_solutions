// @Title: Fizz Buzz Multithreaded
// @Author: colinjxc
// @Date: 2022-02-11T01:06:57+08:00
// @URL: https://leetcode-cn.com/problems/fizz-buzz-multithreaded


typedef struct {
    int n;
    pthread_barrier_t barrier;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    pthread_barrier_init(&obj->barrier, NULL, 4);
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 == 0 && i%5 != 0) {
        printFizz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 != 0 && i%5 == 0) {
        printBuzz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%15 == 0) {
        printFizzBuzz();
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    for (int i = 1; i <= obj->n; i++) {
      if (i%3 != 0 && i%5 != 0) {
        printNumber(i);
      }
      pthread_barrier_wait(&obj->barrier);
    }
}

void fizzBuzzFree(FizzBuzz* obj) {
  if (obj) {
    pthread_barrier_destroy(&obj->barrier);
    free(obj);
  }   
}
