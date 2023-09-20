import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        // Initialize a stack to store opening brackets
        Stack<Character> brackets = new Stack<>();

        // Create a map to look up matching opening brackets for closing brackets
        Map<Character, Character> bracketLookup = new HashMap<>(3);
        bracketLookup.put(')', '(');
        bracketLookup.put(']', '[');
        bracketLookup.put('}', '{');

        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (bracketLookup.containsKey(c)) {
                // If the current character is a closing bracket
                if (!brackets.isEmpty() && bracketLookup.get(c).equals(brackets.peek())) {
                    // Pop the top element from the stack if it matches the expected opening bracket
                    brackets.pop();
                } else {
                    // If the stack is empty or the top element doesn't match, return false
                    return false;
                }
            } else {
                // If the current character is an opening bracket, push it onto the stack
                brackets.push(c);
            }
        }

        // After processing all characters, if the stack is empty, the string is valid;
        // otherwise, it's not valid
        return brackets.isEmpty();
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example 1: Test with a valid string
        String s1 = "()[]{}";
        boolean result1 = solution.isValid(s1);
        System.out.println("Is s1 valid? " + result1); // Expected output: true

        // Example 2: Test with an invalid string
        String s2 = "(]";
        boolean result2 = solution.isValid(s2);
        System.out.println("Is s2 valid? " + result2); // Expected output: false
    }
}
