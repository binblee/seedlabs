all: task1 task2 task3 task4-sample

task1:
	printf "Text to be to one way hashed." > text-to-be-hashed.txt
	openssl dgst -md5 text-to-be-hashed.txt
	openssl dgst -sha1 text-to-be-hashed.txt
	openssl dgst -sha256 text-to-be-hashed.txt

task2:
	printf "Text to be to one way hashed." > text-to-be-hashed.txt
	openssl dgst -md5 -hmac "hmacpassword0000" text-to-be-hashed.txt
	openssl dgst -md5 -hmac "1" text-to-be-hashed.txt
	openssl dgst -sha1 -hmac "hmacpassword0000" text-to-be-hashed.txt
	openssl dgst -sha1 -hmac "1" text-to-be-hashed.txt
	openssl dgst -sha256 -hmac "hmacpassword0000" text-to-be-hashed.txt
	openssl dgst -sha256 -hmac "1" text-to-be-hashed.txt

task3:
	printf "text 123" > text-to-be-hashed-1.txt
	printf "text 133" > text-to-be-hashed-2.txt
	openssl dgst -md5 text-to-be-hashed-1.txt
	openssl dgst -md5 text-to-be-hashed-2.txt
	openssl dgst -sha256 text-to-be-hashed-1.txt
	openssl dgst -sha256 text-to-be-hashed-2.txt

task4-sample:
	gcc -o hash_sample hash_sample.c -lcrypto
	./hash_sample md5
	./hash_sample sha1
	./hash_sample sha256

task4:
	gcc -std=c99 -o hash_test hash_test.c -lcrypto
	./hash_test

clean:
	rm -f *.txt
	rm -f hash_sample
