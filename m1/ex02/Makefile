# Compiler and flags
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
INCLUDES    = -I.

# Directories
SRCDIR      = .
OBJDIR      = ./obj
BINDIR      = ./bin

# Target executable
TARGET      = $(BINDIR)/exec

# Source and object files
SOURCES     = $(SRCDIR)/main.cpp
OBJECTS     = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Default target
all: $(BINDIR) $(OBJDIR) $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create bin directory if it does not exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Create obj directory if it does not exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean object files and executable
fclean: clean
	rm -rf $(BINDIR)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
