#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
/*
Linear Search: O(n)
Binary Search: O(log n)
Depth First Search: O(V + E)
Breadth First Search: O(V + E)
Bubble Sort: O(n^2)
Selection Sort: O(n^2)
Insertion Sort: O(n^2)
Merge Sort: O(n log n)
Quick Sort: O(n log n) (average case)
Heap Sort: O(n log n)
Comb Sort: O(n^2)
Counting Sort: O(n + k)
Radix Sort: O(nk)
Bucket Sort: O(n + k)
Tag Sort: O(n)
Ternary search: O(log3 n)
Meta Binary Search: O(log n)
Ubiqutious Binary Search: O(log n)
Exponential Search: O(log n)
Interpolation Search: O(log log n)
Jump Search: O(sqrt(n))
Fibonacci Search: O(log n)
Tim sort: O(n log n)
Tree sort: O(n log n)
Shell sort: O(n log n)
Pigeonhole sort: O(n + k)
Cycle sort: O(n^2)
Cocktail sort: O(n^2)
Gnome sort: O(n^2)
Strand sort: O(n^2)
Bitonic sort: O(n log^2 n)
Pancake sort: O(n^2)
Binary insertion sort: O(n^2)
Bogo sort: O(n * n!)
Slow sort: O(n log n)
Stooge sort: O(n^2.7)
Bead sort: O(n)
Bose-Nelson sort: O(n log n)
Brick sort: O(n^2)
Burstsort: O(n)
Circle sort: O(n)
Bucket sort: O(n)
*/

// Linear Search: O(n)
// The time complexity of Linear Search is O(n) because every element in the array is checked at most once.
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Binary Search: O(log n)
// Binary Search has a time complexity of O(log n) as it halves the search space at each step.
int binarySearch(int arr[], int l, int r, int key)
{
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Depth First Search (DFS): O(V + E)
// DFS has a time complexity of O(V+E) where V is the number of vertices and E is the number of edges.
// This is because every vertex and every edge will be explored in the worst case.
void DFS(int node, vector<int> graph[], vector<bool> &visited)
{
    visited[node] = true;
    for (auto &i : graph[node])
    {
        if (!visited[i])
            DFS(i, graph, visited);
    }
}

// Breadth First Search (BFS): O(V + E)
// BFS also has a time complexity of O(V+E) because in the worst-case scenario,
// we have to traverse through all vertices and all edges.
void BFS(int node, vector<int> graph[], vector<bool> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto &i : graph[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Bubble Sort: O(n^2)
// Bubble Sort has a time complexity of O(n^2) because there are two nested loops traversing through the array.
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort: O(n^2)
// Selection Sort also has a time complexity of O(n^2) due to the two nested loops in the algorithm.
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        swap(&arr[min_index], &arr[i]);
    }
}

// Insertion Sort: O(n^2)
// Insertion sort has a time complexity of O(n^2) because in the worst case, for each element in the array,
// we may need to compare it to each of the sorted elements.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort: O(n log n)
// Merge Sort has a time complexity of O(n log n) because the array is divided in half in each recursive call.
void merge(int arr[], int l, int m, int r)
{
    // merge operation here
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Quick Sort: O(n log n) in the average case
// The time complexity of QuickSort is O(n log n) because at each step it partitions the array around a pivot,
// and then recursively sorts the elements on either side of the pivot.
int partition(int arr[], int low, int high)
{
    // partition operation here
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap Sort: O(n log n)
// Heap sort involves building a heap from the array and then removing the maximum element and
// placing it at the end of the sorted portion of the array. These operations are performed n times, hence O(n log n).
void heapify(int arr[], int n, int i)
{
    // heapify operation here
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Comb Sort: O(n^2)
// Similar to bubble sort, but it uses a larger gap. With a worst-case time complexity of O(n^2), but it can perform better than this on average.
void combSort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// Counting Sort: O(n + k)
// Counting sort is efficient if the range of input values, k, is not significantly greater than the number of values to be sorted, n.
void countSort(char arr[])
{
    char output[strlen(arr)];

    int count[CHAR_RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= CHAR_RANGE; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

// Radix Sort: O(nk)
// Radix sort has a time complexity of O(nk), where n is the number of elements and k is the number of digits in the maximum number.
void countingSortForRadix(int array[], int size, int place)
{
    // Implementation of counting sort for radix
}

void radixsort(int array[], int size)
{
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSortForRadix(array, size, place);
}

// Bucket Sort: O(n + k)
// Bucket sort assumes that the input is drawn from a uniform distribution and has an average time complexity of O(n + k)
// where n is the number of elements and k is the number of buckets.
void bucketSort(float arr[], int n)
{
    vector<float> b[n];

    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

// Tag Sort: O(n)
// Tag sort requires that each item have a non-negative integer key in a bounded range, and it simply counts occurrences of each key and
// then outputs the keys in sorted order. This gives it a time complexity of O(n), but it has significant memory requirements and isn't suitable for all data.
void tagSort(int arr[], int n)
{
    int max_val = *max_element(arr, arr + n);
    int min_val = *min_element(arr, arr + n);
    int range_val = max_val - min_val + 1;

    vector<int> count(range_val), output(n);
    for (int i = 0; i < n; i++)
        count[arr[i] - min_val]++;

    for (int i = 1; i < range_val; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Ternary Search: O(log3 n)
// Ternary search is a divide-and-conquer search algorithm. It works by dividing the search space into 3 equal parts
// and determining which part the item we are looking for is in, which results in O(log3 n) time complexity.
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key)
            return mid1;
        if (ar[mid2] == key)
            return mid2;
        if (key < ar[mid1])
            return ternarySearch(l, mid1 - 1, key, ar);
        else if (key > ar[mid2])
            return ternarySearch(mid2 + 1, r, key, ar);
        else
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
    }
    return -1;
}

// Meta Binary Search: O(log n)
// Meta binary search refers to using binary search to find the minimum value that satisfies a certain condition,
// and it also has a time complexity of O(log n) because it halves the search space in every step.
bool check(int x)
{
    // check if x satisfies the condition
}

int metaBinarySearch(int l, int r)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    return r;
}

// Ubiquitous Binary Search: O(log n)
// Ubiquitous Binary Search refers to using binary search to find the first or last occurrence of a number in a sorted array,
// and it has a time complexity of O(log n).
int ubiquitousBinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if ((mid == r || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return ubiquitousBinarySearch(arr, l, mid - 1, x);
        else
            return ubiquitousBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// Exponential Search: O(log n)
// Exponential search involves two steps: first finding a range in which the target value may be, and then performing a binary search within that range.
int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return binarySearch(arr, i / 2, min(i, n), x);
}

// Interpolation Search: O(log log n)
// Interpolation search works better than Binary Search for a sorted and uniformly distributed array, and on average it performs in O(log log n).
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);

    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x)
                return lo;
            return -1;
        }

        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            lo = pos + 1;

        else
            hi = pos - 1;
    }
    return -1;
}

// Jump Search: O(sqrt(n))
// Jump Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements by jumping ahead by fixed steps,
// say sqrt(n), instead of searching all elements.
int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

// Fibonacci Search: O(log n)
// Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.
int fibonacciSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else
            return i;
    }

    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

// Tim Sort: O(n log n)
// Tim sort is a hybrid stable sorting algorithm, derived from merge sort and insertion sort,
// designed to perform well on many kinds of real-world data, and its worst case time complexity is O(n log n).
void timSort(int arr[], int n)
{
    // full implementation would require auxiliary functions
}

// Tree Sort: O(n log n)
// Tree sort is a sorting algorithm that is based on Binary Search Tree data structure.
// It first creates a binary search tree from the elements of the input list or array and then performs an in-order traversal on the created binary search tree.
struct Node
{
    int key;
    struct Node *left, *right;
};

void treeSort(int arr[], int n)
{
    // full implementation would require auxiliary functions
}

// Tree Sort: O(n log n)
// Tree sort is a sorting algorithm that is based on Binary Search Tree data structure.
// It first creates a binary search tree from the elements of the input list or array and then performs an in-order traversal on the created binary search tree.
struct Node
{
    int key;
    struct Node *left, *right;
};

void treeSort(int arr[], int n)
{
    // implementation requires creating and balancing a binary search tree
}

// Shell Sort: O(n log n)
// Shell Sort is a generalized version of insertion sort. It first sorts elements far apart from each other and successively reduces the interval between the elements to be sorted.
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

// Pigeonhole Sort: O(n + k)
// Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number of elements and
// the number of possible key values are approximately the same.
void pigeonholeSort(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;
    vector<int> holes[range];
    for (int i = 0; i < n; i++)
        holes[arr[i] - min].push_back(arr[i]);
    int index = 0;
    for (int i = 0; i < range; i++)
        for (int j = 0; j < holes[i].size(); j++)
            arr[index++] = holes[i][j];
}

// Cycle Sort: O(n^2)
// Cycle sort is an in-place, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the
// total number of writes to the original array.
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on
    // the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}

// Cocktail Sort: O(n^2)
// Cocktail Sort is a variation of Bubble sort. The Bubble sort algorithm always traverses elements from left and moves
// the largest element to its correct position in first iteration and second largest in second iteration and so on.
// Cocktail Sort traverses through a given array in both directions alternatively.
void cocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

// Gnome Sort: O(n^2)
// Gnome Sort also called Stupid sort is based on the concept of a Garden Gnome sorting his flower pots.
// A Gnome Garden is a Dutch garden tool that comes up to the waist and is best worked by standing still and working around it.
void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n)
    {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else
        {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

// Other sorts such as Strand Sort, Bitonic Sort, Pancake Sort, Binary Insertion Sort, and Bogo Sort also exist.
// However, their implementation is more complex and may not be commonly used due to their high time complexity or specific use cases.
// For example, Bogo Sort has a time complexity of O((n+1)!) which makes it impractical for large data sets.
// It is a purposely inefficient algorithm, used primarily as an in-joke or to illustrate the concept of a particularly bad algorithm.

/*
Slow Sort: O(n^2) in worst-case but performs better on nearly sorted lists.
    It is not used in practice due to its inefficiency.
    Stooge Sort: O(n^2.7095...) time complexity.
    It recursively splits the array into thirds, sorts the first two-thirds,
    the last two-thirds, and then the first two-thirds again.
Bead Sort: O(n). Bead sort, also called gravity sort, is a natural sorting algorithm.
    Both digital and analog hardware implementations of bead sort can achieve a sorting time of O(n);
    however, the implementation of this algorithm tends to be significantly slower in software
    and can only be used to sort lists of positive integers.
Bose-Nelson Sorting: O(n log n). This is an algorithm for sorting a sequence of n elements,
    which was developed in 1962. It works by recursively breaking the sequence to be
    sorted into two halves, sorting each half, and then merging them back together.
Brick Sort: O(n^2). Also known as odd-even sort, it is a relatively simple sorting algorithm,
    developed originally for use on parallel processors with local interconnections.
    It's similar to bubble sort, but with alternating phases.
Burst-sort: O(n). Burst-sort is a sorting algorithm for strings that distributes keys into buckets,
    just like radix sort, but the buckets are growable arrays, or "bursts" (hence the name).
        The buckets are sorted individually, then concatenated.
    It's a cache-efficient sort and can be faster than quicksort for large data.
Circle Sort: O(n log n). This algorithm recursively sorts pairs of items
    that are initially widely separated in the list, then less widely separated, and so on.
Bucket Sort: O(n+k). Bucket sort is a comparison sort algorithm that
    operates on elements by dividing them into different buckets
    and then sorting these buckets individually.
    Each bucket is sorted individually using a separate sorting algorithm
    or by applying the bucket sort algorithm recursively.
*/