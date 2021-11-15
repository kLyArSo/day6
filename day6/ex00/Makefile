SRCS =	main.cpp
NAME = convert
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(SRCS)
	clang++ $(FLAGS) $(SRCS) -o $(NAME);

clean : 
	rm -Rf $(NAME)

fclean : clean

re: fclean all