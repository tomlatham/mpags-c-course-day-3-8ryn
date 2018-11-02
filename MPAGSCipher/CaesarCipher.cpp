#include "CaesarCipher.hpp"


CaesarCipher::CaesarCipher(const size_t key)
  :key_{key}{
}

CaesarCipher::CaesarCipher(const std::string key)
:key_{0}
{
  bool error{false};
  for ( const auto& elem : key ) {
    if ( ! std::isdigit(elem) ) {
      std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\
\n"
		<< "        the supplied key (" << key << ") could not be \
successfully converted and key has been set to 0" << std::endl;
      error = true;
      break;
    }
  }
  if(!error){
    key_ = std::stoul(key);
  }
}
