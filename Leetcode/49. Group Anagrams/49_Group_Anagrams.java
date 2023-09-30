import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Create a HashMap to store sorted strings as keys and corresponding anagrams
        // as values.
        HashMap<String, List<String>> map = new HashMap<>();
        // Initialize the result list.
        List<List<String>> result = new ArrayList<>();

        // Iterate through each input string in the array.
        for (String str : strs) {
            // Convert the string to a character array and sort it to obtain a unique key.
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String sorted = new String(arr);

            // If the sorted key is not in the map, create a new list for it.
            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<String>());
            }
            // Add the original string to the corresponding anagram list in the map.
            map.get(sorted).add(str);
        }

        // Iterate through the keys (sorted strings) in the map and add the anagram
        // lists to the result.
        for (String key : map.keySet()) {
            result.add(map.get(key));
        }

        // Return the final list of grouped anagrams.
        return result;
    }

    public static void main(String[] args) {
        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

        Solution solution = new Solution();
        List<List<String>> result = solution.groupAnagrams(strs);

        // Print the grouped anagrams
        for (List<String> group : result) {
            System.out.println(group);
        }
    }
}