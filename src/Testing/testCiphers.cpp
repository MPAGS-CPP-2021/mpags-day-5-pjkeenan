#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, 
    const std::string& inputText, const std::string& outputText) {
        std::string cipheredText {cipher.applyCipher(inputText, mode)};
        return cipheredText == outputText;
    }

TEST_CASE("Test encryption ALL classical ciphers", "[all ciphers]")
{
    std::vector<std::unique_ptr<Cipher>> cipherCollection;
    cipherCollection.push_back(cipherFactory(CipherType::Caesar, "10"));
    cipherCollection.push_back(cipherFactory(CipherType::Playfair, "hello"));
    cipherCollection.push_back(cipherFactory(CipherType::Vigenere, "KEY"));

    std::vector<std::string> plaintext;
    plaintext.push_back("HELLOWORLD");
    plaintext.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
    plaintext.push_back("HELLOWORLD");

    std::vector<std::string> ciphertext;
    ciphertext.push_back("ROVVYGYBVN");
    ciphertext.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
    ciphertext.push_back("RIJVSUYVJN");

    for(std::vector<int>::size_type i {0}; i < plaintext.size(); ++i){
        REQUIRE(cipherCollection.at(i) -> applyCipher(plaintext.at(i), CipherMode::Encrypt) == ciphertext.at(i));
    }
}

TEST_CASE("Test decryption ALL classical ciphers", "[all ciphers]")
{
    std::vector<std::unique_ptr<Cipher>> cipherCollection;
    cipherCollection.push_back(cipherFactory(CipherType::Caesar, "10"));
    cipherCollection.push_back(cipherFactory(CipherType::Playfair, "hello"));
    cipherCollection.push_back(cipherFactory(CipherType::Vigenere, "KEY"));

    std::vector<std::string> plainText;
    plainText.push_back("ROVVYGYBVN");
    plainText.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
    plainText.push_back("RIJVSUYVJN");

    std::vector<std::string> cipherText;
    cipherText.push_back("HELLOWORLD");
    cipherText.push_back("BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
    cipherText.push_back("HELLOWORLD");

    for(std::vector<int>::size_type i {0}; i < plainText.size(); ++i){
        REQUIRE(cipherCollection.at(i) -> applyCipher(plainText.at(i), CipherMode::Decrypt) == cipherText.at(i));
    }
}

TEST_CASE("Test each classical cipher", "[all ciphers]")
{
    CaesarCipher cc{10};
    REQUIRE(testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") == true);
    REQUIRE(testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") == true);

    PlayfairCipher pc{"hello"};
    REQUIRE(testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") == true);
    REQUIRE(testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") == true);

    VigenereCipher vc{"KEY"};
    REQUIRE(testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN") == true);
    REQUIRE(testCipher(vc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD") == true);
    
}