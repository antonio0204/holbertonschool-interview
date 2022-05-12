#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """calculates the fewest number of operations needed
    to result in exactly n H characters in the file"""
    pp = ""
    final = "H"
    o = 0

    while len(final) < n:

        if len(final) * 2 <= n and n % len(final) == 0:
            pp = final
            o += 1
            # print("CA")

        final += pp
        o += 1
        # print("P")
        # print(final)

    # print(final, len(final))
    if len(final) != n:
        return 0
    return o
