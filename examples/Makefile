

SRC_FILES := $(wildcard ./list/src/*.c)
OBJ_FILES := $(patsubst %.c,%.o,$(SRC_FILES))
SRCPATH := ./list/src
INCPATH := ./list/include
DEFINES := 


TARGET= examples
CFLAGS = -fdiagnostics-color=always -g -I$(INCPATH)

$(TARGET):main.c $(OBJ_FILES)
	-rm -f $@
	gcc  $(CFLAGS) -o $(TARGET) main.c $(OBJ_FILES) 

%.o:$(SRCPATH)%.c
	gcc -c $(CFLAGS) -o $@ $<

.PHONY:clean

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

