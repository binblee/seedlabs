# Buffer Overflow Lab

### Initial setup (2.1)

Run sysctl to disable OS address space randomization

```bash
disable-os-security.sh
```

check if it is disabled

```bash
sysctl kernel.randomize_va_space
```

or

```bash
cat /proc/sys/kernel/randomize_va_space
```
### Task1 (2.4)

Makefile created for call_shellcode.c, exploit.c and stack.c

```bash
make
```
Run stack I got shell prompt '$'

```bash
$ ./stack
$ id
uid=0(root) gid=0(root) euid=1000(seed) groups=1000(seed),0(root)
```
Previously, it was:
```bash
uid=0(root) gid=0(root) groups=0(root)
```
