#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target) {
  int i = 0, j = nums.size() - 1;
  while (i <= j) {
    int mid = i + (j - i) / 2;
    if (nums[mid] < target) {
      i = mid + 1;
    } else if (nums[mid] > target) {
      j = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << binarySearch(nums, 5) << endl; // 4
  return 0;
}