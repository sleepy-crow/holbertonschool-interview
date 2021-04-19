#!/usr/bin/python3
"""
function that calculates the quantity of water saved
"""


def rain(walls):
    """Calculate how much water will be retained after it rains."""
    if not len(walls) or len(walls) < 3:
        return 0

    if len(walls) == 3 and walls[-1] == 0:
        return 0

    if len(walls) < 1:
        return 0

    rainWater = 0

    for element in range(len(walls)):
        first = walls[element]
        for wal in range(element):
            first = max(first, walls[wal])
        last = walls[element]
        for wal in range(element + 1, len(walls)):
            last = max(last, walls[wal])
        rainWater += (min(first, last) - walls[element])
    return rainWater
