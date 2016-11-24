LINK_TARGET = lzw.exe
OBJDIR = obj
BINDIR = bin

OBJS = main.o

OUT_OBJS = $(addprefix $(OBJDIR)/,$(OBJS))

# REBUILDABLES = $(OUT_OBJS) $(BINDIR)/$(LINK_TARGET)

$(LINK_TARGET) : $(OUT_OBJS)
	g++ -o $(BINDIR)/$@ $^
	
$(OBJDIR)/%.o : src/%.cpp
	g++ -Iinclude -o $@ -c $<
	
clean :  
	rm -f $(OBJDIR)/*.o  $(BINDIR)/*.exe *.exe.stackdump
	
all : 
	$(LINK_TARGET) 
