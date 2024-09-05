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

    // char message[] = "Hello, Naveen , I love you";
    string message1;
    cout << "Enter Message: ";
    getline(cin, message1);
    char message[message1.length() + 1];
    strcpy(message, message1.c_str());
    // TODO: Need to take input in place of message
    octet plaintext = {0, static_cast<int>(sizeof(message) - 1), (char *)message};

    octet ciphertext;
    ciphertext.len = RFS_RSA2048;
    ciphertext.val = (char *)malloc(RFS_RSA2048);

    hash256 hashe;

    core::HASH256_init(&hashe);
    for (int i = 0; i < plaintext.len; i++)
    {
        core::HASH256_process(&hashe, plaintext.val[i]);
    }
    core::HASH256_hash(&hashe, ciphertext.val);

    cout << "Hashed Value: ";
    OCT_output(&ciphertext);
    cout << endl;

    RSA2048::RSA_ENCRYPT(&pub, &plaintext, &ciphertext);

    octet decrypted;
    decrypted.len = RFS_RSA2048;
    decrypted.val = (char *)malloc(RFS_RSA2048);

    RSA2048::RSA_DECRYPT(&priv, &ciphertext, &decrypted);

    // Convert decrypted value to ASCII and print only the actual message
    cout << "Decrypted Value (ASCII): ";
    int message_len = sizeof(message) - 1;  // Length of the original message

    for (int i = 0; i < message_len; i++)
    {
        cout << decrypted.val[i];
    }
    cout << endl;

    RSA2048::RSA_PRIVATE_KEY_KILL(&priv);
    free(ciphertext.val);
    free(decrypted.val);

    return 0;
}
