
# 42-Pipex

## Description

This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

## Rules

Your program will be executed as follows:
        
        ./pipex file1 cmd1 cmd2 file2
It must take 4 arguments:
    
* file1 and file2 are file names.
* cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:

        $> < file1 cmd1 | cmd2 > file2

**Allowed functions:**
   
* open
* close
* read
* write
* malloc
* free
* perror
* strerror
* access
* dup
* dup2,
* execve
* exit
* fork
* pipe
* unlink
* wait
* waitpid
* ft_printf and any equivalent YOU coded

## Output

## Instalation


```bash
  git clone https://github.com/affmde/42-pipex.git
  cd 42-pipex
  make
```
Then just run the executable with the commands you want

## Related projects

[42-fdf](https://github.com/affmde/fdf)
## Authors

- [@affmde](https://www.github.com/affmde) - Andre Miranda

