#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

//Standard Library includes
#include <string>
#include <vector>

// Our project headers
#include "CipherMode.hpp"

class CaesarCipher {
  public:
    explicit CaesarCipher(const size_t key);
    explicit CaesarCipher(const std::string& key);
    std::string applyCipher(const std::string& inputText, const CipherMode encrypt) const;

  private:
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const size_t alphabetSize_ = alphabet_.size();
    size_t key_ = 0;
  
};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
