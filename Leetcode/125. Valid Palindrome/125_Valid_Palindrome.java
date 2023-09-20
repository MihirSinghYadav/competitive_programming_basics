class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;

        // Loop until the left and right pointers meet
        while (left < right) {
            Character start = s.charAt(left);
            Character end = s.charAt(right);

            // Skip non-alphanumeric characters from the left
            if (!Character.isLetterOrDigit(start)) {
                left++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!Character.isLetterOrDigit(end)) {
                right--;
                continue;
            }

            // Check if the lowercase forms of characters at start and end are equal
            if (Character.toLowerCase(start) != Character.toLowerCase(end))
                return false;

            // Move the pointers towards each other
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example 1: Test with a palindrome string
        String s1 = "A man, a plan, a canal, Panama";
        boolean result1 = solution.isPalindrome(s1);
        System.out.println("Is s1 a palindrome? " + result1); // Expected output: true

        // Example 2: Test with a non-palindrome string
        String s2 = "race a car";
        boolean result2 = solution.isPalindrome(s2);
        System.out.println("Is s2 a palindrome? " + result2); // Expected output: false
    }
}
