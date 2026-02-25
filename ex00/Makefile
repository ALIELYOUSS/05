FILES = main.cpp Bureaucrat.cpp 

OBJS = $(FILES:.cpp=.o)

CC = c++

NAME = Bureaucrat

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPP_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all