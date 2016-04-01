LINK_TARGET = 1542201.exe
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include

OBJS =  SNode.o Stack.o Queue.o Search.o BFS.o DFS.o AdjacencyGraph.o AdjacencyMatrix.o Graph.o main.o

OUT_OBJS = $(addprefix $(OBJDIR)/,$(OBJS))

$(LINK_TARGET) : $(OUT_OBJS)
	g++ -o $(BINDIR)/$@ $^
	
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -I$(INCDIR) -o $@ -c $<
	
clean :  
	rm -f $(OBJDIR)/*.o  $(BINDIR)/*.exe *.exe.stackdump
	
all : 
	$(LINK_TARGET) 