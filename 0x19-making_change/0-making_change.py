#!/usr/bin/python3
import math
"""
Making Change
"""


def makeChange(coins, total):
    """
    function that makes change
    """

    if (total <= 0):
        return 0

    if (len(coins) == 0):
        return -1

    coins.sort()

    change = 0
    length = len(coins) - 1
    left = total
    subtotalC = 0

    while (length > 0):
        change += math.floor(left / coins[length])
        currentC = math.floor(left / coins[length])
        subtotalC += coins[length] * currentC
        left = left % coins[length]
        length -= 1

    if (subtotalC != total):
        return -1

    return change
