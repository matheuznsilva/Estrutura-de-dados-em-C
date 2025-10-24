# List of source files
SRCS = library_1.c library_2.c
# List of header files
HDRS = library_1.h library_2.h

# Define the target executable
TARGET = executable_name

# Compilation flags
CFLAGS = -Wall -Wextra

# Build rule for the target executable
$(TARGET): $(SRCS:.c=.o)
	gcc $(CFLAGS) $^ -o $@

# Build rule for source files
%.o: %.c $(HDRS)
	gcc $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o $(TARGET)