#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    You have n number of locked boxes
    in front of you. Each box is numbered sequentially.
    """
    boxOne = [0]
    for key in boxOne:
        for keyBox in boxes[key]:
            if keyBox not in boxOne:
                if keyBox < len(boxes):
                    boxOne.append(keyBox)
    if len(boxOne) == len(boxes):
        return True
    return False
