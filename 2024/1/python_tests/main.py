import numpy as np
from numba import njit

file = open("input.txt", "r")
lines = file.readlines()

@njit
def calculate_total_distance(left, right):
    left.sort()
    right.sort()

    total_distance = 0
    for l, r in zip(left, right):
        total_distance += abs(l - r)

    return total_distance

def main():
    left = []
    right = []
    delimiter = "   "

    for text in lines:
        pos = text.find(delimiter)
        left.append(int(text[:pos]))
        right.append(int(text[pos + len(delimiter):]))

    left = np.array(left)
    right = np.array(right)

    total_distance = calculate_total_distance(left, right)


if __name__ == "__main__":
    main()
