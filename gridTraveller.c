#include "include/uthash.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* limitation: grid with cell count of less than 9999*9999  */
typedef struct MEMO {
    char rowCommaColumn[10];
    unsigned long value;
    UT_hash_handle hh;
} memo_t;

/* time: 2^(rows+columns) space: (rows+columns) */
unsigned long
howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(int rows, int columns) {
    if (!rows || !columns) return 0;
    if (rows + columns == 2) return 1;
    return /*bottom*/
            howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                    rows - 1, columns) + /* right*/
           howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   rows, columns - 1);
}

char arr[10];

char *rowCommaColumn(int rows, int columns) {
    sprintf(arr, "%i,%i", rows, columns);
    return arr;
}

/* time:  space: */
unsigned long
howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsWithMemoizationObject(int rows, int columns, memo_t **memo) {
    char *rcc = rowCommaColumn(rows, columns);
    memo_t *tmp;
    HASH_FIND_STR(*memo, rcc, tmp);
    if (tmp != NULL) {
        return tmp->value;
    }
    if (!rows || !columns) return 0;
    if (rows + columns == 2) return 1;
    memo_t *newMemo = calloc(1, sizeof(memo_t));
    memo_t *newMemo2 = calloc(1, sizeof(memo_t));
    strcpy(newMemo->rowCommaColumn, rcc);
    strcpy(newMemo2->rowCommaColumn, rowCommaColumn(columns, rows));
    newMemo2->value = newMemo->value = /*bottom*/
            howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsWithMemoizationObject(
                    rows - 1, columns, memo) + /* right*/
            howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsWithMemoizationObject(
                    rows, columns - 1, memo);
    HASH_ADD_STR(*memo, rowCommaColumn, newMemo);
    HASH_ADD_STR(*memo, rowCommaColumn, newMemo2);
    return newMemo->value;
}

unsigned long
memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(int rows, int columns) {
    memo_t *memo = NULL;
    return howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsWithMemoizationObject(
            rows, columns, &memo);
}


void howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsTests() {
    assert(howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   1, 1) == 1);
    assert(howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   0, 2) == 0);
    assert(howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   2, 3) == 3);
    assert(howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   3, 3) == 6);
    printf("All grid traveller Tests passed \n");
}

void memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsTests() {
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   1, 1) == 1);
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   0, 2) == 0);
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   2, 3) == 3);
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   3, 3) == 6);
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   4, 4) == 20);
    assert(memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensions(
                   18, 18) == 2333606220);
    printf("All memoized grid traveller Tests passed \n");
}


int main() {
    howManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsTests();
    memoizedHowManyWaysAreThereToNavigateFromTopLeftCornerToBottomRightCornerInGridWithGivenDimensionsTests();
}