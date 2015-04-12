#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DO_ENCRYPT 1
#define KEY_LEN 16
#define OUT_BUF_SIZE (1024 + EVP_MAX_BLOCK_LENGTH)

unsigned char ciphertext[] = {0x8d,0x20,0xe5,0x05,0x6a,0x8d,0x24,0xd0,0x46,0x2c,0xe7,0x4e,0x49,0x04,0xc1,0xb5,
0x13,0xe1,0x0d,0x1d,0xf4,0xa2,0xef,0x2a,0xd4,0x54,0x0f,0xae,0x1c,0xa0,0xaa,0xf9};

unsigned char *plaintext = "This is a top secret.";

int pad_space(unsigned char* key, int key_len){
    if(key_len < KEY_LEN){
        for(int i=key_len; i< KEY_LEN; i++){
            key[i] = 0x20;
        }
    }
}

int encrypt(unsigned char* buf_in, int buf_in_len,
    unsigned char* buf_out, int* buf_out_len, unsigned char* key, int key_len){

    int outlen;

    EVP_CIPHER_CTX ctx;
    pad_space(key, key_len);
    unsigned char iv[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    EVP_CIPHER_CTX_init(&ctx);
    EVP_CipherInit_ex(&ctx, EVP_aes_128_cbc(), NULL, NULL, NULL, DO_ENCRYPT);
    OPENSSL_assert(EVP_CIPHER_CTX_key_length(&ctx) == 16);
    OPENSSL_assert(EVP_CIPHER_CTX_iv_length(&ctx) == 16);
    EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, DO_ENCRYPT);

    EVP_CipherUpdate(&ctx, buf_out, &outlen, buf_in, buf_in_len);
    *buf_out_len = outlen;
    EVP_CipherFinal_ex(&ctx, buf_out + outlen, &outlen);
    *buf_out_len += outlen;
    EVP_CIPHER_CTX_cleanup(&ctx);
    return 1;
}

/*
* return 0 as equal, others as different
*/
int compare(unsigned char* buf1, int buf1_len, unsigned char* buf2, int buf2_len){
    if(buf1_len <=0 || buf2_len <=0 || buf1_len != buf2_len){
        return 1;
    }
    for(int i=0; i< buf1_len; i++){
        if(buf1[i] != buf2[i]){
            return 1;
        }
    }
    return 0;
}

int check_if_is_key(char* key){
    unsigned char outbuf[OUT_BUF_SIZE];
    int outbuf_len = 0;
    encrypt(plaintext, strlen(plaintext), outbuf, &outbuf_len, key, strlen(key));
    return compare(ciphertext, sizeof(ciphertext), outbuf, outbuf_len);
}


int main(){
    char line[256];
    FILE *fp = fopen("words" , "r");;
    if(fp != NULL){
        while( fgets (line, 255, fp) != NULL ) {
            line[strcspn(line, "\r\n")] = 0;
            if ( 0 == check_if_is_key(line) ){
                printf("Got key: %s\n", line);
                break;
            }
        }
        fclose(fp);
    }else{
        perror("Error open words file\n");
        return(-1);
    }
}
