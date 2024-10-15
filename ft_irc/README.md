# ft_irc

<p align="center">
  <img src="https://github.com/DiAraz/DiAraz/blob/main/42_badges/ft_irce.png"/>
</p>

A small Internet Relay Chat (IRC) server made in C++.

---

## Usage

Clone this repository and `cd` into it. To build, use `make`.

To launch the server:

```
./ircserv <port> <password>
```

### Connecting to the Server Using KVIRC

This project was developed for the KVIRC client. After launching `kvirc`, set server as localhost, then in Advance settings
set port the same as you choose for your server. Then use following commands:

```
/PASS <server_password>
/USER <user> <mode(unused)> <host(unused)> <realname>
/NICK <nickname>
```

### Connecting to the Server Using NetCat

Alternatively, connect to the server using `nc`.

```
nc -C localhost <server_port>
```

Then, you can input your IRC commands. To properly register on the server, use the following commands:

```
PASS <server_password>
USER <user> <mode(unused)> <host(unused)> <realname>
NICK <nickname>
```

## Implemented Commands

- `INVITE <nickname> <channel_name>`: Invites a user to a channel.
- `JOIN <channel_name>`: Joins an existing channel or creates one. If `0` is specified as the channel name, removes the user from all channels.
- `KICK <nickname> <channel_name>`: Kicks a user from a channel (this is a channel operator command)
- `LIST`: Lists all channels on the server.
- `MODE <channel_name> <mode(s)>`: Sets/removes channel modes. Implemented channel modes:
    - `i`: set/remove invite-only mode.
    - `k`: set/remove the channel key (password)
    - `l`: set/remove a channel's user limit
    - `o`: give/take channel operator privileges
    - `t`: set/remove the restrictions of the TOPIC command to channel operators
- `NAMES`: lists all of the nicknames on the server.
- `NICK <nickname>`: sets the user's nickname.
- `PART <channel_name> <message>`: removes user from channel(s) and notifies the other users in the channel.
- `PASS <password>`: Used for registration to the server. The client must supply the server password as part of the registration process.
- `PRIVMSG <nickname_or_channel_name> <message>`: sends a message to the specified user or channel.
- `QUIT <message>`: Removes the user from the server and notifies other users in the channels the quitting user was in.
- `TOPIC <channel_name> <message>`: sets message as the channel topic.
- `USER <user> <mode(unused)> <host(unused)> <realname>`: sets a new user's information during registration.