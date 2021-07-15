#!/usr/bin/python3
"""
Island Perimeter module
"""


def island_perimeter(grid):
    """Calculate perimeter of the island (grid)
    Args:
        grid ([[int]]): is a list of list of integers
    Return: perimeter of the island described in grid
    """
    rows = len(grid)
    columns = len(grid[0])
    perimeter = 0

    for i in range(0, rows):
        for j in range(0, columns):
            if grid[i][j] == 1:
                if (grid[i][j + 1] == 1 and grid[i][j - 1] == 1) and \
                   (grid[i + 1][j] == 1 or grid[i - 1][j] == 1):
                    perimeter += 1
                elif (grid[i][j + 1] == 1 or grid[i][j - 1] == 1) and \
                     (grid[i + 1][j] == 1 or grid[i - 1][j] == 1):
                    perimeter += 2
                elif (grid[i][j + 1] == 1 and grid[i][j - 1] == 1) or \
                     (grid[i + 1][j] == 1 and grid[i - 1][j] == 1):
                    perimeter += 2
                elif (grid[i][j + 1] == 1 or grid[i][j - 1] == 1) or \
                     (grid[i + 1][j] == 1 or grid[i - 1][j] == 1):
                    perimeter += 3
                else:
                    perimeter += 4
    return perimeter
