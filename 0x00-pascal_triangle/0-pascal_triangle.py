#!/usr/bin/python3
""" Module with a function that returns pascal triangle """


def pascal_triangle(n):
    """ function pascal triangle generator """
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
