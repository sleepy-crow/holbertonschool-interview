#!/usr/bin/python3
"""
function that calculates the quantity of water saved
"""


def rain(walls):
    """Calculate how much water will be retained after it rains."""
    if walls == None or len(walls) < 3:
        return 0

    if len(walls) == 3 and walls[-1] == 0:
        return 0

    water = 0
    wall1 = 0
    wall2 = 0
    pos = 0
    for i in walls:
        pos += 1
        if pos == len(walls):
            break
        if i > 0 and wall1 == 0:
            wall1 = i
        if wall1 > 0 and i > 0:
            wall2 = i
            if wall1 > wall2:
                water += wall2
            else:
                water += wall1
            wall1 = 0
            wall2 = 0

    return water
