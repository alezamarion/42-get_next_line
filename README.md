# Get_next_line42
The aim of this project is to code a function that returns a line ending with a newline, read from a file descriptor.<br/>
## Use:

🚧 project:<br/>
```
42Libft $ make
```
:shower: Clean Obj files:<br/>
```
42Libft $ make clean
```
:shower: :shower: Clean All (obj files + binary):<br/>
```
42Libft $ make fclean
```
:shower: :shower: 🚧 Clean All + build:<br/>
```
42Libft $ make re
```

<br/>See Makefile<br/>

<h2><b>Main Idea</b></h2>

Here, a simple drawning about the main idea: copy buffer until find a '\n', keeping the residual for the next call.

![gnl_idea](imgs/gnl_idea.png)
