class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        boolean isFirstRowZero = false;
        boolean isFirstColZero = false;

        // find 0 in 1st row and col
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        // find 0 in matrix from (1,1) to (rows,cols)
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // set elements in matrix 0
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // set 1st col and row 0
        if (isFirstColZero) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
        if (isFirstRowZero) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                { 0, 1, 2, 0 },
                { 3, 4, 5, 2 },
                { 1, 3, 1, 5 }
        };

        Solution solution = new Solution();
        solution.setZeroes(matrix);
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}