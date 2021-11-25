#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "Cipher.hpp"
#include "CipherType.hpp"

#include <memory>
#include <string>

/**
 * \file CipherFactory.hpp
 * \brief  Declaration of the factory function for Cipher objects
 */

/**
 * \brief Create a Cipher object of the required concrete type, constructed from the supplied key
 * 
 * \param type the contrete type of Cipher object to be constructed
 * \param key the key with which to construct the cipher
 * \return the newly constructed Cipher object
 */

std::unique_ptr<Cipher> cipherFactory( const CipherType type,
                                        const std::string& key);

#endif // MPAGSCIPHER_CIPHERFACTORY_HPP
