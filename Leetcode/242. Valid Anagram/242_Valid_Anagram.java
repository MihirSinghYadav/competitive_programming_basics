class Solution {
    public boolean isAnagram(String s, String t) {
        // Check if the lengths of the two strings are different, return false
        if (s.length() != t.length())
            return false;

        // Create an array to store the frequency of each lowercase letter
        int[] store = new int[26];

        // Iterate through the characters in both strings
        for (int i = 0; i < s.length(); i++) {
            // Increment the count for the character in string 's' and decrement for 't'
            store[s.charAt(i) - 'a']++;
            store[t.charAt(i) - 'a']--;
        }

        // Check if all counts in the 'store' array are zero, indicating an anagram
        for (int n : store) {
            if (n != 0)
                return false;
        }

        // If all counts are zero, return true (anagram)
        return true;
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example: Test with anagram strings
        String s1 = "anagram";
        String t1 = "nagaram";
        boolean result1 = solution.isAnagram(s1, t1);
        System.out.println("Are s1 and t1 anagrams? " + result1); // Expected output: true

        // Example: Test with non-anagram strings
        String s2 = "rat";
        String t2 = "car";
        boolean result2 = solution.isAnagram(s2, t2);
        System.out.println("Are s2 and t2 anagrams? " + result2); // Expected output: false
    }
}
