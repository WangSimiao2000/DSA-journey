#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selectionSort(vector<int> &nums){
    int n = nums.size();
    // unsorted array: nums[i, n-1]
    for (int i = 0; i < n - 1; i++) {
        // find the minimum element in unsorted array
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k]) {
                k = j;            
            }
        }
        // swap the minimum element with the first element in unsorted array
        swap(nums[i], nums[k]);
    }
}

// Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void bubbleSort(vector<int> &nums){
    int n = nums.size();
    // unsorted array: nums[0, i]
    for(int i = n; i > 0; i--){
        // put the maximum element in unsorted array to its right position
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                // swap the adjacent elements
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// Bubble Sort (Flag Optimization)
void bubbleSortFlag(vector<int> &nums){
    int n = nums.size();
    // unsorted array: nums[0, i]
    for(int i = n; i > 0; i--){
        bool flag = false;
        // put the maximum element in unsorted array to its right position
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                // swap the adjacent elements
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

// Insertion Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void insertionSort(vector<int> &nums){
    int n = nums.size();
    // unsorted array: nums[1, n]
    // sorted array: nums[0, i-1]
    for (int i = 1; i < n; i++) {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间 [0, i-1] 中的正确位置
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j]; // 将 nums[j] 向右移动一位
            j--;
        }
        nums[j + 1] = base; // 将 base 赋值到正确位置
    }
}

// Quick Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
int partition(vector<int> &nums, int left, int right){
    // choose nums[left] as pivot element
    int i = left, j = right;
    while(i < j){
        while(i < j && nums[j] >= nums[left]){
            // from right to left, find the first element less than pivot
            j--;
        }
        while(i < j && nums[i] <= nums[left]){
            // from left to right, find the first element greater than pivot
            i++;
        }
        // swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }
    // 将基准数交换至两子数组的分界线
    // swap pivot element with two subarrays' boundary
    swap(nums[i], nums[left]);
    return i; // return the index of pivot element
}
void quickSort(vector<int> &nums, int left, int right){
    // if the length of subarray is 1, return
    if(left >= right){
        return;
    }
    // partition the array into two subarrays
    int pivot = partition(nums, left, right);
    // recursively sort two subarrays
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

// Merge Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void merge(vector<int> &nums, int left, int mid, int right){
    // left subarray: nums[left, mid]
    // right subarray: nums[mid+1, right]
    // create a temporary array to store the merged array
    vector<int> temp(right - left + 1);
    // initialize the index of left subarray and right subarray
    int i = left, j = mid + 1, k = 0;
    // when both subarrays have elements, do comparison and put the smaller one into temp array
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++]; // 这里是先赋值，再自增, 如果是++i, 则是先自增，再赋值
        }else{
            temp[k++] = nums[j++];
        }
    }
    // put the remaining elements into temp array
    while (i <= mid) {
        temp[k++] = nums[i++];    
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    // copy the elements in temp array to original array (nums)
    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}
void mergeSort(vector<int> &nums, int left, int right){
    // stop condition
    if(left >= right){
        return;
    }
    // 划分阶段
    // partition stage
    int mid = left + (right - left) / 2; // compute the middle index
    mergeSort(nums, left, mid); // sort left subarray
    mergeSort(nums, mid + 1, right); // sort right subarray
    // 合并阶段
    // merge stage
    merge(nums, left, mid, right);
}

// Heap Sort
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
void siftDown(vector<int> &nums, int n, int i){ 
    // n: the length of heap, i: the index of root
    while (true) {
        // judge i,l,r which is the largest, mark the largest index as maxIdx
        int l = 2 * i + 1; // left child
        int r = 2 * i + 2; // right child
        int maxIdx = i;
        if (l < n && nums[l] > nums[maxIdx]) {
            maxIdx = l;
        }
        if (r < n && nums[r] > nums[maxIdx]) {
            maxIdx = r;
        }
        // if the root is the largest or l, r has exceeded the boundary, break
        if (maxIdx == i) {
            break;
        }
        // swap the root with the largest element
        swap(nums[i], nums[maxIdx]);
        // update the index of root
        i = maxIdx;
    }
}
void heapSort(vector<int> &nums){
    // build heap:
    for (int i = nums.size() / 2 - 1; i >= 0; i--) {
        siftDown(nums, nums.size(), i);
    }
    // get the maximum element from the heap
    for (int i = nums.size() - 1; i > 0; i--) {
        // swap the root element with the rightmost element (swap the first element with the last element)
        swap(nums[0], nums[i]);
        // rebuild the heap
        siftDown(nums, i, 0);
    }
}

// Bucket Sort
// Time Complexity: O(n + k)
// Space Complexity: O(n + k)
void bucketSort(vector<float> &nums){
    // initialize k = n/2 buckets, each bucket may contain 2 elements
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);
    // 1. put elements into buckets
    for (float num : nums) {
        int index = num * k;
        buckets[index].push_back(num);    
    }
    // 2. sort each bucket
    for (int i = 0; i < k; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    // 3. merge all buckets
    int index = 0;
    for (vector<float>  &bucket : buckets) {
        for (float num : bucket) {
            nums[index++] = num;
        }    
    }
}

// Counting Sort
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
/* Naive version: can not sort objects */ 
void countingSortNaive(vector<int> &nums){
    // 1. find the maximum element m in nums
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }
    // 2. count the frequency of each element
    // counter[num] represents the frequency of num
    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }
    // 3. ergodic counter, put the elements back to nums
    int i = 0;
    for (int num = 0; num <= m; num++) {
        for (int j = 0; j < counter[num]; j++, i++) {
            nums[i] = num;
        }
    }
}
/* Complete version: can sort objects, and is stable sorting */ 
void countingSort(vector<int> &nums) {
    // 1. find the maximum element m in nums
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }
    // 2. count the frequency of each element
    // counter[num] represents the frequency of num
    vector<int> counter(m + 1, 0);
    for (int num : nums) {
        counter[num]++;
    }
    // 3. calculate the prefix sum of counter
    for (int i = 1; i <= m; i++) {
        counter[i] += counter[i - 1];
    }
    // 4. reverse traversal nums, put the elements into the result array "res"
    // initialize the result array "res"
    int n = nums.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        int num = nums[i];
        res[counter[num] - 1] = num; // put num into the correct index position
        counter[num]--; // update the frequency of num
    }
    nums = res; // copy the result array "res" to original array "nums"
}

// Radix Sort
// Time Complexity: O(n * k)
// Space Complexity: O(n + d)
/* get the k-th digit of num, exp = 10^(k - 1) */
int digit(int num, int exp){
    // passed in exp to avoid repeated calculation
    return (num / exp) % 10;
}
/* counting sort for each digit (depends on the k-th digit of each element) */
void countingSortDigit(vector<int> &nums, int exp){
    // 0~9, 10 digits
    vector<int> counter(10, 0);
    int n = nums.size();
    // count the frequency of each digit
    for (int i = 0; i < n; i++) {
        counter[digit(nums[i], exp)]++;
    }
    // calculate the prefix sum of counter
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }
    // reverse traversal nums, put the elements into the result array "res"
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int d = digit(nums[i], exp);
        res[counter[d] - 1] = nums[i];
        counter[d]--;
    }
    // res -> nums
    for (int i = 0; i < n; i++) {
        nums[i] = res[i];
    }
}
/* radix sort */
void radixSort(vector<int> &nums){
    // find the maximum element m in nums
    int m = 0;
    for (int num : nums) {
        m = max(m, num);
    }
    // traverse each digit of the maximum element m
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSortDigit(nums, exp);
    }
}

int main() {    
    // test for integer type
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    
    // test for float type
    //vector<float> nums = {0.3, 0.1, 0.4, 0.1, 0.5, 0.9, 0.2, 0.6, 0.5, 0.3};

    //selectionSort(nums);
    //bubbleSort(nums);
    //bubbleSortFlag(nums);
    //insertionSort(nums);
    //quickSort(nums, 0, nums.size() - 1);
    //mergeSort(nums, 0, nums.size() - 1);
    //heapSort(nums);
    //bucketSort(nums);
    //countingSortNaive(nums);
    //countingSort(nums);
    radixSort(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}