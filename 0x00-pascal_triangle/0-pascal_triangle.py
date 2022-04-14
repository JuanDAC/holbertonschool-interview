#!/usr/bin/python3
"""
0-main
"""


def pascal_triangle(n):
    """ Pascal triangle generator """
    if n <= 0:
        return []

    row = list(range(n))
    row[-1] = row[0] = 1
    pascal = [*pascal_triangle(n - 1), row]

    if len(row) < 3:
        return pascal
    for i in range(1, len(row) - 1):
        second_last = len(pascal) - 2
        top_left = pascal[second_last][i - 1]
        top_right = pascal[second_last][i]
        row[i] = top_left + top_right
    return pascal


if __name__ == "__main__":

    def print_triangle(triangle):
        """
        Print the triangle
        """
        for row in triangle:
            print("[{}]".format(",".join([str(x) for x in row])))
    print_triangle(pascal_triangle(5))
