##
## EPITECH PROJECT, 2021
## raytracer
## File description:
## make
##

ECHO	=	/bin/echo -e
RED		=	"\e[0;31m"
GREEN	=	"\e[32m"
DEFAULT	=	"\e[0m"
CLAIR	=	"\e[1m"
DEL		=	[DELETE]

SRC	=	src/main.cpp	\
		src/Core.cpp	\
		src/Config.cpp	\
		src/Vector3D.cpp	\
		src/Color.cpp	\
		src/Ray.cpp	\
		src/Light.cpp	\
		src/Scene.cpp	\
		src/Camera.cpp	\
		src/Sphere.cpp	\
		src/Cylinder.cpp	\
		src/Plane.cpp	\
		src/Cone.cpp	\
		src/ImagePPM.cpp	\

CXXFLAGS	=	-I./inc -W -Wall -Wextra -g3

LIBFLAGS	=	-lconfig++ -rdynamic -lsfml-graphics -lsfml-window -lsfml-system

CC	=	c++

OBJ	=	$(SRC:.cpp=.o)

NAME	=	raytracer

all: message $(NAME)

message:
	@$(ECHO) $(CLAIR) "\n  [?] COMPILATION...\n" $(DEFAULT)

$(NAME): $(OBJ)
	@$(ECHO)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIBFLAGS)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIBFLAGS) &&	\
		$(ECHO) $(GREEN) "\n  [✔] COMPILED:" "$(NAME)\n" $(DEFAULT) ||	\
		$(ECHO) $(RED) "\n  [✘] BUILD FAILED:" "$(NAME)\n" $(DEFAULT)

clean:
	@rm -f $(OBJ) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "OBJ -> $(OBJ)" $(DEFAULT)

fclean:
	@rm -f $(OBJ) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "OBJ -> $(OBJ)" $(DEFAULT)
	@rm -f $(NAME) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "NAME -> $(NAME)" $(DEFAULT)

re: fclean all

.PHONY: all message clean fclean
