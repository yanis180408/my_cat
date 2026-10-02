# Welcome to My Cat
***

## Task
The goal of this project is to reimplement the standard `cat` command line utility in C.
The program takes one or more files as arguments and writes their contents to the standard output, one after the other.
The challenge lies in reading files of any size with low-level system calls, handling files that can't be opened, and managing resources properly, while only using the allowed functions of the subject.

## Description
I solved this problem by reading each file in fixed-size chunks and writing them out as they are read:
- **File Handling** : each argument is opened with `open`, read with `read` into a fixed-size buffer, and closed with `close` once the end of the file is reached.
- **Chunked Reading** : the file is processed block by block, so files of any size are supported without loading them entirely into memory.
- **Output** : every chunk is written to the standard output with `write`, using the exact number of bytes returned by `read`.
- **Multiple Files** : the arguments are processed in order, so the contents are concatenated in the order given.
- **Error Handling** : if a file can't be opened or read, an error message is written to `stderr` and the program moves on to the next file.
- **Resource Safety** : every file descriptor opened is closed, even when a read fails.

## Installation
The project includes a Makefile for easy compilation.
1. Compile the project :
```bash
make
```

2. Recompile (clean and build) :
```bash
make re
```

3. Clean object files :
```bash
make clean
```

4. Clean everything (executable and objects) :
```bash
make fclean
```

## Usage
The program takes one or more file names as arguments and displays their contents.

**Syntax :**
```bash
./my_cat [FILE...]
```

**Examples :**

Display a single file:
```
$>cat hello.txt
Hello, world!
$>./my_cat hello.txt
Hello, world!
$>
```

Concatenate several files:
```
$>./my_cat file1.txt file2.txt
(contents of file1.txt)
(contents of file2.txt)
$>
```

Handle a file that doesn't exist:
```
$>./my_cat missing.txt
my_cat: missing.txt: No such file or directory
$>
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>