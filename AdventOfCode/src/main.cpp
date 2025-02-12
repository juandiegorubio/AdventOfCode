#include "days.hpp"
#include <iostream>
using namespace std;

int main() {
    string mem;
    cin >> mem;

    int mult_start = mem.find("mult(")+1;

    while(mult_start != mem.end()) {
        // Get X
        int comma_pos = mem.find(',', mult_start);
        if(comma_pos - mult_start < 1 || comma_pos - mult_start > 3) continue;
        int X = mem.substr()
 
        int mult_end = mem.find(')', mult_start);
        if(mult_end - comma_pos < 1 || mult_end - comma_pos > 3) continue;

    }    

}