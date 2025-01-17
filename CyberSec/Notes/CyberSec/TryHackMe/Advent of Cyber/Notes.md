# **Day 5**
- XXE
	- XML external entity injection (also known as XXE) is a web security vulnerability that allows an attacker to interfere with an application's processing of XML data. It often allows an attacker to view files on the application server filesystem, and to interact with any back-end or external systems that the application itself can access.

![[Pasted image 20250106115452.png]]
Server responded with it's own /etc/hosts file

in wishlist.php:
```javascript
libxml_disable_entity_loader(false);
$wishlist = simplexml_load_string($xml_data, "SimpleXMLElement", LIBXML_NOENT);
```

"`libxml_disable_entity_loader(false)`"
Allows users to load external entities
i.e) External file references or Request remote servers 
`simplexml_load_string` with the `LIBXML_NOENT` option, the web app resolves external entities
allowing attackers access to sensitive files or allowing them to make unintended requests from the server.

Fix:
- **Disable External Entity Loading**: The primary fix is to disable external entity loading in your XML parser. In PHP, for example, you can prevent XXE by setting `libxml_disable_entity_loader(true)` before processing the XML.
- **Validate and Sanitise User Input**: Always validate and sanitise the XML input received from users. This ensures that only expected data is processed, reducing the risk of malicious content being included in the request. For example, remove suspicious keywords like `/etc/host`, `/etc/passwd`, etc, from the request.