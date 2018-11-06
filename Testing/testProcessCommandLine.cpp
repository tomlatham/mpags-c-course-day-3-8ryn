//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE( "Command line read correctly", "[parsing]"){

  ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};

  SECTION("help command correctly parsed"){
    SECTION("-h"){
      const std::vector<std::string> args{"program-name","-h"};
      processCommandLine(args, settings);
      REQUIRE( settings.helpRequested == true);
    }
    SECTION("--help"){
      const std::vector<std::string> args{"program-name","--help"};
      processCommandLine(args, settings);
      REQUIRE( settings.helpRequested == true);
    }
  }

  SECTION("version requested correctly parsed"){
    const std::vector<std::string> args{"program-name","--version"};
    processCommandLine(args, settings);
    REQUIRE( settings.versionRequested == true);
  }

  SECTION("input file correctly parsed"){
    const std::vector<std::string> args{"program-name","-i","Input.txt"};
    processCommandLine(args, settings);
    REQUIRE( settings.inputFile == "Input.txt");
  }

  SECTION("output file correctly parsed"){
    const std::vector<std::string> args{"program-name","-o", "Output.txt"};
    processCommandLine(args, settings);
    REQUIRE( settings.outputFile == "Output.txt");
  }

  SECTION("key correctly parsed"){
    const std::vector<std::string> args{"program-name","-k","6"};
    processCommandLine(args, settings);
    REQUIRE( settings.cipher_key == "6");
  }

  SECTION("cipher mode correctly parsed"){
    SECTION("encrypt"){
      const std::vector<std::string> args{"program-name","--encrypt"};
      processCommandLine(args, settings);
      REQUIRE(settings.encrypt == CipherMode::Encrypt);
    }
    SECTION("decrypt"){
      const std::vector<std::string> args{"program-name","--decrypt"};
      processCommandLine(args, settings);
      REQUIRE(settings.encrypt == CipherMode::Decrypt);
    }
  }

  SECTION("multiple argument check"){
    const std::vector<std::string> args{"program-name","--decrypt","-k","1","-i","Input.txt","-o","Output.txt"};
    processCommandLine(args, settings);
    REQUIRE(settings.encrypt == CipherMode::Decrypt);
    REQUIRE(settings.cipher_key == "1");
    REQUIRE(settings.inputFile == "Input.txt");
    REQUIRE(settings.outputFile == "Output.txt");
    REQUIRE(settings.helpRequested == false);
    REQUIRE(settings.versionRequested ==false);
  }
}
