# Definir o compilador
CXX = /usr/sbin/clang++
#CXX = g++

# Definir as opções de compilação
CXXFLAGS = -std=c++20 -fcolor-diagnostics -fansi-escape-codes -g
#CXXFLAGS = -Wall -std=c++17

# Definir os diretórios dos arquivos
SRC_DIR = ./src
BIN_DIR = ./bin
INC_DIR = ./include
INC_EXT = ./external/include
MAIN = ./main.cpp

# Adicionar o diretório de inclusão dos cabeçalhos
CXXFLAGS += -I$(INC_DIR) -i$(INC_EXT)

# Encontrar recursivamente todos os arquivos .cpp em SRC_DIR
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Obter os nomes dos arquivos .o correspondentes
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))


# Definir o nome do executável
TARGET = TextRPG

# Regra para gerar os arquivos-objeto
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	@mkdir -p $(@D) # Cria o diretório se não existir
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

# Regra para gerar o executável
$(BIN_DIR)/$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(MAIN)

all: $(BIN_DIR)/$(TARGET)

# Regra para limpar
clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean

# Lembrete do processo manual
#clang++ -c ./src/arquivo.cpp -o ./bin/arquivo.o
#clang++ ./main.cpp ./bin/*.o -o Programa