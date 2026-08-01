#include <bits/stdc++.h>
using namespace std;

string receivedText(string S) {
    list<char> text;
    auto cursor = text.begin();

    bool numbersEnabled = true;   // Initially numbers can be typed

    for (char ch : S) {
        if (ch == '<') {
            cursor = text.begin();
        }
        else if (ch == '>') {
            cursor = text.end();
        }
        else if (ch == '*') {
            if (cursor != text.begin()) {
                auto it = cursor;
                --it;                  // Character before cursor
                cursor = text.erase(it);
            }
        }
        else if (ch == '#') {
            numbersEnabled = !numbersEnabled;
        }
        else {
            if (isdigit(ch) && !numbersEnabled)
                continue;              // Ignore digits

            text.insert(cursor, ch);   // Insert before cursor
        }
    }

    return string(text.begin(), text.end());
}

int main() {
    string S;
    cin >> S;
    cout << receivedText(S);
    return 0;
}
