#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../utils/string.h"

using namespace std;

class file {
public:
    string path;
    string fullname;
    string name;
    string ext;

    file(string path) {
        this->path = path;

        vector<string> fpath = utils::split(path, "/");
        this->fullname = fpath.at(fpath.size() - 1);

        vector<string> fname = utils::split(fullname, ".");
        this->name = fname.at(0);
        this->ext = fname.at(fname.size() - 1);
    }

    int getFileContents(string& output) {
        ifstream inpt(path);

        string buffer;

        if (!inpt.is_open()) { 
            cerr << "Error opening the file '" + path + "'" << endl;
            return 1; 
        }

        while(getline(inpt, buffer)) {
            output += buffer + "\n";
        }

        output.erase(output.length() - 1, output.length());

        inpt.close();
        return 0;
    }
};
