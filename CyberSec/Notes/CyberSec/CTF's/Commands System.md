o
## general

#### Random stuff
**Command substitution**
$ can be used to concatenate output of a function
	e$(echo cho) test
	will resolve to `echo test`

seq 
- seq 1 3 10
- prints:
	- 1
	- 4
	- 7
	- 10
- Can be used with | for automated testing.
Loops
![[Pasted image 20250720125640.png]]
![[Pasted image 20250720125725.png]]




### less
xk
- jump forwards x lines forward
g
- beg
G
- end
/x
- Search for string x

## grep 

#### Basic Usage
grep "pattern" file               # Search for exact pattern
grep -i "pattern" file            # Case-insensitive search
grep -r "pattern" dir/            # Recursive search in directory
grep -n "pattern" file            # Show line numbers
grep -v "pattern" file            # Invert match (lines NOT matching)

#### Regex & Extended Patterns
grep -E "patt1|patt2" file        # OR with extended regex
grep -E "^start" file             # Lines that start with 'start'
grep -E "end$" file               # Lines that end with 'end'
grep -E "[0-9]{4,}" file          # Numbers with 4+ digits

#### File Searching Tricks
grep -r "flag" . 2>/dev/null      # Recursively find "flag", suppress errors
grep -ri "password" .             # Case-insensitive recursive search
grep -a "flag{" binary            # Search strings in binary file
strings binary | grep "flag"      # Extract printable strings then grep
grep -r --include="*.php" "key" . # Search only .php files

#### Match Context
grep -A 2 "flag" file             # Show 2 lines *after* match
grep -B 2 "flag" file             # Show 2 lines *before* match
grep -C 2 "flag" file             # Show 2 lines before & after

#### Count Matches
grep -c "flag" file               # Count matches per file
grep -ro "flag" . | wc -l         # Total matches recursively (one per line)

#### Show Matching Part Only
grep -oE "flag\{[^\}]+\}" file    # Extract full flag pattern like flag{...}

#### Search all file rec
grep -rE "your_regex_pattern" .

## Find Command Cheat Sheet for CTFs

####  Basic Usage
find . -name "filename"                # Find file by name (exact match)
find . -iname "filename"              # Case-insensitive name match
find /path -type f -name "*.txt"      # Find all .txt files in path
find . -type d -name "dir*"           # Find directories starting with "dir"

####  File Properties
find . -size +10M                     # Files larger than 10MB
find . -size -100k                    # Files smaller than 100KB
find . -empty                         # Find empty files or directories
find . -type f -perm 777              # Find files with 777 permissions

####  By Time
find . -mmin -10                      # Modified in last 10 minutes
find . -mtime -1                      # Modified in last 1 day
find . -atime +5                      # Accessed more than 5 days ago

####  Execute Commands
find . -name "*.sh" -exec chmod +x {} \;   # Make all .sh files executable
find . -name "*.zip" -exec unzip {} \;     # Unzip all .zip files found
find . -type f -exec grep "flag" {} \;     # Search "flag" in all files

# ### Combine Conditions
find . \( -name "*.php" -o -name "*.html" \)  # Find .php or .html files
find . -type f -size +1M -name "*.log"        # Large .log files

####  Output Tricks
find . -type f > filelist.txt            # Save file list to a file
find . -type f -print0 | xargs -0 grep "flag"  # Grep safely across filenames with spaces

####  Special CTF Tips
find / -name "flag*" 2>/dev/null         # Search for flag files (ignore errors)
find . -type f -exec strings {} \; | grep "flag{"   # Search flag in strings of all files


# zip
```
zip --encrypt -r my_protected_info.zip my_info/
```


### gdb
`gcc -o -g a a.c`
`gdb -q ./a`
Can now view source code with list x in gdb (start at list 1)

int a
`x/axw &var` view a next bytes from location of var

### Perl
Run a system command
`perl -e 'system("echo hi")'`

`perl -e 'print "A" x 20;'`
`perl -e 'print "0x41" x 20;'`
Both print 'A' 20 times

outputting a the result and concatenating the result tot a shell command.
`una$(perl -e 'print "m";')e`
$(perl -e 'print "m";') returns m
so final result is `uname`



The output of the 

