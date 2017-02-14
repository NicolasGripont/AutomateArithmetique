#VARIABLES

MAKEFILE = makefile
EXE = automateArithmetique.exe
COMP = g++
RM = rm
EDL = g++
ECHO = echo
INT = symbole.h nombre.h expression.h lexer.h automate.h state.h
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
SOS = backup
BACKUPFILE = backup.sh
RESSOURCES = 


#RULES

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<


main.o : automate.h automate.cpp $(MAKEFILE)
symbole.o : symbole.h $(MAKEFILE)
nombre.o : nombre.h symbole.h symbole.cpp $(MAKEFILE)
expression.o : expression.h symbole.h symbole.cpp $(MAKEFILE)
lexer.o : lexer.h nombre.h nombre.cpp expression.h expression.cpp symbole.h symbole.cpp $(MAKEFILE)
automate.o : automate.h lexer.h lexer.cpp state.h state.cpp nombre.h nombre.cpp expression.h expression.cpp symbole.h symbole.cpp $(MAKEFILE)
state.o : automate.h automate.cpp symbole.h symbole.cpp $(MAKEFILE)

$(CLEAN) :
	$(ECHO) "nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core main.o


$(SOS) : 
	./$(BACKUPFILE) $(MAKEFILE) $(INT) $(REAL) $(RESSOURCES) $(BACKUPFILE)

