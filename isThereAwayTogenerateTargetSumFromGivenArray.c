#include "include/uthash.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct MEMO {
    long key;
    bool value;
    UT_hash_handle hh;
} memo_t;

/*
 * m = targetSum
 * n = arraySize
 * time: O(n^m)
 * space: O(n)
 * */
bool isThereAwayToGenerateTargetSumFromGivenArray(long targetSum, unsigned long *array,
                                                  unsigned long arraySize) {
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (unsigned long i = 0; i < arraySize; ++i) {
        long remainder = (long) (targetSum - array[i]);
        if (isThereAwayToGenerateTargetSumFromGivenArray(remainder, array, arraySize)) {
            return true;
        }
    }

    return false;
}

void *newMemoWithValues(long targetSum, bool value, memo_t **memo) {
    memo_t *newMemo = calloc(1, sizeof(memo_t));
    newMemo->value = value;
    newMemo->key = targetSum;
    HASH_ADD(hh, *memo, key, sizeof (long), newMemo);
}

/* m = targetSum
 * n = arraySize
 * time: O(mn)
 * space: O(m)
 * */
bool isThereAwayToGenerateTargetSumFromGivenArrayWithMemoizationObject(long targetSum,
                                                                       unsigned long *array,
                                                                       unsigned long arraySize,
                                                                       memo_t **memo) {
    memo_t *tmp;
    HASH_FIND(hh, *memo, &targetSum, sizeof (long), tmp);
    if (tmp != NULL) {
        return tmp->value;
    }
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (unsigned long i = 0; i < arraySize; ++i) {
        long remainder = (long) (targetSum - array[i]);
        if (isThereAwayToGenerateTargetSumFromGivenArrayWithMemoizationObject(remainder, array,
                                                                              arraySize, memo)) {
            /* no need to memoize since an early return is executed */
            return true;
        }
    }
    newMemoWithValues(targetSum, false, memo);
    return false;

}


bool memoizedIsThereAwayToGenerateTargetSumFromGivenArray(long targetSum, unsigned long *array,
                                                          unsigned long arraySize) {
    memo_t *memo  = NULL;
    return isThereAwayToGenerateTargetSumFromGivenArrayWithMemoizationObject(targetSum, array,
                                                                             arraySize, &memo);
}

/* Test arrays */
unsigned long arrayOne[1] = {2};
unsigned long arrayTwo[2] = {2, 4};
unsigned long arrayThree[3] = {2, 9, 6};
unsigned long arrayFour[4] = {2, 4, 7, 6};
unsigned long arrayFive[5] = {2, 4, 1, 9, 3};
unsigned long arrayTwoTwo[2] = {7, 14};


void isThereAwayToGenerateTargetSumFromGivenArrayTests() {
    assert(isThereAwayToGenerateTargetSumFromGivenArray(0, arrayOne, 1));
    assert(isThereAwayToGenerateTargetSumFromGivenArray(8, arrayTwo, 2));
    assert(isThereAwayToGenerateTargetSumFromGivenArray(7, arrayThree, 3) == false);
    assert(isThereAwayToGenerateTargetSumFromGivenArray(5, arrayFour, 4) == false);
    assert(isThereAwayToGenerateTargetSumFromGivenArray(16, arrayFive, 5));
    assert(isThereAwayToGenerateTargetSumFromGivenArray(1000, arrayFive, 2));
//    assert(isThereAwayToGenerateTargetSumFromGivenArray(300, arrayTwoTwo, 2));
    printf("All Tests Passed\n");
}


void memoizedIsThereAwayToGenerateTargetSumFromGivenArrayTests() {
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(0, arrayOne, 1));
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(8, arrayTwo, 2));
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(7, arrayThree, 3) == false);
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(5, arrayFour, 4) == false);
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(16, arrayFive, 5));
    assert(memoizedIsThereAwayToGenerateTargetSumFromGivenArray(300, arrayTwoTwo, 2) == false);
    printf("All memoized Tests Passed\n");
}

int main() { isThereAwayToGenerateTargetSumFromGivenArrayTests();
memoizedIsThereAwayToGenerateTargetSumFromGivenArrayTests();}
