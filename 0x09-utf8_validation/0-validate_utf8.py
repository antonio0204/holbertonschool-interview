#!/usr/bin/python3
"""
Validate UTF8
"""


def validUTF8(data):
    """Check if a set of integers are valid utf-8 format"""
    num_bytes = 0
    for char_d in data:
        byte = char_d & 0xff
        if num_bytes:
            if (byte >> 6 == 1 or byte >> 6 == 3):
                return False
            num_bytes -= 1
            continue

        while 7 - num_bytes and byte & (1 << (7 - num_bytes)):
            num_bytes += 1
        if num_bytes == 1 or num_bytes > 4:
            return False
        num_bytes = max(num_bytes - 1, 0)

    if num_bytes:
        return False
    return True
