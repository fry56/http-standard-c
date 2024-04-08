##
## EPITECH PROJECT, 2022
## make
## File description:
## desc
##

# Variables
CC = gcc
RM = rm -f

# Nom de l'exécutable
EXEC_NAME = http_standard_server

# Sources and objects
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
	\
	src/request/parse_request.c \

OBJ = $(SRC:.c=.o)

# Include directory
INCLUDE_DIR = include
CFLAGS = -Wextra -Wall -Werror -g -I$(INCLUDE_DIR)

# Default target
all: $(EXEC_NAME)

# Rule to make the executable
$(EXEC_NAME): $(OBJ)
	@echo "Linking $@"
	$(CC) -o $@ $(OBJ)
	@echo "Executable created: $(EXEC_NAME)"

# Generic rule for building objects
%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean objects and executable
clean:
	@echo "Cleaning objects and executable"
	$(RM) $(OBJ) $(EXEC_NAME)

# Full rebuild
re: fclean all

# Alias for clean (common convention)
fclean: clean

# Run the program
run: $(EXEC_NAME)
	@echo "Running the program:"
	./$(EXEC_NAME)

.PHONY: all clean fclean re run
