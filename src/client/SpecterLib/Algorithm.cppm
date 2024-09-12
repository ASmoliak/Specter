module;
#include <vector>
#include <string>
#include <random>

#include <boost/beast/core/detail/base64.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
export module Algorithm;

export class Algorithm
{
public:
	Algorithm() = delete;

	static std::string EncodeBase64(const std::vector<uint8_t>& raw_content)
	{
		using namespace boost::beast::detail;
		const auto encoded_size = base64::encoded_size(raw_content.size());

		std::string base64;
		base64.resize(encoded_size);
		base64::encode(base64.data(), raw_content.data(), raw_content.size());

		return base64;
	}

	static std::vector<uint8_t> DecodeBase64(const std::string& base64)
	{
		using namespace boost::beast::detail;
		const auto decoded_size = base64::decoded_size(base64.size());

		std::vector<uint8_t> raw_content;
		raw_content.resize(decoded_size);
		base64::decode(raw_content.data(), base64.data(), base64.size());

		return raw_content;
	}

	static std::string BuildUuid()
	{
		const auto uuid = boost::uuids::random_generator()();

		return boost::lexical_cast<std::string>(uuid);
	}

	// Generates random number, you can specify the minimum and maximum
	// Or not specify anything if you want the full possible range for that integer type.
	template <typename T>
	static T GenerateRandomUInt(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
	{
		return static_cast<T>(GenerateRandomUIntImpl(min, max));
	}

private:
	static uint64_t GenerateRandomUIntImpl(uint64_t min, uint64_t max)
	{
		std::random_device random_device;
		std::mt19937 generator(random_device());
		std::uniform_int_distribution distribution(min, max);

		return distribution(generator);
	}
};
