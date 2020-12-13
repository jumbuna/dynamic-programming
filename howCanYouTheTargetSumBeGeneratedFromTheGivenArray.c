#include "include/uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


long emptyArray[1] = {0};

typedef struct MEMO {
    long key;
    long *array;
    UT_hash_handle hh;
} memo_t;

/*
 * m = targetSum
 * n = arraySize
 *
 * time: O(n^m + m)
 * space: O(m)
 * */
long *howCanTheTargetSumBeGeneratedFromTheGivenArray(long targetSum, long *array, long arraySize) {
    if (targetSum == 0) return emptyArray;
    if (targetSum < 0) return NULL;

    for (long x = 0; x < arraySize; x++) {
        long remainder = targetSum - array[x];
        long *tmp;
        if ((tmp = howCanTheTargetSumBeGeneratedFromTheGivenArray(remainder, array, arraySize))) {
            if (tmp[0] == 0) {
                tmp = calloc(2, sizeof(long));
                tmp[0] = 0;
            } else {
                /* cater for the extra space for storing the array length */
                tmp = realloc(tmp, sizeof(long)*(tmp[0] + 2));
            }
            tmp[0] += 1;
            tmp[tmp[0]] = array[x];
            return tmp;
        }
    }

    return NULL;
}

void newMemoObject(long targetSum, long *array, memo_t **memo) {
    memo_t *newMemo = calloc(1, sizeof (memo_t));
    newMemo->key = targetSum;
    newMemo->array = array;
    HASH_ADD(hh, *memo, key, sizeof(long), newMemo);
}

/*
 * m = targetSum
 * n = arraySize
 * 
 * time: O(m * n^2 + n)
 * space: O(m^2)
 * */
long *howCanTheTargetSumBeGeneratedFromTheGivenArrayWithMemoizationObject(long targetSum, long
                                                                                                *array, long arraySize, memo_t **memo) {
    memo_t *tmpMemo;
    HASH_FIND(hh, *memo, &targetSum, sizeof(long), tmpMemo);
    if (tmpMemo != NULL) {
        return tmpMemo->array;
    }
    if (targetSum == 0) return emptyArray;
    if (targetSum < 0) return NULL;

    for (long x = 0; x < arraySize; x++) {
        long remainder = targetSum - array[x];
        long *tmp;
        if ((tmp = howCanTheTargetSumBeGeneratedFromTheGivenArrayWithMemoizationObject(remainder,
                                                                                       array,
                                                                                       arraySize,
                                                                                       memo))) {
            if (tmp[0] == 0) {
                tmp = calloc(2, sizeof(long));
                tmp[0] = 0;
            } else {
                /* cater for the extra space for storing the array length */
                tmp = realloc(tmp, sizeof(long)*(tmp[0] + 2));
            }
            tmp[0] += 1;
            tmp[tmp[0]] = array[x];
            newMemoObject(targetSum, tmp, memo);
            return tmp;
        }
    }
    newMemoObject(targetSum, NULL, memo);
    return NULL;
}

long *memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArray(long targetSum, long *array, long
                                                                                                  arraySize) {
    memo_t *memo = NULL;
    return howCanTheTargetSumBeGeneratedFromTheGivenArrayWithMemoizationObject(targetSum, array,
                                                                               arraySize, &memo);
}

/* Test arrays */
long arrayOne[1] = {2};
long arrayTwo[2] = {2, 4};
long arrayThree[3] = {2, 9, 6};
long arrayFour[4] = {2, 4, 7, 6};
long arrayFive[5] = {2, 4, 1, 9, 3};
long arrayTwoTwo[2] = {7, 14};

long sumOfGivenArray(const long *array) {
    if (array == NULL) return -1;
    long sum = 0;
    for(long x = 1; x <= array[0]; x++) {
        sum += array[x];
    }
    //may free the array here
    /*if (array[0] != 0) {
        free(array);
    }*/
    return sum;
}


void howCanTheTargetSumBeGeneratedFromTheGivenArrayTests() {
    assert(sumOfGivenArray(howCanTheTargetSumBeGeneratedFromTheGivenArray(10, arrayTwo, 2)) == 10);
    assert(sumOfGivenArray(howCanTheTargetSumBeGeneratedFromTheGivenArray(7, arrayThree, 3)) != 7);
    assert(sumOfGivenArray(howCanTheTargetSumBeGeneratedFromTheGivenArray(21, arrayFour, 4)) == 21);
//    assert(sumOfGivenArray(howCanTheTargetSumBeGeneratedFromTheGivenArray(300, arrayTwoTwo, 2))
//           == -1);
    printf("All Tests Passed\n");
}

void memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArrayTests() {
    assert(sumOfGivenArray(memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArray(10, arrayTwo, 2))
           ==
           10);
    assert(sumOfGivenArray(memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArray(7, arrayThree, 3)
                           ) !=
           7);
    assert(sumOfGivenArray(memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArray(21, arrayFour, 4))
           ==
           21);
    assert(sumOfGivenArray(memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArray(300, arrayTwoTwo,
                                                                                2))
           == -1);
    printf("All memoized Tests Passed\n");
}

int main() {
    howCanTheTargetSumBeGeneratedFromTheGivenArrayTests();
    memoizedHowCanTheTargetSumBeGeneratedFromTheGivenArrayTests();
}
