NAME = main

CC = g++

SOURCE_PATH = srcs/
SOURCES = \
		data.cpp\
		interface.cpp\
		stock.cpp\
		user.cpp\
		main.cpp
SRCS = $(addprefix $(SOURCE_PATH), $(SOURCES))

INCLUDES = ./includes

all:
		$(CC) $(SRCS) -I $(INCLUDES) -o $(NAME)

clean:

fclean: clean

		rm -rf $(NAME)

re: fclean all