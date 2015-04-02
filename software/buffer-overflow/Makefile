all: call_shellcode stack exploit setuidroot_sample

call_shellcode: call_shellcode.c
	gcc -z execstack -o call_shellcode call_shellcode.c

stack: stack.c
	sudo gcc -o stack -z execstack -fno-stack-protector stack.c
	sudo chmod 4755 stack

exploit: exploit.c
	gcc -o exploit exploit.c

setuidroot_sample: setuidroot_sample.c
	sudo gcc -o setuidroot_sample setuidroot_sample.c
	sudo chmod 4755 setuidroot_sample
