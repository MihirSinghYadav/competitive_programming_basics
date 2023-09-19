import java.util.ArrayList;
import java.util.List;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Create a list to store the characters of the current substring
        List<Character> substring = new ArrayList<>();

        // Initialize a variable to keep track of the largest substring length found
        int largestLength = 0;

        // Loop through the characters of the input string
        for (int right = 0; right < s.length(); right++) {
            // Check if the current character is already in the substring
            if (substring.contains(s.charAt(right))) {
                // If yes, find the index of the character
                int index = substring.indexOf(s.charAt(right));
                // Remove the character at that index
                substring.remove(index);
                // If the removed character was not the first character, remove all characters
                // before it
                if (index > 0)
                    substring.subList(0, index).clear();
            }

            // Add the current character to the substring
            substring.add(s.charAt(right));

            // Update the largestLength with the maximum of its current value and the size
            // of the substring
            largestLength = Math.max(largestLength, substring.size());
        }

        // Return the length of the longest substring without repeating characters
        return largestLength;
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example 1: Test with a string
        String s1 = "abcabcbb";
        int result1 = solution.lengthOfLongestSubstring(s1);
        System.out.println("Length of the longest substring in s1: " + result1);

        // Example 2: Test with another string
        String s2 = "bbbbb";
        int result2 = solution.lengthOfLongestSubstring(s2);
        System.out.println("Length of the longest substring in s2: " + result2);
    }
}
