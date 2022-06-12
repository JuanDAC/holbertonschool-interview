#!/usr/bin/python3
from typing import List
"""
Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total.
"""


def makeChange(coins: List[int], total: int, acumulated: int = 0, ordered: bool = False):
    """
    Prototype: def makeChange(coins, total)
    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total is 0 or less, return 0
    """
    if len(coins) == 0 and total > 0:
        return -(acumulated + 1)

    if len(coins) == 0:
        return 0

    if not ordered:
        coins.sort(reverse=True)

    biggest, *leftover = coins

    if type(total) is not int or type(biggest) is not int:
        return -1

    if total == 0:
        return 0

    possibleAmount = (total // biggest)

    if possibleAmount == 0:
        return makeChange(leftover, total, acumulated)

    nextTotal = (total % biggest)
    nextChanges = possibleAmount + \
        makeChange(leftover, nextTotal, acumulated + possibleAmount, ordered)
    if nextChanges == -1:
        nextChanges = makeChange(leftover, total, acumulated, ordered)
    return nextChanges


if __name__ == '__main__':
    print(makeChange([1, 2, 25], 37))
    print(makeChange([1256, 54, 48, 16, 102], 1453))
    print(makeChange([2, 21], 26))
