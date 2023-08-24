#include "NosoCpp.h"
nCripto cripto;
nUtils utils;

WalletObject* NosoCpp::CreateNewAddress() {
	NosoC::KeyPair KeysPair = cripto.generateECKeysPair();

	WalletObject* walletObject = new WalletObject();

	walletObject->PublicKey = KeysPair.PublicKey;
	walletObject->PrivateKey = KeysPair.PrivateKey;
	walletObject->Hash = cripto.getAddressFromPublicKey(KeysPair.PublicKey);

	std::cout << "  #Create Wallet Wallet Object:" << std::endl;
	std::cout << "  #PublicKey: " << walletObject->PublicKey << std::endl;
	std::cout << "  #PrivateKey: " << walletObject->PrivateKey << std::endl;
	std::cout << "  #Hash: " << walletObject->Hash << std::endl;
	return nullptr;
}

WalletObject* NosoCpp::ImportWalletForKeys(std::string& keys) {


	NosoC::KeyPair keysPair = utils.StringTokenizer(keys);
	bool verification = cripto.verifySignedString(NosoC::StringSignature, keysPair.PublicKey);

	if (verification && utils.checkSizesKeyPair(keysPair)) {
		WalletObject* walletObject = new WalletObject();
		walletObject->PublicKey = keysPair.PublicKey;
		walletObject->PrivateKey = keysPair.PrivateKey;
		walletObject->Hash = cripto.getAddressFromPublicKey(keysPair.PublicKey);

		std::cout << "  #Wallet Object:" << std::endl;
		std::cout << "  #Hash: " << walletObject->Hash << std::endl;
		std::cout << "  #Public Key: " << walletObject->PublicKey << std::endl;
		std::cout << "  #Private Key: " << walletObject->PrivateKey << std::endl;
		return walletObject;
	}
	else
	{
		std::cout << "  #Error -> Invalid input keys." << std::endl;
	}

	return nullptr;
}

bool NosoCpp::operator==(const NosoCpp& other) const
{
	return false;
}



