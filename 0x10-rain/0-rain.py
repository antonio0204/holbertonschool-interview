#!/usr/bin/python3
"""
Rain Problem Solution
"""


def rain(walls):
    """
    Prototype: def rain(walls)
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    Assume that the ends of the list (before index 0 and after index walls[-1])
    are not walls, meaning they will not retain water.
    If the list is empty return 0.
    """
    n = len(walls)
    if n == 0:
        return 0
    length = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        length = length + (min(left, right) - walls[i])

    return length
