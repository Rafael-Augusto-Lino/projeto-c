# Compilador e Flags
CC = gcc
CFLAGS = -Wall -Wextra -g3

# Pastas
SRC_DIR = Sources
BUILD_DIR = Sources/output

# Executável
TARGET = $(BUILD_DIR)/main.exe

# Lista de arquivos (procura todos os .c em Sources)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# --- REGRAS DE COMPILAÇÃO ---
# GARANTIA: "all" precisa ser a primeira regra para o make saber por onde começar
all: $(TARGET)

# Regra para linkar os arquivos .o e gerar o .exe
$(TARGET): $(OBJS)
	@echo Linkando os modulos e gerando o executavel...
	$(CC) $(OBJS) -o $(TARGET)
	@echo Compilacao concluida com sucesso!

# Regra para compilar cada arquivo .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compilando: $<
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar o projeto
clean:
	@echo Limpando arquivos antigos de build...
	if exist $(SRC_DIR)\output del /q $(SRC_DIR)\output\*

# Regra para compilar e rodar direto
run: all
	@echo Executando o programa:
	@echo ----------------------------------------
	$(TARGET)

.PHONY: all clean run