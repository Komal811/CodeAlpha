#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Encrypts the given text using Caesar Cipher
void encrypt(string &text, int key) {
    for (char &c : text) {
        if (isupper(c)) {
            c = (c - 'A' + key) % 26 + 'A';
        } else if (islower(c)) {
            c = (c - 'a' + key) % 26 + 'a';
        }
    }
}

// Decrypts the given text using Caesar Cipher
void decrypt(string &text, int key) {
    for (char &c : text) {
        if (isupper(c)) {
            c = (c - 'A' - key + 26) % 26 + 'A';
        } else if (islower(c)) {
            c = (c - 'a' - key + 26) % 26 + 'a';
        }
    }
}

int main() 
{
    string text;
    int key;
    int choice;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the key (integer value): ";
    cin >> key;

    cout << "Choose an operation (1 for Encrypt, 2 for Decrypt): ";
    cin >> choice;

    if (choice == 1) {
        encrypt(text, key);
        cout << "Encrypted text: " << text << endl;
    } else if (choice == 2) {
        decrypt(text, key);
        cout << "Decrypted text: " << text << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
