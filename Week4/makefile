LINK_TARGET = 1542201.exe
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include
LD_FLAGS = -O3
CC_FLAGS = -I$(INCDIR)

CPP_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES = $(addprefix $(OBJDIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

$(LINK_TARGET) : $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<
	
clean :  
	rm -f $(OBJDIR)/*  $(BINDIR)/* *.exe.stackdump
	
all : 
	$(LINK_TARGET) 