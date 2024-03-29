//
// Created by Reed Steve on 2024/3/9.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

inline void notify_ignored() {
    cout << "Ignored" << endl;
}

class Navigator {
    string location[100];
    size_t ptr, size;
public:
    Navigator(const string &home) : location{home}, ptr(0), size(1) {}

    const string &get_location() const {
        if (ptr >= 0) {
            return location[ptr];
        } else {
            return "";
        }
    }

    bool forward() {
        if (ptr < size - 1) {
            ptr++;
            return true;
        } else {
            return false;
        }
    }

    bool back() {
        if (ptr > 0) {
            ptr--;
            return true;
        } else {
            return false;
        }
    }

    void visit(const string &url) {
        location[++ptr] = url;
        size = ptr + 1;
    }
};

bool run_browser() {
    Navigator navigator("http://www.acm.org/");
    string cmd;
    while (getline(cin, cmd)) {
        if (cmd == "QUIT") {
            return true;
        } else if (cmd == "FORWARD") {
            if (navigator.forward()) {
                cout << navigator.get_location() << endl;
            } else {
                notify_ignored();
            }
        } else if (cmd == "BACK") {
            if (navigator.back()) {
                cout << navigator.get_location() << endl;
            } else {
                notify_ignored();
            }
        } else if (cmd.size() >= 5 && cmd.substr(0, 6) == "VISIT ") {
            auto url = cmd.substr(6);
            navigator.visit(url);
            cout << navigator.get_location() << endl;
        }
    }
    return false;
}

int main() {
    while (run_browser()) {}
    return 0;
}