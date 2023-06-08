<div align="center">

# 42 - Pipex

<img alt="mac" src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white"/>
<img alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>
<img alt="Ubuntu" src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/>
<br>
<img alt="c" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
<br>
<img alt="size" src="https://img.shields.io/github/languages/code-size/affmde/42-pipex"/>
<img alt="total files" src="https://img.shields.io/github/directory-file-count/affmde/42-pipex"/>
<img alt="repo size" src="https://img.shields.io/github/repo-size/affmde/42-pipex"/>
<img alt="commits per month" src="https://img.shields.io/github/commit-activity/m/affmde/42-pipex"/>
</div>

---

## ![description icon](https://cdn-icons-png.flaticon.com/32/2644/2644332.png) Description

This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

## ![rules icon](https://cdn-icons-png.flaticon.com/32/3251/3251383.png) Rules

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


## ![install icon](https://cdn-icons-png.flaticon.com/32/427/427132.png) Install and run

```bash
  $git clone https://github.com/affmde/42-pipex.git
  $cd 42-pipex
  $make
 $ ./pipex (infile)(cmd1)(cmd2)(outfile)
```
Replace infile with the file from where you get the input. cmd1 and cmd2 with the respoctive commands you want to execute. Outfile with the file where you want to redirect the data

## ![relate icon](https://cdn-icons-png.flaticon.com/32/2875/2875800.png) Related projects

 - [42-fdf](https://github.com/affmde/fdf)


