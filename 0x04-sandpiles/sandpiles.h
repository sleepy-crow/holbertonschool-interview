#ifndef SANDPILES
#define SANDPILES
/* libraries used */ 
#include <stdlib.h>
#include <stdio.h>

/* functions */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
/** Balances a grid (1 iteration) */
void balance_grid(int grid[3][3]);

/** Determines if a grid is balanced */
int is_balanced(int grid[3][3]);

#endif