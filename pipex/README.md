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

File descriptor

In Unix type systems, a file descriptor (fd for short) is a small positive integer used as reference to an open file in a process. By default, each process systematically inherits three open file descriptors : 0	for Standard Input (STDIN_FILENO), 1 for Standard Output (STDOUT_FILENO), 2 for Standard Error (STDERR_FILENO - constant macros in <unistd.h>).

open

    Open files and create a new file descriptor for them.

    Include <fcntl.h> library.

    Prototype: int open(const char *pathname, int flags, mode_t mode);

        pathname: the path towards the file in the form of a string of characters.

        flags: an integer representing the flags indicating the access mode, we can combine flags with the bitwise | (OR) operator.
              O_RDONLY	Read only.
              O_WRONLY	Write only.
              O_RDWR	Read and write.
              O_TRUNC	Truncated mode. If the file exists and the access mode allows writing to it (O_WRONLY or O_RDWR), truncates its contents to 0 size when it is opened, with the effect of overwriting the file.
              O_APPEND	Append mode. The file offset is set to the end of the file at each write, with the effect of adding text to the end of the file instead of overwriting it.
              O_CREAT	Creates the file if it does not already exist. Its permissions must then be specified in open‘s mode parameter.

        mode: an integer representing the permissions to give to the file upon creation. This is an “optional” parameter that will be ignored if we don’t ask to create the file if it doesn’t already exist (to shorten this permissions specification is to directly use their added numeric values, preceded by a 0. For example 0777 as read/write/execute to all).
    
    close

        We use it to close an open file descriptor. 
        
        Include <unistd.h> library.

        Prototype: int close(int fd); fd is the file descriptor that you want to close. Upon success, the close function returns 0, but on failure, it returns -1. The close function only closes the file descriptor, it does not delete the file itself!

    unlink

        We use to remove a named file from the file system. It effectively deletes the file by removing its directory entry.

        Include <unistd.h> library.

        Prototype: int unlink(const char *pathname); The system call returns 0 on success or -1 on failure.
    
    write

        Write into the file descriptor.

        Include <unistd.h> library.

        Prototype: ssize_t write(int fd, const void *buf, size_t count);
            fd: the file descriptor to write to.

            buf: a pointer to a memory zone to write to the file, typically containing a string of characters.

            count: the number of bytes (i.e. characters) to write, typically the length of the string of characters specified in the previous parameter.

        On success, the write function returns the number of bytes it has written, However, upon failure, it returns -1.
    
    read

        Function loads the contents of a file into memory, in part or in full, using its file descriptor.

        Include <unistd.h> library.

        Prototype: ssize_t read(int fd, void *buf, size_t count);

            fd: the file descriptor to read from.

            buf: a pointer towards a memory area where we can temporarily store the read characters.

            count: a size in bytes to read, in other words, the number of characters to read. This size will often correlate with the size of the memory area indicated in the previous parameter.
        
        The read function returns the number of characters it has read, or -1 in case of error. When the read function reaches the end of the file, it will return 0.