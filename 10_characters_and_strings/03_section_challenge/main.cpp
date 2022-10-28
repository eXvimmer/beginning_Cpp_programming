/*
 * Section 10 challenge
 * Substitution Cipher
 */

#include <iostream>
#include <string>

int main() {
  /* TODO: add numbers and important symbols too */
  std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
  std::string message{};
  std::string encrypted_message{};
  std::string decrypted_message{};

  std::cout << "Enter your secret message: ";
  std::getline(std::cin, message);
  std::cout << "\nEncrypting message...\n";

  for (char c : message) {
    char target{};
    size_t index = alphabet.find(c);
    target = index != std::string::npos ? key.at(index) : c;
    encrypted_message += target;
  }
  std::cout << "Encrypted message: " << encrypted_message << "\n";

  std::cout << "\nDecrypting message...\n";
  for (char c : encrypted_message) {
    char target{};
    size_t index = key.find(c);
    target = index != std::string::npos ? alphabet.at(index) : c;
    decrypted_message += target;
  }
  std::cout << "Dycrypted message: " << decrypted_message << "\n";
}
