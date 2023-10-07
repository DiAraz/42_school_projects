Good to remember:

The child process and the parent process both continue to execute from the point of the fork call.

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
