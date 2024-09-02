# RSA Implementation with MIRACL Core

This project demonstrates the implementation of RSA encryption and decryption using the MIRACL Core cryptographic library. The RSA algorithm is a widely used public-key cryptosystem that enables secure data transmission and digital signatures.

## Overview

### RSA Algorithm

RSA is an asymmetric cryptographic algorithm that utilizes a pair of keys:
- **Public Key (`PUB`)**: Used for encrypting messages and verifying signatures.
- **Private Key (`PRIV`)**: Used for decrypting messages and generating signatures.

### Key Components

- **Public Key (`PUB`)**:
  - `n`: The modulus, computed as the product of two large prime numbers `p` and `q`.
  - `e`: The public exponent, typically a small odd number like 65537.

- **Private Key (`PRIV`)**:
  - `p`: A large prime number.
  - `q`: Another large prime number.
  - `dp`: Private exponent for `p`.
  - `dq`: Private exponent for `q`.
  - `c`: Inverse of `p` modulo `q`.

## Key Pair Generation

The function `RSA_KEY_PAIR` generates an RSA key pair, including the public and private keys.

### Steps:

1. **Prime Generation**: 
   - The function generates two large prime numbers `p` and `q`.
   - The primes are selected such that they satisfy specific conditions, such as `p mod 4 = 3`.

2. **Compute Modulus (`n`)**: 
   - The modulus `n` is computed as the product of `p` and `q`.

3. **Compute Private Exponents (`dp`, `dq`)**: 
   - The private exponents `dp` and `dq` are computed using the formula:
     \[
     dp = e^{-1} \mod \left(\frac{p-1}{2}\right), \quad dq = e^{-1} \mod \left(\frac{q-1}{2}\right)
     \]

4. **Compute CRT Coefficient (`c`)**: 
   - `c` is computed as the inverse of `p` modulo `q` (or vice versa, depending on implementation).

## RSA Encryption

The `RSA_ENCRYPT` function encrypts a message using the public key.

### Steps:

1. **Convert Plaintext to Integer**: 
   - The plaintext (message) is converted into an integer `f`.

2. **Encryption**: 
   - The integer `f` is raised to the power of the public exponent `e` and taken modulo `n` to produce the ciphertext.

3. **Convert Back to Octet**: 
   - The resulting ciphertext is converted back to an octet string (byte array).

## RSA Decryption

The `RSA_DECRYPT` function decrypts a message using the private key.

### Steps:

1. **Convert Ciphertext to Integer**: 
   - The ciphertext is converted into an integer `g`.

2. **Decryption Using CRT**:
   - Compute `jp = g^dp mod p` and `jq = g^dq mod q`.
   - Combine `jp` and `jq` using the Chinese Remainder Theorem (CRT) to recover the original message.

3. **Convert Back to Octet**: 
   - The resulting plaintext is converted back to an octet string (byte array).

## Additional Functions

- **`RSA_PRIVATE_KEY_FROM_OPENSSL`**: 
  - Converts a private key from OpenSSL format to MIRACL format.

- **`RSA_KEY_PAIR_FROM_OPENSSL`**: 
  - Imports a key pair from OpenSSL.

- **`RSA_PRIVATE_KEY_KILL`**: 
  - Safely destroys a private key by zeroing out its components in memory.

## Conclusion

This implementation provides a foundation for secure communication, ensuring that only someone with the corresponding private key can decrypt a message encrypted with the public key. The security of RSA is based on the difficulty of factoring the large modulus `n` into its prime factors `p` and `q`, making it crucial that `p` and `q` are chosen carefully and kept secret.
