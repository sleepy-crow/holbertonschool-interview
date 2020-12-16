#!/usr/bin/python3

def canUnlockAll(boxes):
    leng = len(boxes)
    keys = [0]
    comp = [0]

    for i in range(0, leng):
        if len(boxes[i]) == 1:
            x = boxes[i]
            if (x > comp and x not in keys and x < leng):
                keys.append(x)
            else:
                pass
        elif len(boxes[i]) > 0:
            le = len(boxes[i])
            for j in range(0, le):
                x = boxes[i]
                if (x > comp and x not in keys and x < leng):
                    keys.append(boxes[i])
                else:
                    pass
        else:
            pass

    if len(keys) == len(boxes):
        return True
    else:
        return False