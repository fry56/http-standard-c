##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

CC = gcc
RM = rm -f

EXEC_NAME = http_standard_server

SRC = \
	src/main.c \
	\
	src/router/free_router.c \
	src/router/handle_route.c \
	src/router/add_route.c \
	src/router/init_router.c \
	src/router/find_route.c \
	\
	src/server/create_server.c \
	src/server/accept_connection.c \
	src/server/handle_client.c \
	src/server/start_server.c \
	src/server/handle_request.c \
	\
	src/response/send_response.c \
	src/response/add_header_response.c \
	\
	src/request/parse_request.c \
	src/request/find_param.c \

OBJ = $(SRC:.c=.o)

INCLUDE_DIR = include
CFLAGS = -Wextra -Wall -Werror -g -I$(INCLUDE_DIR)

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ)
	@echo "Linking $@"
	$(CC) -o $@ $(OBJ)
	@echo "Executable created: $(EXEC_NAME)"

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning objects and executable"
	$(RM) $(OBJ) $(EXEC_NAME)

re: fclean all

fclean: clean

run: $(EXEC_NAME)
	@echo "Running the program:"
	./$(EXEC_NAME)

.PHONY: all clean fclean re run
