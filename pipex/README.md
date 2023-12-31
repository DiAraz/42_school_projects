# pipex

<p align="center">
  <img src="https://github.com/DiAraz/DiAraz/blob/main/42_badges/pipexe.png" />
</p>

Pipex is a small command-line program that emulates the functionality of the shell's pipe feature. It reads input from a file, runs two commands as separate child processes, and then sends the output of the first command as input to the second command. The output is then written to another file. Pipex is implemented using the C programming language and various system calls, such as fork, pipe, dup2, and execve.

The result is virtually identical to this kind of shell command:
```
$ < input_file command1 | command2 > output file
```

## Usage
Git clone the repository and cd into it. To compile, use ```make```.

Then run the following command:

```
./pipex file1 cmd1 cmd2 file2
```
The output will be written to the specified output file. If the output file exists, it will be overwritten.
Each command can be given arguments and options if surrounded by quotation marks. For example:
```
./pipex input_file "cat -e" "grep pipex" output_file
```