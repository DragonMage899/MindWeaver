**Directory brute forcing** is a technique used to systematically guess the names of directories and files on a web server in order to discover hidden or unprotected resources. This is typically done using automated tools that make numerous HTTP requests, testing different potential directory and file names from a predefined or dynamically generated list.

The goal is to uncover sensitive information, misconfigurations, or vulnerabilities that may be exploitable, aiding in penetration testing and security assessments.

Typically, web servers will return the following status codes (relevant to directory brute forcing) to a request:

- **404:** This indicates that the resource likely doesn't exist
- **403:** This code means that you don't have permission to access that specific file or directory
- **301:** Redirect code, the web server will redirect you to the requested content
- **200:** OK status code

The above are just a few of the many status codes returned by web servers, but are typically codes that one might look at when brute forcing directories as they give indicators about what files or directories may be present on the web server.


///
`gobuster dir -u 10.10.175.125/TASK5 -w /home/Dragon/Code/wordlists/SecLists/Discovery/Web-Content/directory-list-2.3-medium.txt -t 100`
