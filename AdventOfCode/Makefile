CC = g++
CXXFLAGS = -Wall -Wextra

IDIR = include
ODIR = build
BDIR = bin
SRCDIR = src
LIBDIR = lib

# Archivos fuente
LIB_SOURCES = $(wildcard $(LIBDIR)/*.cpp) # wildcard crea la lista de todos los objetos que coinciden con ese patrón
SRC_SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Archivos objeto
LIB_OBJ = $(LIB_SOURCES:$(LIBDIR)/%.cpp=$(ODIR)/%.o) # Para cada archivo en la lista, sustituye la carpeta y la extensión
SRC_OBJ = $(SRC_SOURCES:$(SRCDIR)/%.cpp=$(ODIR)/%.o)

all: $(BDIR)/main # Lo que ejecuta el comando make

# Regla para crear el ejecutable
$(BDIR)/main: $(LIB_OBJ) $(SRC_OBJ) | $(BDIR)
	$(CC) $(LIB_OBJ) $(SRC_OBJ) -o $@

# Regla para compilar los archivos de lib/
$(ODIR)/%.o: $(LIBDIR)/%.cpp | $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Regla para compilar los archivos de src/
$(ODIR)/%.o: $(SRCDIR)/%.cpp | $(ODIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Crear directorios necesarios
$(BDIR):
	mkdir -p $(BDIR)
$(ODIR):
	mkdir -p $(ODIR)

# Limpieza
clean:
	rm -rf $(ODIR) $(BDIR)

help:
	@echo "Comandos disponibles:"
	@echo "  make         - Compila el programa"
	@echo "  make clean   - Limpia los archivos generados"
