

SRCPATH := ./stack/src
INCPATH := ./stack/include
SRC_FILES := $(wildcard ./stack/src/*.c)
OBJ_FILES := $(patsubst %.c,%.o,$(SRC_FILES))
DEFINES := 


TARGET= examples
CFLAGS = -fdiagnostics-color=always -g -I$(INCPATH) 

$(TARGET):main.c $(OBJ_FILES)
	-rm -f $@
	gcc  $(CFLAGS) -o $(TARGET) main.c $(OBJ_FILES) -lm

%.o:$(SRCPATH)%.c
	gcc -c $(CFLAGS) -o $@ $<

.PHONY:clean

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

