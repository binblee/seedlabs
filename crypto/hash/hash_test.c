#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/evp.h>

#define BIT24 unsigned char[3];

#define HASH3_IN_BYTES 3
typedef union {
    struct {
        unsigned int val: HASH3_IN_BYTES*8;
    } i;
    unsigned char cval[HASH3_IN_BYTES];
} BITS24TYPE;

typedef struct {
    unsigned char buf[256];
    int len;
} MSGTYPE;

int msg_compare(MSGTYPE* msg1, MSGTYPE* msg2){
    if(msg1->len != msg2->len){
        return msg1->len < msg2->len;
    }
    for(int i=0; i<msg1->len; i++){
        if(msg1->buf[i] != msg2->buf[i]){
            return msg1->buf[i] < msg2->buf[i];
        }
    }
    return 0;
}

void octal2string(unsigned char* buf, int size, char* str){
    strcpy(str,"0x");
    for(int i=0; i<size; i++){
        sprintf(str+strlen(str),"%02x",buf[i]);
    }
}

void msg_set(MSGTYPE* msg, int num){
    BITS24TYPE tmp;
    tmp.i.val = num;
    memcpy(msg->buf, tmp.cval, 3);
    msg->len = 3;
}


void generate_random(MSGTYPE* msg, int number_in_bytes){
    int devRandom = open("/dev/random", O_RDONLY);
    ssize_t result_size = read(devRandom,msg->buf, number_in_bytes);
    msg->len = result_size;
    close(devRandom);

}

BITS24TYPE hash24bits(char* digestname,unsigned char* message, int message_len){
    BITS24TYPE hash_bits24;
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char full_hash_value[EVP_MAX_MD_SIZE];
    int full_hash_size;

    OpenSSL_add_all_digests();
    md = EVP_get_digestbyname(digestname);
    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, message, message_len);
    EVP_DigestFinal_ex(mdctx, full_hash_value, &full_hash_size);
    EVP_MD_CTX_destroy(mdctx);
    memcpy(hash_bits24.cval,full_hash_value,HASH3_IN_BYTES);
    EVP_cleanup();
    return hash_bits24;
}

void display_msg_hash(MSGTYPE* msg, BITS24TYPE* hash_value){
    char str[256];
    octal2string(msg->buf,msg->len,str);
    printf("message:%s",str);

    *hash_value = hash24bits("md5",msg->buf,msg->len);
    octal2string(hash_value->cval,3,str);
    printf("(hash:%s)\n",str);
}

// message = 3 octals
// hash = 3 octals
// To break one-way property:
// how many trials to find first preimage
void find_first_preimage(){
    printf("find first preimage\n");
    char str[256];
    MSGTYPE msg;

    generate_random(&msg,3);
    BITS24TYPE hash_value = hash24bits("md5",msg.buf,msg.len);
    display_msg_hash(&msg, &hash_value);

    for(int i=0; i< 1 << 24; i++){
        MSGTYPE trial_num;
        msg_set(&trial_num, i);
        BITS24TYPE hash_trial = hash24bits("md5",trial_num.buf,trial_num.len);
        if( hash_value.i.val == hash_trial.i.val
            && msg_compare(&msg, &trial_num) == 0 ){
            octal2string(trial_num.buf,trial_num.len,str);
            printf("found first preimage:%s with %d(%x) trials\n", str, i, i);
            break;
        }
    }
}

int main(){
    find_first_preimage();
    return 0;
}
