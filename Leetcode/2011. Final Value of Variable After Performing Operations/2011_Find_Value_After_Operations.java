class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int value = 0;
        for (int i = 0; i < operations.length; i++) {
            if (operations[i].charAt(1) == '+')
                value++;
            else
                value--;
        }
        return value;
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example 1: Test with operations
        String[] operations1 = { "--X", "X++", "X++" };
        int result1 = solution.finalValueAfterOperations(operations1);
        System.out.println("Final value after operations1: " + result1);

        // Example 2: Test with different operations
        String[] operations2 = { "++X", "X--", "X--" };
        int result2 = solution.finalValueAfterOperations(operations2);
        System.out.println("Final value after operations2: " + result2);
    }
}
