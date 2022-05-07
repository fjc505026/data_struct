TARGET= leetcode
C_FILES = $(shell ls *.c)  #get all .c file in current DIR
BASE = $(basename $(C_FILES))  #get file name without .c
OBJS = $(addsuffix .o, $(addprefix obj/,$(BASE))) #covert to obj/*.o, all object file put in obj/ 


$(TARGET):$(OBJS)
	-rm -f $@
	gcc -o $(TARGET) $(OBJS)

obj/%.o:%.c
	@if test ! -d"obj"; then mkdir -p obj; fi;
	gcc -c -g -o $@ $<

clean:
	-rm -f $(TARGET)
	-rm -f obj/*.o
