#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int do_crypt(FILE *in, FILE *out, int do_encrypt){
    /* Allow enough space in output buffer for additional block */
    unsigned char inbuf[1024], outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
    int inlen, outlen;
    EVP_CIPHER_CTX ctx;
    /* Bogus key and IV: we'd normally set these from
     * another source.
     */
    unsigned char key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    unsigned char iv[] = {1,2,3,4,5,6,7,8,8,7,6,5,4,3,2,1};

    /* Don't set key or IV right away; we want to check lengths */
    EVP_CIPHER_CTX_init(&ctx);
    EVP_CipherInit_ex(&ctx, EVP_aes_128_cbc(), NULL, NULL, NULL,
            do_encrypt);
    OPENSSL_assert(EVP_CIPHER_CTX_key_length(&ctx) == 16);
    OPENSSL_assert(EVP_CIPHER_CTX_iv_length(&ctx) == 16);

    /* Now we can set key and IV */
    EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, do_encrypt);

    for(;;)
            {
            inlen = fread(inbuf, 1, 1024, in);
            if(inlen <= 0) break;
            if(!EVP_CipherUpdate(&ctx, outbuf, &outlen, inbuf, inlen))
                    {
                    /* Error */
                    EVP_CIPHER_CTX_cleanup(&ctx);
                    return 0;
                    }
            fwrite(outbuf, 1, outlen, out);
            }
    if(!EVP_CipherFinal_ex(&ctx, outbuf, &outlen))
            {
            /* Error */
            EVP_CIPHER_CTX_cleanup(&ctx);
            return 0;
            }
    fwrite(outbuf, 1, outlen, out);

    EVP_CIPHER_CTX_cleanup(&ctx);
    return 1;
}
void main(){
    FILE *in = fopen("crypttext", "rb");
    FILE *out = fopen("crypttext-e", "wb");
    do_crypt(in, out, 1);
    fclose(in);
    fclose(out);
}
