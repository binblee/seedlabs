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

clean:
	rm `ls *.bmp | grep -v pic_original.bmp`
