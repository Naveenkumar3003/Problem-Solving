#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main() {

    vector<string> arr = {
        "Apple123",
        "APPLE45",
        "banana123",
        "PineApple99",
        "123apple",
        "Orange"
    };

    string searchText = "apple";

    int count = 0;

    for (string s : arr) {

        // Convert a copy to lowercase
        string lower = s;

        for (char &c : lower) {
            c = tolower(c);
        }

        // Check if searchText is present
        if (lower.find(searchText) != string::npos) {
            cout << s << endl;   // Print original string
            count++;
        }
    }

    cout << "Count: " << count << endl;

    return 0;
}
