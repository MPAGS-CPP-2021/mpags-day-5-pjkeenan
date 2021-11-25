#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

#include <string>
#include <iostream>
#include <algorithm>

VigenereCipher::VigenereCipher (const std::string& key) {
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {

    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key.empty()){
        key_ = 'A'; // Think this results in null encryption??
        std::cout << "Added null encryption key" << std::endl;
    }

    // loop over the key
    charLookup_.clear();
    for (const auto& keyChar : key_) {
        // Find the letter position in the alphabet
        for ( std::size_t i {0}; i < Alphabet::size; ++i) {
            if (keyChar == Alphabet::alphabet[i]) {
                // Create a CaesarCipher using this position as a key
                CaesarCipher cipher{i};
                // Insert a std::pair of the letter and CaesarCipher into the lookup
                charLookup_.insert(std::make_pair(keyChar, cipher));
            }
        }
    }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const {
    std::string outputText {""};
    // For each letter in input:
    for (std::size_t i{0}; i < inputText.size(); ++i) {
        // Find the corresponding letter in the key, repeating/truncating as required
        char keyLetter {key_[i % key_.size()]};
        // Find the Caesar cipher from the lookup
        auto charLoopupIter = charLookup_.find(keyLetter);
        auto ccipher = (*charLoopupIter).second;
        // Run the (de)encryption
        // Add the result to the output
        const std::string inputLetter {inputText[i]};
        outputText += ccipher.applyCipher(inputLetter, cipherMode);
    }
        
    return outputText;
}
