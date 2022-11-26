#!/usr/bin/python3
"""
Module to calculate the perimeter of an island
"""


def island_perimeter(grid) -> int:
    """
    Function to calculate the perimeter of an island
    Arguments:
        - grid is a list of list of integers:
            * 0 represents water
            * 1 represents land
            * Each cell is square, with a side length of 1.
            * Cells are connected horizontally/vertically
                (not diagonally).
            * grid is rectangular, with its width and height
                not exceeding 100
        - The grid is completely surrounded by water
        - There is only one island (or nothing).
        - The island doesn't have “lakes” (water inside that
            isn't connected to the water surrounding the island).
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 1, 0],
        [0, 1, 1, 0, 1, 0],
        [0, 1, 1, 1, 1, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
