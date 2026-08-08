#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> arr;
    int size;

    MaxHeap(int cap) {
        arr.resize(cap);
        size = 0;
    }

    // Insert into heap
    void insert(int val) {
        if (size == arr.size()) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = val;  // insert at end
        int i = size;
        size++;

        // Fix heap upwards
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Heapify (fix heap downward)
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Build heap in O(n)
    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Heap sort (static function)
    static void heapSort(vector<int> &v) {
        int n = v.size();

        // Step 1: Build max-heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyStatic(v, n, i);

        // Step 2: Swap max with last & reduce size
        for (int i = n - 1; i >= 0; i--) {
            swap(v[0], v[i]);
            heapifyStatic(v, i, 0); // reduced heap
        }
    }

private:
    // Static heapify for heap sort
    static void heapifyStatic(vector<int> &v, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && v[left] > v[largest])
            largest = left;

        if (right < n && v[right] > v[largest])
            largest = right;

        if (largest != i) {
            swap(v[i], v[largest]);
            heapifyStatic(v, n, largest);
        }
    }
};

int main() {
    int n;
    cin >> n;

    MaxHeap h(n);

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        h.insert(input[i]);
    }

    cout << "Max Heap array:\n";
    for (int i = 0; i < h.size; i++) cout << h.arr[i] << " ";
    cout << "\n";

    // Heap sort usage
    MaxHeap::heapSort(input);

    cout << "After Heap Sort:\n";
    for (int x : input) cout << x << " ";
    cout << "\n";

    return 0;
}
