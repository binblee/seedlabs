all: call_shellcode stack exploit

call_shellcode: call_shellcode.c
	gcc -z execstack -o call_shellcode call_shellcode.c

stack: stack.c
	sudo gcc -o stack -z execstack -fno-stack-protector stack.c
	sudo chmod 4755 stack

exploit: exploit.c
	gcc -o exploit exploit.c

clean:
	rm exploit
	rm -f stack
	rm call_shellcode
