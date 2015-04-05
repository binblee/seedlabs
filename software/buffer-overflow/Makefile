all: call_shellcode stack exploit

call_shellcode: call_shellcode.c
	gcc -z execstack -o call_shellcode call_shellcode.c

stack: stack.c
	sudo gcc -ggdb -o stack -z execstack -fno-stack-protector stack.c
	sudo chmod 4755 stack

exploit: exploit.c
	gcc -o exploit exploit.c
	./exploit

randomon:
	sudo sysctl -w kernel.randomize_va_space=2

randomoff:
	sudo sysctl -w kernel.randomize_va_space=0

clean:
	rm exploit
	rm -f stack
	rm badfile
	rm call_shellcode
