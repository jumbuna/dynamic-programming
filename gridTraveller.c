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
unsigned long gridTraveller(int rows, int columns) {
    if (!rows || !columns) return 0;
    if (rows + columns == 2) return 1;
    return /*bottom*/ gridTraveller(rows - 1, columns) + /* right*/ gridTraveller(rows, columns - 1);
}

char *rowCommaColumn(int rows, int columns) {
    char tmp[10];
    sprintf(tmp, "%i,%i", rows, columns);
    return tmp;
}

/* time:  space: */
unsigned long gridTravellerWithMemoizationObject(int rows, int columns, memo_t **memo) {
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
    memccpy(newMemo->rowCommaColumn, rowCommaColumn(rows, columns), 10, sizeof(char));
    memccpy(newMemo2->rowCommaColumn, rowCommaColumn(columns, rows), 10, sizeof(char));
    newMemo2->value = newMemo->value = /*bottom*/ gridTravellerWithMemoizationObject(rows - 1, columns, memo) + /* right*/ gridTravellerWithMemoizationObject(rows, columns - 1, memo);
    HASH_ADD_STR(*memo, rowCommaColumn, newMemo);
    HASH_ADD_STR(*memo, rowCommaColumn, newMemo2);
    return newMemo->value;
}

unsigned long memoizedGridTraveller(int rows, int columns) {
    memo_t *memo = NULL;
    return gridTravellerWithMemoizationObject(rows, columns, &memo);
}


void gridTravellerTests() {
    assert(gridTraveller(1, 1) == 1);
    assert(gridTraveller(0, 2) == 0);
    assert(gridTraveller(2, 3) == 3);
    assert(gridTraveller(3, 3) == 6);
    printf("All grid traveller Tests passed \n");
}

void memoizedGridTravellerTests() {
    assert(memoizedGridTraveller(1, 1) == 1);
    assert(memoizedGridTraveller(0, 2) == 0);
    assert(memoizedGridTraveller(2, 3) == 3);
    assert(memoizedGridTraveller(3, 3) == 6);
    assert(memoizedGridTraveller(4, 4) == 20);
    printf("All memoized grid traveller Tests passed \n");
}


int main() {
    gridTravellerTests();
    memoizedGridTravellerTests();
    printf("%lu", memoizedGridTraveller(18, 18));
}