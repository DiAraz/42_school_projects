NAME = ircserv

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./inc
RM := rm -f
CDEPS = $(patsubst %, includes/%.hpp, Channel response Request Server User);

SRC = main.cpp	$(addprefix sources/, Server.cpp User.cpp Request.cpp Channel.cpp cmd_error_replies.cpp Bonus_Bot.cpp) \
				$(addprefix sources/commands/, ft_cap.cpp ft_nick.cpp ft_ping.cpp ft_pass.cpp \
				ft_user.cpp ft_quit.cpp ft_privmsg.cpp ft_notice.cpp \
				ft_oper.cpp ft_kill.cpp ft_globops.cpp ft_send.cpp ft_receive.cpp \
				ft_join.cpp ft_list.cpp ft_part.cpp ft_topic.cpp ft_who.cpp ft_mode.cpp ft_kick.cpp ft_invite.cpp ft_time.cpp ft_joke.cpp)

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(CDEPS)
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@rm -rf *.dmg

re: fclean all

run :
	@make
	./$(NAME) 6668 123

get_client:
	@echo "\033[0;32mDownloading and launching KVIrc client...\033[0m"
	@curl -o KVIrc-5.0.0.dmg ftp://ftp.kvirc.net/pub/kvirc/5.0.0/binary/macosx/KVIrc-5.0.0.dmg
	@open KVIrc-5.0.0.dmg
 
.PHONY: all clean fclean re run get_client
