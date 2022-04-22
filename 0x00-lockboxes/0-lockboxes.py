#!/usr/bin/env python3
""" Can un lock all """


def canUnlockAll(boxes):
    """ Can un lock all """
    unlocked = boxes[0]
    for box_id, keys in enumerate(boxes):
        if not keys:
            if box_id in unlocked:
                unlocked.append(0)
            continue
        for key in keys:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    print(unlocked)
    if len(unlocked) == len(boxes):
        return True
    return False
