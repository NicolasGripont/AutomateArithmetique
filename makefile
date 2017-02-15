#VARIABLES

MAKEFILE = makefile
EXE = automateArithmetique.exe
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = symbol.h number.h expression.h numberexpression.h binaryexpression.h multiplybinaryexpression.h plusbinaryexpression.h lexer.h automate.h state.h
REAL = $(INT:.h=.cpp) main.cpp
OBJ = $(INT:.h=.o) main.o
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -std=c++11 -Wall -O3
EDLFLAGS = 
LIBS = 
LIBPATH =# -L
INCPATH =# -I
CLEAN = clean
RESSOURCES = 


#RULES

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<


main.o : automate.h automate.cpp $(MAKEFILE)
symbol.o : symbol.h $(MAKEFILE)
number.o : number.h symbol.h symbol.cpp $(MAKEFILE)
expression.o : expression.h symbol.h symbol.cpp $(MAKEFILE)
numberexpression.o : numberexpression.h expression.h expression.cpp symbol.h symbol.cpp $(MAKEFILE)
binaryexpression.o : binaryexpression.h expression.h expression.cpp symbol.h symbol.cpp $(MAKEFILE)
multiplybinaryexpression.o : multiplybinaryexpression.h binaryexpression.h binaryexpression.cpp expression.h expression.cpp symbol.h symbol.cpp $(MAKEFILE)
plusbinaryexpression.o : plusbinaryexpression.h binaryexpression.h binaryexpression.cpp expression.h expression.cpp symbol.h symbol.cpp $(MAKEFILE)
lexer.o : lexer.h expression.h expression.cpp symbol.h symbol.cpp number.h number.cpp $(MAKEFILE)
automate.o : automate.h lexer.h lexer.cpp state.h state.cpp expression.h expression.cpp symbol.h symbol.cpp number.h number.cpp $(MAKEFILE)
state.o : automate.h automate.cpp symbol.h symbol.cpp $(MAKEFILE)

$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core main.o

