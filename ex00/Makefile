#parameters====================================================================

CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	= MyFirstClassInOrthodoxCanonicalForm
INCLUDE	=


#sources=======================================================================

SRCS	= main.cpp \
		  Fixed.cpp

OBJS	= $(SRCS:.cpp=.o)

TARGET_OBJS = $(OBJS)

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CPP) -o $@ $(TARGET_OBJS)

#const options=================================================================

%.o : %.c
	$(CPP) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
