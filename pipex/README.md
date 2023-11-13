Usage

Regular pipex execution

Pipex can handle 2 or more commands. To execute:

$ ./pipex input_file command1 command2 output_file

The output will be written to the specified output file. If the output file exists, it will be overwritten. This replicates the shell command:

$ < input_file command1 | command2 > output_file

Each command can be given arguments and options if surrounded by quotation marks. For example:

$ ./pipex example.txt "cat -e" "grep x" outfile.txt


Good to remember:

The child process and the parent process both continue to execute from the point of the fork call.
Child process has pid 0. To work in parent process we use pid !=0.
The function execve replaces the current process, should be called in child process.


New functions to learn:

pipe

    The pipe is used for interprocess communication. The pipe function creates a pair of file descriptors, where one descriptor is for writing (to send data) and the other is for reading (to receive data).

    Include <unistd.h> library.

    Prototype: int pipe(int pipefd[2]);  where pipefd[0] represents the file descriptor for reading from the pipe, and pipefd[1] represents the file descriptor for writing to the pipe. On success, zero is returned.

fork

    Creates a new process by duplicating the existing process. The new process is called the child process, and the existing process is called the parent process.

    Include <unistd.h> library.

    Prototype: pid_t fork(void); pid_t is a data type representing process IDs used for process identification. Returns PID for parent, 0 for child and -1 for error.

wait/waitpid

    Use to suspend the parent process’ execution until the child process’ state changes.

    Include <sys/wait.h> library.

    Prototype: pid_t wait(int *status);
               pid_t waitpid(pid_t pid, int *status, int options); Handles better if we hae several children. 

                status: a pointer to an integer type variable in which wait and waitpid can store the child’s exit status. If you're not interested in the child's exit status, you can pass NULL for this argument.

                pid: the PID of the child process we should wait for.

                options: A set of flags that control the behavior of the waitpid function. Common options include WNOHANG (return immediately if no child has terminated) and WUNTRACED (report stopped child processes).

execve

    Use to replace the current process image with a new one specified by the path to the executable file. This allows a process to execute a different program.

    Include <unistd.h> library.

    Prototype: int execve(const char *pathname, char *const argv[], char *const envp[]);

                pathname: The path to the binary executable file to be executed.

                argv: An array of strings representing the arguments passed to the new program. The first element (argv[0]) is conventionally the name of the program itself, and the last element must be NULL to terminate the argument list.

                envp: An array of strings representing the environment variables to be set for the new program. Like argv, this array must also be terminated with a NULL pointer.