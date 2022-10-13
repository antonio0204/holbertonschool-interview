#!/usr/bin/python3
'''
rotates 2D matrix
'''


def rotate_2d_matrix(matrix):
    matrix_copy = list(zip(*matrix[::-1]))
    i = len(matrix)
    j = len(matrix[0])
    for vector in range(i):
        for element in range(j):
            matrix[vector][element] = matrix_copy[vector][element]
