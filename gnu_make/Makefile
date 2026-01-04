include include_me.mk


all: main
	@

main : $(OBJ_FILE)
	$(echo_macro)
	gcc $^ -o $@

$(OBJ_FILE) : $(SRC)
	gcc $(HDR_FILES) -c $^

run: main
	./main

clean: 
	rm -f main 
	rm -f *.o
