# Compiler and flags
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
INCLUDES    = -I.

# Directories
SRCDIR      = .
OBJDIR      = ./obj
BINDIR      = ./bin

# Target executable
TARGET      = $(BINDIR)/triangle

# Source and object files
SOURCES     = $(SRCDIR)/main.cpp \
              $(SRCDIR)/Fixed.cpp \
              $(SRCDIR)/BSP.cpp \
              $(SRCDIR)/Point.cpp

OBJECTS     = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Default target
all: $(BINDIR) $(OBJDIR) $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Ensure bin directory exists
$(BINDIR):
	mkdir -p $(BINDIR)

# Ensure obj directory exists
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
