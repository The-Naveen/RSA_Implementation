#include <bits/stdc++.h>
using namespace std;

#include "Lib/rsa_RSA2048.h"
#include "Lib/randapi.h"

int main()
{
    unsigned long ran;
    char raw[100];
    octet RAW = {0, sizeof(raw), raw};
    csprng rng;

    std::random_device rd;
    ran = static_cast<unsigned long>(time(nullptr)) ^ rd();

    RAW.len = 100;
    RAW.val[0] = ran;
    RAW.val[1] = ran >> 8;
    RAW.val[2] = ran >> 16;
    RAW.val[3] = ran >> 24;

    for (int i = 4; i < 100; i++)
    {
        RAW.val[i] = rd() & 0xFF;
    }

    core::CREATE_CSPRNG(&rng, &RAW);

    RSA2048::rsa_private_key priv;
    RSA2048::rsa_public_key pub;
    sign32 e = 65537;

    RSA2048::RSA_KEY_PAIR(&rng, e, &priv, &pub, nullptr, nullptr);

    char message[] = "Hello, RSA!";
    //TODO need to take input in place of message
    octet plaintext = {0, sizeof(message) - 1, (char *)message};
    octet ciphertext;
    ciphertext.len = RFS_RSA2048;
    ciphertext.val = (char *)malloc(RFS_RSA2048);

    octet chipertexthash;
    chipertexthash.len = 32;
    chipertexthash.val = (char *)malloc(32);

    hash256 hashe;

    core::HASH256_init(&hashe);
    for (int i = 0; i < plaintext.len; i++)
    {
        core::HASH256_process(&hashe, plaintext.val[i]);
    }
    core::HASH256_hash(&hashe, chipertexthash.val);

    cout << "Hashed Value: ";
    OCT_output(&chipertexthash);
    cout<<endl;

    RSA2048::RSA_ENCRYPT(&pub, &plaintext, &ciphertext); // correct till here

    octet decrypted;
    decrypted.len = RFS_RSA2048;
    decrypted.val = (char *)malloc(RFS_RSA2048);

    RSA2048::RSA_DECRYPT(&priv, &ciphertext, &decrypted);

    printf("Decrypted message: %s\n", decrypted.val);

    RSA2048::RSA_PRIVATE_KEY_KILL(&priv);
    free(ciphertext.val);
    free(decrypted.val);
    free(chipertexthash.val);

    return 0;
}
