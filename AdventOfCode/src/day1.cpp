#include "days.hpp"


void day1_part1_with_linked_lists() {
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

void day1_part1() {
    // Read two lists
    vector<int> l1, l2;
    int n1, n2;
    while( cin >> n1 >> n2 ) {
        l1.push_back(n1);
        l2.push_back(n2);
    }
    // Sort lists
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    // Get sum of distances
    int result = 0;
    for(long unsigned int i=0; i < l1.size(); ++i) result += abs(l2[i] - l1[i]);
    cout << result << endl;
}

void day1_part2() {
    vector<int> values_found; 
    unordered_map<int, int> values_freq;
    int n1, n2;
    // Read values and how many times are repeated
    while( cin >> n1 >> n2 ) {
        values_found.push_back(n1);
        if(values_freq.find(n1) == values_freq.end()) values_freq[n1] = 0;
        if(values_freq.find(n2) == values_freq.end()) values_freq[n2] = 0;
        values_freq[n2]++;
    }
    // Get sum of values * frequency
    int result = 0;
    for(long unsigned int i=0; i < values_found.size(); ++i)
        result += abs( values_found[i] * values_freq[values_found[i]] );
    cout << result << endl;
}
