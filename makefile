NAME = trigFunctionTable
OBJECTS = trigFunctionTable.c

program: $(OBJECTS)
	gcc $(OBJECTS) -o $(NAME) -lm
	./$(NAME)
	rm $(NAME)