#include "Algorithm.h"

#include <random>

#include <boost/beast/core/detail/base64.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost::beast::detail;

std::string Algorithm::EncodeBase64(const std::vector<uint8_t>& content)
{
	std::string encoded(base64::encoded_size(content.size()), 0);
	base64::encode(encoded.data(), content.data(), content.size());
	return encoded;
}

std::vector<uint8_t> Algorithm::DecodeBase64(const std::string& base64)
{
	std::vector<uint8_t> decoded(base64::decoded_size(base64.size()), 0);
	base64::decode(decoded.data(), base64.data(), base64.size());
	return decoded;
}

bool Algorithm::IsBase64(const std::string& str)
{
	if (str.size() % 4)
	{
		return false;
	}

	try
	{
		std::vector<uint8_t> decoded(base64::decoded_size(str.size()), 0);
		const auto [outputSize, _] = base64::decode(decoded.data(), str.data(), str.size());
		return outputSize == decoded.size();
	}
	catch (...)
	{
		return false;
	}
}

std::string Algorithm::BuildUuid()
{
	const auto uuid = boost::uuids::random_generator()();
	return boost::lexical_cast<std::string>(uuid);
}

uint64_t Algorithm::GenerateRandomUIntImpl(uint64_t min, uint64_t max)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution distribution(min, max);
	return distribution(generator);
}
