#include <bits/stdc++.h>
#include "../include/DataStructures.h"
using namespace std;
using namespace std::chrono;




void main_with_linked_list() {
    LinkedList list1, list2;
    int n1, n2;
    auto start = high_resolution_clock::now();
    while (cin >> n1 >> n2) {
        list1.insert_sort(n1);
        list2.insert_sort(n2);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}

void main_with_vector() {
    vector<int> l1, l2;
    int n1, n2;
    auto start = high_resolution_clock::now();
    while (cin >> n1 >> n2) {
        l1.push_back(n1);
        l2.push_back(n2);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}

int main() {
    main_with_linked_list();
    cout << "THIS WORKS" << endl;
}
