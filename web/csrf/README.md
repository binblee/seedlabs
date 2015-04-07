# CSRF

### Hands on instruction

Refer to this: [hands on instruction](http://www.cis.syr.edu/~wedu/seed/Labs/Web/CSRF_Collabtive/CSRF_Collabtive.pdf)
and [this video](http://www.cis.syr.edu/~wedu/education/websec3.html)

### Attacker solution

replace below file with index.html under attacker/

```bash
/var/www/CSRF/Attacker/index.html
```

### Counter measure solution

run make to generate patch files
```bash
make
```
copy csrf-fix.patch to /var/www/CSRF/Collabtive of VM.
run this command to apply patch and restart apache2
```bash
sudo patch -p1 < csrf-fix.patch
sudo service apache2 restart
```
