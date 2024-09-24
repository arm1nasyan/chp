#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string makeKey() {

    string alph = "abcdefghijklmnopqrtsuvwxyz";
    string key = alph;

    srand(time(0));

    for (int i = key.length() - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        swap(key[i], key[j]);
    }

    return key;
}

string enqryptStr(string str, string key) {

    for (int i = 0; i < str.length(); i++) {
        int keyInd = int(str[i]) - 97;
        str[i] = key[keyInd];
    }

    return str;
}

string deqrypt(string str, string key) {
    string decripted = "";
    string alph = "abcdefghijklmnopqrtsuvwxyz";

    for (int i = 0; i < str.length(); i++) {
        bool check = false;
        int index = -1;
        for (int j = 0; j < key.length(); j++) {
            if (key[j] == str[i]) {
                check = true;
                index = j;
                break;
            }
        }
        if (check)
            decripted += alph[index];
    }

    return decripted;
}

bool checking(string str1, string str2) {
    return str1 == str2;
}

int main() {

    string key = makeKey();

    string textToHash;

    cout << "Enter text to encrypt: ";
    cin >> textToHash;

    string enqryptedText = enqryptStr(textToHash, key);

    cout << "Key: " << key;
    cout << "\n";
    cout << "Result: " << enqryptedText;

    string decrypted = deqrypt(enqryptedText, key);
    cout << endl << "decrypted: " << decrypted;

    cout << endl << (checking(decrypted, textToHash) ? "Ok" : "Something wrong!");

    return 0;
}