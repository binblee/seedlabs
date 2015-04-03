# Buffer Overflow Lab

### Documents
[Smashing the Stack](http://cecs.wright.edu/people/faculty/tkprasad/courses/cs781/alephOne.html)

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
./stack
$
```
