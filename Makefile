CFLAGS_DEBUG=-std=c++17 -Wall -Werror -g
CFLAGS_SANITIZED=${CFLAGS_DEBUG} -fsanitize=address,undefined,leak
CFLAGS_RELEASE=${CFLAGS_DEBUG} -O3
BUILDDIR=./build
DEBUGDIR=./ddir
SANITIZERDIR=./sdir
SRCDIR=.
CC=clang++

all: release
sanitized: CFLAGS=$(CFLAGS_SANITIZED)
sanitized:
	$(CC) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/HelpCommand.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp $(SRCDIR)/Text.cpp -o $(SANITIZERDIR)/Program -lstdc++ $(CFLAGS)

debug: CFLAGS=$(CFLAGS_DEBUG)
debug:
	$(CC) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/HelpCommand.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp $(SRCDIR)/Text.cpp -o $(DEBUGDIR)/Program -lstdc++

release: CFLAGS=$(CFLAGS_RELEASE)
release:
	$(CC) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/HelpCommand.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp $(SRCDIR)/Text.cpp -o $(BUILDDIR)/Program -lstdc++

build_release:
	mkdir -p $(BUILDDIR)

build_debug:
	mkdir -p $(DEBUGDIR)

build_sanitized:
	mkdir -p $(SANITIZERDIR)

clean_release:
	rm -rf $(BUILDDIR)/*

clean_debug:
	rm -rf $(DEBUGDIR)/*

clean_sanitized:
	rm -rf $(SANITIZERDIR)/*
