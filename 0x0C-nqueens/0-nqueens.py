#!/usr/bin/python3
"""Solving N Queens with Backtracing"""
from sys import argv, exit


def nqueens(n, y, board):
    """
    Method: nqueens - place n queens on an n
            by n board so that no queens are
            attacking any other piece on the
            board

    Parameters:
        n - number of queens
        y - current row
        board - current board
    Return: All possible solutions to
            placement, in list of lists form
    """
    for x in range(n):
        hold = 0
        for cell in board:
            if x == cell[1]:
                hold = 1
                break
            if y - x == cell[0] - cell[1]:
                hold = 1
                break
            if x - cell[1] == cell[0] - y:
                hold = 1
                break
        if hold == 0:
            board.append([y, x])
            if y == n - 1:
                print(board)
                del board[-1]
                break
            nqueens(n, y + 1, board)
            del board[-1]


if __name__ == '__main__':
    """
    Main guard - check for correct number of arguments and call nqueens
    """
    n = 0
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(argv[1])
    except Exception:
        print('N must be a number')
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)

    nqueens(n, 0, [])
