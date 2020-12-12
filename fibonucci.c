#include "include/uthash.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MEMO {
    __unused unsigned  long key;
    unsigned long value;
    UT_hash_handle hh;
} memo_t;

/* time: O(2^n) space: O(n)*/
unsigned long findNthNumberInFibonociSequence(unsigned long n) {
    return n <= 2 ? 1
                  : (findNthNumberInFibonociSequence(n - 1) +
                     findNthNumberInFibonociSequence(n - 2));
}

/* time: O(n) space: O(n)*/
unsigned long findNthNumberInFibonociSequenceWithMemoizationObject(unsigned long n, memo_t **memo) {
        memo_t *temp;
        HASH_FIND(hh, *memo, &n, sizeof(unsigned long), temp);
        if (temp != NULL) {
            return temp->value;
        }
    if(n <= 2) return 1;
    memo_t *newMemo = calloc(1, sizeof(memo_t));
    newMemo->key = n;
    newMemo->value =
            (findNthNumberInFibonociSequenceWithMemoizationObject(n - 1, memo) +
             findNthNumberInFibonociSequenceWithMemoizationObject(n - 2, memo));
    HASH_ADD(hh, *memo, key, sizeof(unsigned long), newMemo);
    return newMemo->value;
}

unsigned long findNthNumberInFibonociSequenceWithMemoization(unsigned long n) {
    memo_t *memo = NULL;
    return findNthNumberInFibonociSequenceWithMemoizationObject(n, &memo);
}

void fibTests() {
    assert(findNthNumberInFibonociSequence(5) == 5);
    assert(findNthNumberInFibonociSequence(6) == 8);
    assert(findNthNumberInFibonociSequence(7) == 13);
    assert(findNthNumberInFibonociSequence(8) == 21);
    printf("All Fibonoci Tests passed\n");
}

void memoizedFibTests() {
    assert(findNthNumberInFibonociSequenceWithMemoization(5) == 5);
    assert(findNthNumberInFibonociSequenceWithMemoization(6) == 8);
    assert(findNthNumberInFibonociSequenceWithMemoization(7) == 13);
    assert(findNthNumberInFibonociSequenceWithMemoization(8) == 21);
    printf("All Memoization Fibonoci Tests passed\n");
}

int main() {
    fibTests();
    memoizedFibTests();
    printf("%lu", findNthNumberInFibonociSequenceWithMemoization(100));
}
