NAME = trigFunctionTable
OBJECTS = trigFunctionTable.c

program: $(OBJECTS)
	gcc $(OBJECTS) -o $(NAME) -lm

run prorgam:
	./$(NAME)
	rm $(NAME)