import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        // Create a HashSet to store unique integers from the 'nums' array
        Set<Integer> set = new HashSet<>();

        // Iterate through each element 'nums[i]' in the 'nums' array
        for (int i = 0; i < nums.length; i++) {
            // Check if 'set' already contains the current element 'nums[i]'
            if (set.contains(nums[i])) {
                // If a duplicate is found, return true
                return true;
            }
            // Add the current element 'nums[i]' to the 'set' to track unique values
            set.add(nums[i]);
        }

        // If no duplicates are found after iterating through the entire array, return
        // false
        return false;

    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = { 1, 2, 3, 4, 5 };
        System.out.println("Array 1 contains duplicate: " + solution.containsDuplicate(nums1));
        // Should print "Array 1 contains duplicate: false"

        int[] nums2 = { 1, 2, 3, 1, 4, 5 };
        System.out.println("Array 2 contains duplicate: " + solution.containsDuplicate(nums2));
        // Should print "Array 2 contains duplicate: true"

        int[] nums3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        System.out.println("Array 3 contains duplicate: " + solution.containsDuplicate(nums3));
        // Should print "Array 3 contains duplicate: false"
    }
}
