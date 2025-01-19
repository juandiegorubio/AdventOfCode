#include "days.hpp"

bool is_report_safe(string s) {
    stringstream ss(s);

    int prev_level; ss >> prev_level;
    bool is_incremental, is_incremental_set = false;
    
    for(int level = 0; ss >> level; ) {
        int difference = level - prev_level;
        // We check if the distance between level and prev_level is between 1 and 3
        if(abs(difference) > 3 || abs(difference) < 1) return false;
        // We check if is incremental or decremental
        if( is_incremental_set && is_incremental != (difference > 0) ) return false;
        else {
            is_incremental = (difference) > 0; 
            is_incremental_set = true; 
        }
        // If all conditions passed, then we keep checking
        prev_level = level;
    }
    return true;
}

void day2_part1() {
    string report_str;
    int result = 0;
    while(getline(cin, report_str)) {
        if(is_report_safe(report_str)) result++;
    }
    cout << result << endl;
}