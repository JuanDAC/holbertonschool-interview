#!/usr/bin/python3

'''
Given a number n, write a method that calculates
the fewest number of operations needed to result in
exactly n H characters in the file.
'''


def findIterations(n, result, index):
    '''
    returns min operations to get n Hs
    '''
    if n % index == 0:
        n, result = findIterations(n / index, result + index, index)
    return (n, result)


def minOperations(n, result=0, index=2):
    '''
    returns min operations to get n Hs
    '''

    if n < 2 and result == 0:
        return 0

    if index < (n + 1):
        n, result = findIterations(n, result, index)
        return minOperations(n, result, index + 1)
    return result


if __name__ == '__main__':

    n = 4
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

    n = 12
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
