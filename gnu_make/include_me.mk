.PHONY = clean 

SRC =  $(shell find -iname "*.c")
OBJ_FILE = $(patsubst %.c, %.o, $(SRC))
OBJ := $(SRC: %.c = %.o)
GCC_HDR = -I ./include/
HDR_FILES = $(shell find -iname "*.h" -exec dirname {} \; | sed 's/^./-I./g' | xargs echo)

$(info $(SRC) $(OBJ_FILE) $(HDR_FILES))




#MACROS 
define echo_macro 
echo "HI"
echo "WELCOME TO ZOOTOPIA"
endef