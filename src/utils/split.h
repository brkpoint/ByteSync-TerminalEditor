#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, string delimiter) {
    size_t pos = 0;
    vector<string> sf;

    while ((pos = s.find(delimiter)) != string::npos) {
        sf.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }

    sf.push_back(s);
    
    return sf;
}
