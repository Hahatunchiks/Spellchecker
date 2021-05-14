CXXFLAGS_DEBUG=-std=c++17 -Wall -Werror -g
CXXFLAGS_SANITIZED=${CFLAGS_DEBUG} -fsanitize=address,undefined,leak
CXXFLAGS_RELEASE=${CFLAGS_DEBUG} -O3
BUILDDIR=./build
DEBUGDIR=./ddir
SANITIZERDIR=./sdir
SRCDIR=.
CXX=clang++

all: release
sanitized: CXXFLAGS+=$(CXXFLAGS_SANITIZED)
sanitized: build_sanitized
	$(CXX) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp -o $(SANITIZERDIR)/Program -lstdc++ $(CXXFLAGS)

debug: CXXFLAGS+=$(CXXFLAGS_DEBUG)
debug: build_debug
	$(CXX) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp -o $(DEBUGDIR)/Program -lstdc++ $(CXXFLAGS)

release: CXXFLAGS+=$(CXXFLAGS_RELEASE)
release: build_release
	$(CXX) $(SRCDIR)/main.cpp $(SRCDIR)/Application.cpp $(SRCDIR)/Client.cpp $(SRCDIR)/Ngrams.cpp $(SRCDIR)/SpellChecker.cpp -o $(BUILDDIR)/Program -lstdc++ $(CXXFLAGS)

build_release:
	mkdir -p $(BUILDDIR)

build_debug:
	mkdir -p $(DEBUGDIR)

build_sanitized:
	mkdir -p $(SANITIZERDIR)

clean: clean_debug clean_release clean_sanitized

clean_release:
	rm -rf $(BUILDDIR)/*

clean_debug:
	rm -rf $(DEBUGDIR)/*

clean_sanitized:
	rm -rf $(SANITIZERDIR)/*
