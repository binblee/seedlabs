test_setuid:	test_setuid.c
	gcc -o test_setuid test_setuid.c
	sudo setcap cap_setuid=ep ./test_setuid

clean:
	rm -f test_setuid
