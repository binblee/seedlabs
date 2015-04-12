KVALUE=00112233445566778889aabbccddeeff
IVVALUE=0102030405060708
OPTIONS=-K $(KVALUE) -iv $(IVVALUE)

all: task1 task2

task1:
	openssl enc -aes-128-cbc -e -in pic_original.bmp -out pic_encrypted.bmp $(OPTIONS)
	openssl enc -aes-128-cbc -d -in pic_encrypted.bmp -out pic_decrypted.bmp $(OPTIONS)

task2:
	openssl enc -aes-128-cbc -e -in pic_original.bmp -out pic_aes-128-cbc.bmp $(OPTIONS)
	head -c 54 pic_original.bmp | dd of=pic_aes-128-cbc.bmp bs=1 seek=0 count=54 conv=notrunc

	openssl enc -aes-128-cfb -e -in pic_original.bmp -out pic_aes-128-cfb.bmp $(OPTIONS)
	head -c 54 pic_original.bmp | dd of=pic_aes-128-cfb.bmp bs=1 seek=0 count=54 conv=notrunc

	openssl enc -aes-256-ecb -e -in pic_original.bmp -out pic_aes-256-ecb.bmp $(OPTIONS)
	head -c 54 pic_original.bmp | dd of=pic_aes-256-ecb.bmp bs=1 seek=0 count=54 conv=notrunc

	openssl enc -bf-cbc -e -in pic_original.bmp -out pic_bf-cbc.bmp -K $(KVALUE) $(OPTIONS)
	head -c 54 pic_original.bmp | dd of=pic_bf-cbc.bmp bs=1 seek=0 count=54 conv=notrunc

	openssl enc -bf-ecb -e -in pic_original.bmp -out pic_bf-ecb.bmp -K $(KVALUE) $(OPTIONS)
	head -c 54 pic_original.bmp | dd of=pic_bf-ecb.bmp bs=1 seek=0 count=54 conv=notrunc

task3:
	openssl enc -aes-128-cbc -e -in plain.txt -out plain-aes-128-cbc.txt $(OPTIONS)
	printf '\x00' | dd of=plain-aes-128-cbc.txt bs=1 seek=29 count=1 conv=notrunc
	openssl enc -aes-128-cbc -d -in plain-aes-128-cbc.txt -out plain-aes-128-cbc-decrypted.txt $(OPTIONS)

	openssl enc -aes-128-cfb -e -in plain.txt -out plain-aes-128-cfb.txt $(OPTIONS)
	printf '\x00' | dd of=plain-aes-128-cfb.txt bs=1 seek=29 count=1 conv=notrunc
	openssl enc -aes-128-cfb -d -in plain-aes-128-cfb.txt -out plain-aes-128-cfb-decrypted.txt $(OPTIONS)

	openssl enc -aes-128-ecb -e -in plain.txt -out plain-aes-128-ecb.txt $(OPTIONS)
	printf '\x00' | dd of=plain-aes-128-ecb.txt bs=1 seek=29 count=1 conv=notrunc
	openssl enc -aes-128-ecb -d -in plain-aes-128-ecb.txt -out plain-aes-128-ecb-decrypted.txt $(OPTIONS)

	openssl enc -aes-128-ofb -e -in plain.txt -out plain-aes-128-ofb.txt $(OPTIONS)
	printf '\x00' | dd of=plain-aes-128-ofb.txt bs=1 seek=29 count=1 conv=notrunc
	openssl enc -aes-128-ofb -d -in plain-aes-128-ofb.txt -out plain-aes-128-ofb-decrypted.txt $(OPTIONS)

task4:
	openssl enc -aes-128-cbc -e -in plain20 -out plain20-aes-128-cbc.txt $(OPTIONS)
	openssl enc -aes-128-cbc -e -in plain24 -out plain24-aes-128-cbc.txt $(OPTIONS)
	openssl enc -aes-128-cbc -e -in plain25 -out plain25-aes-128-cbc.txt $(OPTIONS)
	openssl enc -aes-128-cbc -e -in plain32 -out plain32-aes-128-cbc.txt $(OPTIONS)
	hd plain20-aes-128-cbc.txt
	hd plain24-aes-128-cbc.txt
	hd plain25-aes-128-cbc.txt
	hd plain32-aes-128-cbc.txt

	openssl enc -bf-cbc -e -in plain20 -out plain20-bf-cbc.txt $(OPTIONS)
	openssl enc -bf-cbc -e -in plain24 -out plain24-bf-cbc.txt $(OPTIONS)
	hd plain20-bf-cbc.txt
	hd plain24-bf-cbc.txt

	openssl enc -bf-cfb -e -in plain20 -out plain20-bf-cfb.txt $(OPTIONS)
	openssl enc -bf-cfb -e -in plain24 -out plain24-bf-cfb.txt $(OPTIONS)
	hd plain20-bf-cfb.txt
	hd plain24-bf-cfb.txt

	openssl enc -bf-ecb -e -in plain20 -out plain20-bf-ecb.txt $(OPTIONS)
	openssl enc -bf-ecb -e -in plain24 -out plain24-bf-ecb.txt $(OPTIONS)
	hd plain20-bf-ecb.txt
	hd plain24-bf-ecb.txt

	openssl enc -bf-ofb -e -in plain20 -out plain20-bf-ofb.txt $(OPTIONS)
	openssl enc -bf-ofb -e -in plain24 -out plain24-bf-ofb.txt $(OPTIONS)
	hd plain20-bf-ofb.txt
	hd plain24-bf-ofb.txt

INC=/usr/include/
LIB=/usr/lib/i386-linux-gnu/
task5:
	gcc -I$(INC) -L$(LIB) -o sample_encrypt sample_encrypt.c -lssl -lcrypto
	echo "Some Crypto Text" > crypttext
	./sample_encrypt
	openssl aes-128-cbc -d -K 000102030405060708090A0B0C0D0E0F -iv 01020304050607080807060504030201 -in crypttext-e -out crypttext-d
	diff crypttext crypttext-d

clean:
	rm -f `ls *.bmp | grep -v pic_original.bmp`
	rm -f `ls *.txt | grep -v plain.txt`
	rm -f crypttext*
	rm -f sample_encrypt
