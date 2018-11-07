//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE( "Command line read correctly", "[parsing]"){

  ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};

  SECTION("help command correctly parsed"){
    SECTION("-h"){
      const std::vector<std::string> args{"program-name","-h"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE( settings.helpRequested == true);
    }
    SECTION("--help"){
      const std::vector<std::string> args{"program-name","--help"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE( settings.helpRequested == true);
    }
  }

  SECTION("version requested correctly parsed"){
    const std::vector<std::string> args{"program-name","--version"};
    bool res { processCommandLine(args, settings) };
    REQUIRE(res);
    REQUIRE( settings.versionRequested == true);
  }

  SECTION("input file correctly parsed"){
    SECTION("input file indicated but not provided"){
      const std::vector<std::string> args{"program-name","-i"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(!res);
    }
    SECTION("input file indicated and provided"){
      const std::vector<std::string> args{"program-name","-i","Input.txt"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE( settings.inputFile == "Input.txt");
    }
  }

  SECTION("output file correctly parsed"){
    SECTION("output file indicated but not provided"){
      const std::vector<std::string> args{"program-name","-o"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(!res);
    }
    SECTION("output file indicated and provided"){
      const std::vector<std::string> args{"program-name","-o", "Output.txt"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE( settings.outputFile == "Output.txt");
    }
  }

  SECTION("key correctly parsed"){
    SECTION("key indicated but not provided"){
      const std::vector<std::string> args{"program-name","-k"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(!res);
    }
    SECTION("key indicated and provided"){
      const std::vector<std::string> args{"program-name","-k","6"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE( settings.cipher_key == "6");
    }
  }

  SECTION("cipher mode correctly parsed"){
    SECTION("encrypt"){
      const std::vector<std::string> args{"program-name","--encrypt"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE(settings.encrypt == CipherMode::Encrypt);
    }
    SECTION("decrypt"){
      const std::vector<std::string> args{"program-name","--decrypt"};
      bool res { processCommandLine(args, settings) };
      REQUIRE(res);
      REQUIRE(settings.encrypt == CipherMode::Decrypt);
    }
  }

  SECTION("multiple argument check"){
    const std::vector<std::string> args{"program-name","--decrypt","-k","1","-i","Input.txt","-o","Output.txt"};
    bool res { processCommandLine(args, settings) };
    REQUIRE(res);
    REQUIRE(settings.encrypt == CipherMode::Decrypt);
    REQUIRE(settings.cipher_key == "1");
    REQUIRE(settings.inputFile == "Input.txt");
    REQUIRE(settings.outputFile == "Output.txt");
    REQUIRE(settings.helpRequested == false);
    REQUIRE(settings.versionRequested ==false);
  }
}
