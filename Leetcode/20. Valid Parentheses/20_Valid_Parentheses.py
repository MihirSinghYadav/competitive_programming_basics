class Solution:
    def isValid(self, s: str) -> bool:
        # Define a mapping of closing brackets to their corresponding opening brackets
        mapping = {")": "(", "]": "[", "}": "{"}
        # Initialize an empty stack to store opening brackets
        stack = []

        # Iterate through each character in the input string
        for c in s:
            if c not in mapping:
                # If the current character is not a closing bracket, push it onto the stack
                stack.append(c)
                continue
            if not stack or stack[-1] != mapping[c]:
                # If the stack is empty or the top element doesn't match the expected opening bracket, return False
                return False
            # Pop the top element from the stack
            stack.pop()

        # After processing all characters, if the stack is empty, the string is valid; otherwise, it's not valid
        return not stack


def main():
    # Create an instance of the Solution class
    solution = Solution()

    # Example 1: Test with a valid string
    s1 = "()[]{}"
    result1 = solution.isValid(s1)
    print("Is s1 valid? " + str(result1))  # Expected output: true

    # Example 2: Test with an invalid string
    s2 = "(]"
    result2 = solution.isValid(s2)
    print("Is s2 valid? " + str(result2))  # Expected output: false


if __name__ == "__main__":
    main()
