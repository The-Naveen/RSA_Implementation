#include <bits/stdc++.h>
using namespace std;
using namespace WWW;

#include "Lib/rsa.h"
#include "Lib/randapi.h" 
// #include "Lib/hash.h"

int main() {

    unsigned long ran;
    char raw[100];
    octet RAW = {0, sizeof(raw), raw};
    csprng rng;

    // Improve seed generation by combining time and random_device
    std::random_device rd;
    ran = static_cast<unsigned long>(time(nullptr)) ^ rd();

    // Populate RAW with random data
    RAW.len = 100;
    RAW.val[0] = ran;
    RAW.val[1] = ran >> 8;
    RAW.val[2] = ran >> 16;
    RAW.val[3] = ran >> 24;

    // Fill the rest of RAW with high-entropy data
    for (int i = 4; i < 100; i++)
    {
        RAW.val[i] = rd() & 0xFF; // Use random_device to fill the remaining bytes
    }

    // Initialize CSPRNG
    core::CREATE_CSPRNG(&rng, &RAW);

    // Use try-catch to handle potential exceptions
    // try
    // {
    //     Key key(&RNG);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     core::KILL_CSPRNG(&RNG);
    //     return -1;
    // }

    rsa_private_key priv;
    rsa_public_key pub;
    sign32 e = 65537;


    WWW::RSA_KEY_PAIR(&rng, e, &priv, &pub, nullptr, nullptr);

    char message[] = "Hello, RSA!";
    // cin << message;
    octet plaintext = {0, sizeof(message), (char *)message};
    octet ciphertext;
    ciphertext.len = RFS_WWW; 
    ciphertext.val = (char *)malloc(RFS_WWW);

    octet chipertexthash;
    chipertexthash.len = RFS_WWW;
    chipertexthash.val = (char *)malloc(RFS_WWW);

    hash256 hashe;

    RSA_ENCRYPT(&pub, &plaintext, &ciphertext);

    octet decrypted;
    decrypted.len = RFS_WWW;
    decrypted.val = (char *)malloc(RFS_WWW);

    RSA_DECRYPT(&priv, &ciphertext, &decrypted);

    printf("Decrypted message: %s\n", decrypted.val);

    RSA_PRIVATE_KEY_KILL(&priv);
    free(ciphertext.val);
    free(decrypted.val);

    return 0;
}
