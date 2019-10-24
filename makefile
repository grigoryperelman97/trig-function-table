NAME = trigFunctionTable
OBJECTS = trigFunctionTable.c

program: $(OBJECTS)
	gcc $(OBJECTS) -o $(NAME) -lm -Wall

run prorgam:
	./$(NAME)
	rm $(NAME)