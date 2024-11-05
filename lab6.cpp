// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Cipher {
    public:
    
        Cipher(int n) {
            this->n = n;
        }
    
        string encrypt(const string& text) {
            string encrypted;
            auto matrix = generateKey(text);
        
            cout << "Encrypt key:" << endl;
            for (const auto& row : matrix) {
                for (char ch : row) {
                    cout << ch << " ";
                }
                cout << endl;
            }
        
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < matrix.size(); i++) {
                    encrypted += matrix[i][j];
                }
            }
            
            string compressed = compress(encrypted);
        
            return compressed;
        }
        
        string decrypt(string& text) {
            text = decompress(text);
            string decrypted;
            auto matrix = generateDecryptKey(text);
        
            cout << "Decrypt key:" << endl;
            for (const auto& row : matrix) {
                for (char ch : row) {
                    cout << ch << " ";
                }
                cout << endl;
            }
        
            for (const auto& row : matrix) {
                for (char ch : row) {
                    decrypted += ch;
                }
            }
        
            return decrypted;
        }
    
    private:
        int n;
        vector<vector<char>> generateKey(const string& text) {
            int rows = (text.size() + n - 1) / n;
            vector<vector<char>> matrix(rows, vector<char>(n, ' '));
        
            int k = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < n; j++) {
                    if (k < text.length()) {
                        matrix[i][j] = text[k++];
                    }
                }
            }
            return matrix;
        }
        
        vector<vector<char>> generateDecryptKey(const string& text) {
            int rows = (text.size() + n - 1) / n;
            vector<vector<char>> matrix(rows, vector<char>(n, ' '));
        
            int k = 0;
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < rows; i++) {
                    if (k < text.length()) {
                        matrix[i][j] = text[k++];
                    }
                }
            }
            return matrix;
        }
        
        string compress(const string& input) {
            stringstream result;
            int count = 1;
    
            for (size_t i = 1; i <= input.size(); ++i) {
                if (i < input.size() && input[i] == input[i - 1]) {
                    ++count;
                } else {
                    result << input[i - 1];
                    result << (char)count;
                    count = 1;
                }
            }
    
            return result.str();
        }

        string decompress(const string& input) {
            stringstream result;

            for (size_t i = 0; i < input.size(); i += 2) {
                char ch = input[i];
                int count = (char)input[i + 1];
        
                result << string(count, ch);
            }

            return result.str();
        }
};

int main() {
    int n = 4;
    Cipher obj(n);
    string text = "barev";
    string test = obj.encrypt(text);
    cout << test;
    cout << endl;
    cout << obj.decrypt(test);

    return 0;
}
