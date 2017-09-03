This project consists in the development of a Compiler for the Ja language (a subset of the Java language, version 8).

It has a lexical analyser, a syntax analyser, a semantic analyser and an intermediate code generator.

All the instructions can be found at the PDF file (Portuguese version only, unfortunately attached to the repo.
There is also a run.sh file to compile the project.
When running in, the following flags can be passed:

-1: performs the lexical analysis, reporting possible lexical errors, and ends.

-l: performs the lexical analysis, reporting tokens found and possible lexical errors, and
ends.

-2: performs the parsing, reporting any lexical or syntactic errors, and terminates.

-t: performs the parsing, reporting any lexical or syntactic errors, prints the syntax tree built during the parsing of the program (if there are no syntactic errors), and ends.

-3: executes the semantic analysis (if there are no syntactic errors), reporting any lexical or semantic erros, and ends. If there are syntactic errors the behavior is identical to the flag -2.

-s: executes the semantic analysis (if there are no syntactic errors), reporting any lexical or semantic errors, prints the contents of the symbol table (s) and the abstract syntax tree annotated, and ends. If there are syntactic errors the behavior is identical to the flag -2.
