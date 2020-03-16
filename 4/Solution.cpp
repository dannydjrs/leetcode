#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

struct VectorRange {
    vector<int>& arr;
    int min;
    int max;
    VectorRange(std::vector<int>& arr)
    : arr(arr)
    , min(0) // >=
    , max(arr.size()) // <
    {}
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        VectorRange r1(nums1);
        VectorRange r2(nums2);

        return findMediunBetweenIndexes(r1, r2);
    }

    double findMediunBetweenIndexes(VectorRange r1, VectorRange r2) {
        cout << "R1 min: " << r1.min << endl;
        cout << "R1 max: " << r1.max << endl;
        cout << "R2 min: " << r2.min << endl;
        cout << "R2 max: " << r2.max << endl;

        if (r1.max - r1.min <= 0) {
            cout << "ends with r1" << endl;
            return getMedian(r2);
        }

        if (r2.max - r2.min <= 0) {
            cout << "ends with r2" << endl;
            return getMedian(r1);
        }

        if (r1.max - r1.min == 1 && r2.max - r2.min == 1) {
            cout << "ends with both" << endl;
            return (r1.arr[r1.min] + r2.arr[r2.min]) / 2.0;
        }

        double m1 = getMedian(r1);
        double m2 = getMedian(r2);

        cout << m1 << endl;
        cout << m2 << endl;

        if (m1 < m2) {
            r1.min = (int)((r1.max - r1.min) / 2) + r1.min;
            r2.max = (int)((r2.max - r2.min) / 2) + r2.min;
        } else if (m1 > m2) {
            r1.max = (int)((r1.max - r1.min) / 2) + r1.min;
            r2.min = (int)((r2.max - r2.min) / 2) + r2.min;
        } else {
            return m1;
        }

        return findMediunBetweenIndexes(r1, r2);
    }

    double getMedian(VectorRange range) {
        int size = range.max - range.min;

        if (size % 2 == 1) { // If odd array length
            return range.arr[(int)(size / 2) + range.min]; // Get middle element
        } else { // If even array length
            double l = range.arr[(int)((size-1) / 2) + range.min];
            double r = range.arr[(int)(size / 2) + range.min];
            return (l + r) / 2;
        }
    }
};


int main() {
    vector<int> first;
    vector<int> second;

    first.push_back(1);
    first.push_back(2);

    second.push_back(-1);
    second.push_back(3);

    Solution s;
    cout << s.findMedianSortedArrays(first, second) << endl;

    return 1;
}
