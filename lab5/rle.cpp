#include <iostream>

using namespace std;

string encode(string text) {

    int len = text.length();
    string encoded = "";

    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && text[i] == text[i + 1]) {
            count++;
            i++;
        }
        encoded += (text[i] + to_string(count));
    }
    return encoded;
}

string decode(string text) {

    int len = text.length();
    string decoded = "";

    for (int i = 0; i < len; i++) {
        char c = text[i];
        i++;

        int count = 0;
        while (i < len && isdigit(text[i])) {
            count = count * 10 + (text[i] - '0');
            i++;
        }
        i--;

        for (int j = 0; j < count; j++)
            decoded += c;
    }

    return decoded;
}

int main() {

    string text;

    cout << "Enter text: ";
    getline(cin, text);

    string encoded = encode(text);

    cout << "String: " << text << endl;
    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decode(encoded) << endl;

    return 0;
}