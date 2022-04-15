#!/usr/bin/python3
"""
Module that contain a function with a return of a pascal triangle.
Module that contain a function with a return of a pascal triangle.
"""


def second_last(matrix):
    """
    Return the second last index.
    Return the second last index.
    """
    return matrix[len(matrix) - 2]


def top_left(matrix, index):
    """
    Return the top left index of current value.
    Return the top left index of current value.
    """
    return second_last(matrix)[index - 1]


def top_right(matrix, index):
    """
    Return the top right index of current value.
    Return the top right index of current value.
    """
    return second_last(matrix)[index]


def pascal_triangle(n):
    """
    Returns pascal triangle with n height.
    Returns pascal triangle with n height.
    """
    if n <= 0:
        return []

    row = list(range(n))
    row[-1] = row[0] = 1
    triangle = [*pascal_triangle(n - 1), row]

    if len(row) < 3:
        return triangle

    for i in range(1, len(row) - 1):
        row[i] = top_left(triangle, i) + top_right(triangle, i)
    return triangle
