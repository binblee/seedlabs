all: retlib exploit showsh foobar.s

retlib: retlib.c
	gcc -fno-stack-protector -z noexecstack -S retlib.c
	sudo gcc -fno-stack-protector -z noexecstack -o retlib retlib.c
	sudo chmod 4755 retlib

exploit: exploit.c
	gcc -o exploit exploit.c
	./exploit

showsh: showshellenv.c
	gcc -o showsh showshellenv.c

foobar.s: foobar.c
	gcc -fno-stack-protector -S foobar.c

randomon:
	sudo sysctl -w kernel.randomize_va_space=2

randomoff:
	sudo sysctl -w kernel.randomize_va_space=0

clean:
	rm -f retlib
	rm badfile
	rm showsh
	rm *.s
