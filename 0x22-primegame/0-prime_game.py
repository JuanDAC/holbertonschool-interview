#!/usr/bin/python3
""" Prime Game """

import math


def is_prime(n):
    """ Check if n is a prime number """
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if not n % i:
            return False
    return True


def primes_until(n):
    """Return a list of prime numbers until n"""
    return [i for i in range(2, n+1) if is_prime(i)]


def isWinner(x, nums):
    """ x is the number of rounds and nums is an array of n
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None """
    score = {"Maria": 0, "Ben": 0}
    for round in range(x):
        primes = primes_until(nums[round])
        _sum = len(primes)
        if (_sum % 2):
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            score[winner] += 1

    if score["Maria"] > score["Ben"]:
        return "Maria"

    elif score["Ben"] > score["Maria"]:
        return "Ben"

    return None
