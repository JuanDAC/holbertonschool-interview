#!/usr/bin/python3
""" Can un lock all """


def canUnlockAll(boxes):
    """ Can un lock all """
    if type(boxes) is not list or len(boxes) == 0:
        return False

    unlocked = boxes[0]
    for box_id, keys in enumerate(boxes):
        if not keys:
            if box_id in unlocked:
                unlocked.append(0)
            continue
        for key in keys:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False


if __name__ == "__main__":
    boxes = [[4, 6], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
    print(canUnlockAll(boxes))
