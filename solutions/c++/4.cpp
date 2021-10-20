//69% speed
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    const vector<int> &A = nums1.size() < nums2.size() ? nums1 : nums2;
    const vector<int> &B = nums1.size() < nums2.size() ? nums2 : nums1;
    unsigned int m = A.size(), n = B.size(), imin = 0, imax = m,
                 i = (imax + imin) / 2, j = (m + n + 1) / 2 - i;
    if (A.size() == 0) {
      if (B.size() % 2 == 1)
        return B[n / 2];
      else
        return (B[(n - 1) / 2] + B[(n - 1) / 2 + 1]) / 2.0;
    }
    while (!((j == 0 || i == m || B[j - 1] <= A[i]) &&
             (i == 0 || j == n || A[i - 1] <= B[j]))) {
      if (B[j - 1] > A[i]) {
        imin = i + 1;
        i = (imin + imax) / 2;
      } else {
        imax = i - 1;
        i = (imin + imax) / 2;
      }
      j = (m + n + 1) / 2 - i;
    }
    if ((m + n) % 2 == 1) {
      if (i == 0)
        return B[j - 1];
      if (j == 0)
        return A[i - 1];
      return max(A[i - 1], B[j - 1]);
    } else {
      int a, b, c, d;
      if (i == 0) {
        a = numeric_limits<int>::min();
        c = A[i];
      } else if (i == m) {
        a = A[i - 1];
        c = numeric_limits<int>::max();
      } else {
        a = A[i - 1];
        c = A[i];
      }
      if (j == 0) {
        b = numeric_limits<int>::min();
        d = B[j];
      } else if (j == n) {
        b = B[j - 1];
        d = numeric_limits<int>::max();
      } else {
        b = B[j - 1];
        d = B[j];
      }

      return (max(a, b) + min(c, d)) / 2.0;
    }
    // return 2.0;
  }
};
