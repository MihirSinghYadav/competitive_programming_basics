from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        rowZero = False

        # determine which rows/cols need to be zero
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0
                    if r > 0:
                        matrix[r][0] = 0
                    else:
                        rowZero = True

        # changing values except 1st row and col
        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[0][c] == 0 or matrix[r][0]==0:
                    matrix[r][c] = 0

        # changing 1st row and col
        if matrix[0][0] == 0:
            for r in range(rows):
                matrix[r][0] = 0

        if rowZero:
            for c in range(cols):
                matrix[0][c] = 0


def main():
    matrix = [[1, 2, 3], [4, 0, 6], [7, 8, 9]]
    solution = Solution()
    solution.setZeroes(matrix)
    for row in matrix:
        print(row)


if __name__ == "__main__":
    main()
