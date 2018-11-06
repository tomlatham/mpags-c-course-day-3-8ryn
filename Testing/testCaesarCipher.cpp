//! Unit Tests for MPAGSCipher caesarCipher interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Cipher applied correctly"){
  const std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  CaesarCipher cipher{"11"};
  SECTION("encrypt"){
    const std::string encrypted{cipher.applyCipher(alphabet,CipherMode::Encrypt)};
    REQUIRE(encrypted == "LMNOPQRSTUVWXYZABCDEFGHIJK");
  }
  SECTION("decrypt"){
    const std::string decrypted{cipher.applyCipher(alphabet,CipherMode::Decrypt)};
    REQUIRE(decrypted == "PQRSTUVWXYZABCDEFGHIJKLMNO");
  }
}
