#include <iomanip>
#include <iostream>

#include "SpecterLib/Algorithm.h"
#include "SpecterLib/Cryptography.h"

// Encodes and decodes string to obscrypto and decodes obscrypto for debugging and troubleshooting purposes
void main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "ObscryptoTool.exe <encoded obscrypto/raw quoted string>\n";
		return;
	}

	try
	{
		const std::string str = argv[1];

		if (Algorithm::IsBase64(str))
		{
			std::cout << "Decoded string: " << std::quoted(Cryptography::FromObscryptoB64(str)) << '\n';
		}
		else
		{
			// TODO validate args before encoding

			const auto key = Algorithm::GenerateRandomUInt<uint8_t>();
			std::cout << "Encoded string: " << std::quoted(Cryptography::ToObscryptoB64(str, key)) << '\n';
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Failed, exception occurred: " << std::quoted(e.what()) << '\n';
	}
}
