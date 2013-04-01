//inspired by Find the median of two sorted list
class Solution {
public:
    double FindKthInternal(int a[], int b[], int na, int nb, int left, int right, int k)
    {
		if(left > right)
			return FindKthInternal(b, a, nb, na, max(0, k - 1 - na), min(nb, k - 1), k);
		int i = (left + right) / 2;
		int j = k - 1 - i - 1;
		if(j >= 0 && j < nb && a[i] < b[j])
			return FindKthInternal(a, b, na, nb, i + 1, right, k);
		else if(j + 1 >= 0 && j + 1 < nb && a[i] > b[j+1])
			return FindKthInternal(a, b, na, nb, left, i - 1, k);
		else
			return a[i];
    }
    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return FindKthInternal(A, B, m, n, max(0, k - 1 - n), min(m - 1, k - 1), k);
    }
};

