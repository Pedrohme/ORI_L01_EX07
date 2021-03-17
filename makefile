SRCDIR := src
OBJDIR := obj
BINDIR := bin

BIN := $(BINDIR)/ex07
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CPPFLAGS := -Iinclude
CFLAGS   := -Wall

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ) | $(BINDIR)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(RM) -r $(BINDIR) $(OBJDIR)
	@echo "Limpo!"