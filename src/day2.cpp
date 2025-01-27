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



bool is_report_safe_part2(vector<int> report) {
    bool is_incremental = false;
    bool bad_level_found = false;
    for(long unsigned int i=0; i < report.size()-1; ++i) {
        int diff = report[i+1] - report[i];
        bool change_sign = is_incremental_set && (is_incremental != (diff > 0));
        bool level_diff_outbound = abs(diff) < 1 || abs(diff) > 3;

        if( change_sign || level_diff_outbound ) {
            vector<int> test_report1(report.begin()+i+1, report.end());
            vector<int> test_report2(report.begin()+i, report.end());
            test_report2.erase(report.begin() + 1);
            
            if( !is_report_safe_part2(test_report1) && !is_report_safe_part2(test_report2) ) return false;
            else return true;
        }
        else {
            is_incremental = (diff > 0);
            is_incremental_set = true;
        }
    }
    return true;
}


void day2_part2() {
    string report_str;
    int result = 0;
    while(getline(cin, report_str)) {
        
        // Read the report
        stringstream ss(report_str);
        vector<int> report;
        for(int level=0; ss >> level; ) report.push_back(level);
        
        // Get if report is unsafe
        bool safe_report = is_report_safe_part2(report);
        if(safe_report) result++;
    }
    cout << result << endl;
}
