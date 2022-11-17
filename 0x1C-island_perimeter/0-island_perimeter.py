#!/usr/bin/python3


from typing import List, Dict


def perimeter(grid: List[List[int]], islands: Dict[str, bool], i: int, j: int, width: int, height: int) -> int:
    if not grid:
        return 0

    if grid[i][j] == 1:
        key = '%d, %d' % (i, j)

        if (islands.get(key, False)):
            return 0

        current_perimeter = 0
        islands[key] = True

        measures = [width, height]
        structures = [grid, islands]

        if (0 if i-1 == -1 else grid[i-1][j]):
            current_perimeter += perimeter(*structures, i-1, j, *measures)
        if (0 if i-1 == height else grid[i+1][j]):
            current_perimeter += perimeter(*structures, i+1, j, *measures)
        if (0 if j-1 == -1 else grid[i][j-1]):
            current_perimeter += perimeter(*structures, i, j-1, *measures)
        if (0 if j-1 == width else grid[i][j+1]):
            current_perimeter += perimeter(*structures, i, j+1, *measures)

        perimeter_value = int(not (0 if i-1 == -1 else grid[i-1][j])) \
            + int(not (0 if i-1 == len(grid) else grid[i+1][j])) \
            + int(not (0 if j-1 == -1 else grid[i][j-1])) \
            + int(not (0 if j-1 == len(grid[i]) else grid[i][j+1]))

        return current_perimeter + perimeter_value

    return 0


def island_perimeter(grid: List[List[int]]) -> int:

    if not grid:
        return 0

    x = -1
    y = -1
    width = len(grid[0])
    height = len(grid)
    while x == -1 and y < height:
        y += 1
        try:
            x = grid[y].index(1)
        except Exception:
            x = -1
    islands = dict()
    value = perimeter(grid, islands, y, x, width, height)
    return value


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 1, 0, 1, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
