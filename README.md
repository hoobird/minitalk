# Minitalk

This project involves creating a small data exchange program using UNIX signals. 
<br> It consists of two main programs: `client` and `server`.

## Getting Started

To compile the project, use the provided Makefile:

```bash
make all
```

This will generate the `client` and `server` executables.

## Usage

### Server

The server must be started first. It prints its PID upon launch and waits for incoming signals from clients.

```bash
./server
```

### Client

The client sends a string to the server by providing the server's PID and the string as command-line arguments.

```bash
./client [server_pid] [message]
```

## Implementation Details

### Client (`client.c`)

- The client program sends signals to the server using `kill` with either `SIGUSR1` or `SIGUSR2`.
- It handles errors gracefully and ensures proper parameter usage.
- The message to be sent is converted into bits and sent one by one.

### Server (`server.c`)

- The server program listens for signals from clients using `sigaction` to handle `SIGUSR1` and `SIGUSR2`.
- It reconstructs the message from the received signals and prints it to the standard output.
- The server acknowledges each signal received from the client.

## ~~Bonus Features~~

- ~~The server acknowledges every message received by sending back a signal to the client.~~
- ~~Unicode characters support.~~
