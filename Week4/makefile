LINK_TARGET = 1542201.exe
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include

OBJS = SEdge.o SNode.o Queue.o SingleLinkedList.o AdjacencyList.o AdjacencyGraph.o Graph.o Prim.o Kruskal.o SpanningTree.o main.o

OUT_OBJS = $(addprefix $(OBJDIR)/,$(OBJS))

$(LINK_TARGET) : $(OUT_OBJS)
	g++ -o $(BINDIR)/$@ $^
	
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -I$(INCDIR) -o $@ -c $<
	
clean :  
	rm -f $(OBJDIR)/*.o  $(BINDIR)/*.exe *.exe.stackdump
	
all : 
	$(LINK_TARGET) 