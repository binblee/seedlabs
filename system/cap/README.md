# Linux Capability Exploration Lab

### Task 1

cap_dac_read_search

```c
/* Overrides all DAC restrictions regarding read and search on files
   and directories, including ACL restrictions if [_POSIX_ACL] is
   defined. Excluding DAC access covered by CAP_LINUX_IMMUTABLE. */

#define CAP_DAC_READ_SEARCH  2
```

```bash
sudo setcap cap_dac_read_search=ep /bin/ls
ls /root
```

cap_dac_override

```c
/* Override all DAC access, including ACL execute access if
   [_POSIX_ACL] is defined. Excluding DAC access covered by
   CAP_LINUX_IMMUTABLE. */

#define CAP_DAC_OVERRIDE     1
```

cap_chown
```c
/* In a system with the [_POSIX_CHOWN_RESTRICTED] option defined, this
   overrides the restriction of changing file ownership and group
   ownership. */

#define CAP_CHOWN            0
```

```bash
seed@ubuntu:~$ sudo setcap cap_chown,cap_dac_override=ep /bin/chown
seed@ubuntu:~$ getcap /bin/chown
/bin/chown = cap_chown,cap_dac_override+ep
seed@ubuntu:~$ chown seed:seed /root/hello
seed@ubuntu:~$ ls /root/hello -l
-rw-r--r-- 1 seed seed 0 Apr 25 00:53 /root/hello
seed@ubuntu:~$
```

cap_setuid
```c
/* Allows set*uid(2) manipulation (including fsuid). */
/* Allows forged pids on socket credentials passing. */

#define CAP_SETUID           7
```
```bash
seed@ubuntu:~$ make test_setuid
seed@ubuntu:~$ ./test_setuid
#id
(should be root)
```

cap_kill
```c
/* Overrides the restriction that the real or effective user ID of a
   process sending a signal must match the real or effective user ID
   of the process receiving the signal. */

#define CAP_KILL             5
```
```bash
seed@ubuntu:~$ sudo setcap cap_kill=ep /bin/kill
seed@ubuntu:~$ /bin/kill -9 <process id owned by root>
```

cap_net_raw
```c
/* Allow use of RAW sockets */
/* Allow use of PACKET sockets */
/* Allow binding to any address for transparent proxying (also via NET_ADMIN) */

#define CAP_NET_RAW          13
```
### Task 2
skip
