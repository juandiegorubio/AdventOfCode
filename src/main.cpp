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
        
        if( abs(diff) < 1 || abs(diff) > 3 ) return false;
        if( order_set && (is_order_increasing != (diff > 0)) ) return false;
        if( !order_set ) {
            is_order_increasing = (diff > 0);
            order_set = true;
        }
        
        prev_level = level;
    }
    return true;
}


bool is_report_safe_tolerable(vector<int> report) {
    
    int diff, level, prev_level = report[0];
    bool is_order_increasing, order_set = false;

    for(long unsigned int i=1; i < report.size(); ++i) {
        level = report[i];
        diff = level - prev_level;

        
    }
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
    int result = 0;

    while(getline(cin, input)) {
        stringstream report_str(input);
        for(int level=0; report_str >> level; ) report.push_back(level);
        if( is_report_safe_tolerable(report) )  result++;
        report.clear();
    }

    cout << "Reports Safe: " << result << endl;
}


int main() {
    day2_part1();
}