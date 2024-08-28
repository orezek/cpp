# Compiler and flags
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
INCLUDES    = -I.

# Directories
SRCDIR      = .
OBJDIR      = ./obj

# Target executable
TARGET      = megaphone

# Source and object files
SOURCES     = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS     = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Default target
all: $(OBJDIR) $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory if it does not exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean object files and executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
