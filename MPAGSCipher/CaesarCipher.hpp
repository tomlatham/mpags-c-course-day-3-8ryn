#ifndef CAESARCIPHER_MPAGSCIPHER_HPP
#define CAESARCIPHER_MPAGSCIPHER_HPP

#include <string>
#include <iostream>

class CaesarCipher {
  public:
  explicit CaesarCipher(const size_t key);
  explicit CaesarCipher(const std::string key);
  size_t key_;
  
};

#endif //CAESARCIPHER_MPAGSCIPHER_HPP
