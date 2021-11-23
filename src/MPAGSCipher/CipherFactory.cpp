// #include <memory>
// #include <string>

// //#include "Cipher.hpp"
// #include "CipherFactory.hpp"
// //#include "CipherType.hpp"
// #include "CaesarCipher.hpp"
// #include "PlayfairCipher.hpp"
// #include "VigenereCipher.hpp"

// std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key) {
//     switch (type) {
//         case CipherType::Caesar :
//             return std::make_unique<CaesarCipher>(key);
//             break;
//         case CipherType::Playfair :
//             return std::make_unique<PlayfairCipher>(key);
//             break;
//         case CipherType::Vigenere :
//             return std::make_unique<VigenereCipher>(key);
//             break;
//     }
//     // Incase some how get out of the switch cases?
//     return std::unique_ptr<Cipher>{};
// }


#include <memory>
#include <string>

#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory( const CipherType type,
                                        const std::string& key)
{
        switch (type)
        {
            case CipherType::Caesar :
                return std::make_unique<CaesarCipher> (key);
            case CipherType::Playfair :
                return std::make_unique<PlayfairCipher> (key);
            case CipherType::Vigenere :
                return std::make_unique<VigenereCipher> (key);
        }
        return nullptr;
}
