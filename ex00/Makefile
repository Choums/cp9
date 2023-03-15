NAME    = btc

# directories
SRCDIR        =    ./srcs
INCDIR        =    ./includes
OBJDIR        =    ./obj

# src / obj files
SRC        =	main.cpp

OBJ        	= $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
# nommage automatique des fichiers de dependance d'apres les noms des sources C
SDEP		= $(addprefix $(OBJDIR)/,$(SRC:.cpp=.d))

# ensemble des fichiers de dependance
DEP			= $(SDEP)

# compiler
CC        = c++
CFLAGS    = -Wall -Wextra -Werror -std=c++98 -g3 -MMD -fsanitize=address


all:			obj $(NAME)

obj:	
				mkdir -p $(OBJDIR)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -lm -o $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
				$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
		rm -rf $(OBJDIR) ${DEP}

fclean:	clean
		rm -rf $(NAME)

re:		fclean
		make all

# inclusion des dependances
-include $(DEP)