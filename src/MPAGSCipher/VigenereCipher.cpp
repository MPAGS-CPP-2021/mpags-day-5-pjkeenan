#include "VigenereCipher.hpp"

#include <string>
#include <iostream>

VigenereCipher::VigenereCipher (const std::string& key) {
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {
    std::cout << key << std::endl;
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode /*cipherMode*/ ) const {
    return inputText;
}