/*
 * This code is licensed under the terms of the MIT License.
 *
 * Author: pasichDev
 * Repository: https://github.com/pasichDev/NosoCpp
 *
 * See LICENSE file for details.
 */
#ifndef OBJECTS_H
#define OBJECTS_H
#include <botan/bigint.h>

namespace NosoC {



	class KeyPair {
	public:
		std::string PublicKey;
		std::string PrivateKey;

	};

	enum class KeyType {
		SECP256K1,
		SECP384R1,
		SECP521R1,
		SECT283K1
	};

	class DivResult {
	public:
		Botan::BigInt Quotient;
		Botan::BigInt Remainder;
	};

}

#endif 
