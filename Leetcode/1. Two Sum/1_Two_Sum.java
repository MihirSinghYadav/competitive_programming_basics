import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store the elements from the 'nums' array as keys
        // and their corresponding indices as values.
        HashMap<Integer, Integer> maps = new HashMap<>();

        // Iterate through each element in the 'nums' array.
        for (int i = 0; i < nums.length; i++) {
            // Calculate the difference between the 'target' value and the current element.
            int diff = target - nums[i];

            // Check if the 'diff' value is already present in the 'maps' HashMap.
            if (maps.containsKey(diff)) {
                // If 'diff' is found, return an array containing the indices of the two
                // elements.
                // 'maps.get(diff)' retrieves the index of the element that complements 'diff',
                // and 'i' is the index of the current element.
                return new int[] { maps.get(diff), i };
            }

            // If 'diff' is not found, add the current element and its index to the 'maps'
            // HashMap.
            maps.put(nums[i], i);
        }

        // If no pair of elements that add up to the 'target' is found, return an empty
        // integer array.
        return new int[] {};

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = { 2, 7, 11, 15 };
        int target = 9;
        int[] result = solution.twoSum(nums, target);
        System.out.println("[" + result[0] + "," + result[1] + "]");
    }
}
