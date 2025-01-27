#include "days.hpp"
#include <iostream>
using namespace std;



void print_vector(vector<int> report) {
    for(int level : report) cout << level << ' ';
    cout << endl;
}


bool is_report_safe(vector<int> report) {
    
    int diff, level, prev_level = report[0];
    bool is_order_increasing, order_set = false;

    for(long unsigned int i=1; i < report.size(); ++i) {
        level = report[i];
        diff = level - prev_level;
        
        if( abs(diff) < 1 || abs(diff) > 3 || (order_set && (is_order_increasing != (diff > 0))) ) {
            return false;
        }
        if( !order_set ) {
            is_order_increasing = (diff > 0);
            order_set = true;
        }
        
        prev_level = level;
    }
    return true;
}


bool is_report_safe_with_dampener(vector<int> report) {
    
    int diff, level, prev_level = report[0];
    bool is_order_increasing, order_set = false;

    for(long unsigned int i=1; i < report.size(); ++i) {
        level = report[i];
        diff = level - prev_level;

        if( abs(diff) < 1 || abs(diff) > 3 || ( order_set && is_order_increasing != (diff > 0) ) ) {
            vector<int> report_without_level(report.begin(), report.end());
            vector<int> report_without_prev_level(report.begin(), report.end());
            report_without_level.erase( report_without_level.begin() + i );
            report_without_prev_level.erase( report_without_prev_level.begin() + i-1 );
            if ( is_report_safe(report_without_prev_level) || is_report_safe(report_without_level) ) {
                return true;
            }
            else {
                cout << "Report: "; print_vector(report);
                cout << "\t Sub-report: "; print_vector(report_without_prev_level);
                cout << "\t Sub-report: "; print_vector(report_without_level);
                // if( !is_report_safe(report_without_level) && !is_report_safe(report_without_prev_level)) cout << "\t Both sub reports didn't work" << endl;
                // else if( is_report_safe(report_without_level) ) { cout << "\t Report that failed: "; print_vector(report_without_prev_level); }
                // else { cout << "\t Report that failed: "; print_vector(report_without_level); }
                return false;
            }
        }
        if( !order_set ) {
            is_order_increasing = diff > 0;
            order_set = true;
        }

        prev_level = level;
    }

    return true;
}



void day2_part1() {
    string input;
    vector<int> report;
    int result = 0;

    while(getline(cin, input)) {
        stringstream report_str(input);
        for(int level=0; report_str >> level; ) report.push_back(level);
        if( is_report_safe(report) )  result++;
        report.clear();
    }

    cout << "Reports Safe: " << result << endl;
}

void day2_part2() {
    string input;
    vector<int> report;
    int n_reports = 0;
    int result = 0;

    while(getline(cin, input)) {
        stringstream report_str(input);
        for(int level=0; report_str >> level; ) report.push_back(level);
        if( is_report_safe_with_dampener(report) )  result++;
        report.clear();
        n_reports++;
    }

    cout << "Reports: " << n_reports << endl;
    cout << "Reports Safe: " << result << endl;
}


int main() {
    day2_part2();
}