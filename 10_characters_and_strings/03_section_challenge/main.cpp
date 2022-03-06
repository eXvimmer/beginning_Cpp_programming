/*
 * Section 10 challenge
 * Substitution Cipher
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
  string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
  string message{};
  string encrypted_message{};
  string decrypted_message{};

  cout << "Enter your secret message: ";
  std::getline(cin, message);
  cout << "\nEncrypting message...\n";

  for (char c : message) {
    char target{};
    size_t index = alphabet.find(c);
    target = index != string::npos ? key.at(index) : c;
    encrypted_message += target;
  }
  cout << "Encrypted message: " << encrypted_message << "\n";

  cout << "\nDecrypting message...\n";
  for (char c : encrypted_message) {
    char target{};
    size_t index = key.find(c);
    target = index != string::npos ? alphabet.at(index) : c;
    decrypted_message += target;
  }
  cout << "Dycrypted message: " << decrypted_message << "\n";
}
