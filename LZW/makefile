LINK_TARGET = lzw.exe

OBJS = main.o

$(LINK_TARGET) : $(OUT_OBJS)
	g++ -o $@ $^
	
$%.o : %.cpp
	g++ -o $@ -c $<
	
clean :  
	rm -f $(OBJDIR)/*.o  $(BINDIR)/*.exe *.exe.stackdump
	
all : 
	$(LINK_TARGET) 
