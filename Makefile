CXXFLAGS_DEBUG=-std=c++17 -Wall -Werror -g
CXXFLAGS_SANITIZED=${CXXFLAGS_DEBUG} -fsanitize=address,undefined,leak
CXXFLAGS_RELEASE=${CXXCFLAGS_DEBUG} -O3
BUILDDIR=./build_release
DEBUGDIR=./build_debug
SANITIZERDIR=./build_sanitized
CXX=clang++

all: release
#release
$(BUILDDIR)/main.o: main.cpp
	$(CXX) -c $(CXXFLAGS_RELEASE) $< -o $(BUILDDIR)/main.o

$(BUILDDIR)/Application.o: Application.cpp
	$(CXX) -c $(CXXFLAGS_RELEASE) $< -o $(BUILDDIR)/Application.o

$(BUILDDIR)/Client.o: Client.cpp
	$(CXX) -c $(CXXFLAGS_RELEASE) $< -o $(BUILDDIR)/Client.o

$(BUILDDIR)/Ngrams.o: Ngrams.cpp
	$(CXX) -c $(CXXFLAGS_RELEASE) $< -o $(BUILDDIR)/Ngrams.o

$(BUILDDIR)/SpellChecker.o: SpellChecker.cpp
	$(CXX) -c $(CXXFLAGS_RELEASE) $< -o $(BUILDDIR)/SpellChecker.o

build_release:
	mkdir -p $(BUILDDIR)

_release:  CXXFLAGS+=$(CXXFLAGS_RELEASE)
_release:  $(BUILDDIR)/main.o $(BUILDDIR)/Client.o $(BUILDDIR)/Ngrams.o $(BUILDDIR)/SpellChecker.o $(BUILDDIR)/Application.o
	$(CXX) -o $(BUILDDIR)/Program $^  -lstdc++ $(CXXFLAGS)

release: build_release _release

clean_release:
	rm -rf $(BUILDDIR)/*

#debug
$(DEBUGDIR)/main.o: main.cpp
	$(CXX) -c $(CXXFLAGS_DEBUG) $< -o $(DEBUGDIR)/main.o

$(DEBUGDIR)/Application.o: Application.cpp
	$(CXX) -c $(CXXFLAGS_DEBUG) $< -o $(DEBUGDIR)/Application.o

$(DEBUGDIR)/Client.o: Client.cpp
	$(CXX) -c $(CXXFLAGS_DEBUG) $< -o $(DEBUGDIR)/Client.o

$(DEBUGDIR)/Ngrams.o: Ngrams.cpp
	$(CXX) -c $(CXXFLAGS_DEBUG) $< -o $(DEBUGDIR)/Ngrams.o

$(DEBUGDIR)/SpellChecker.o: SpellChecker.cpp
	$(CXX) -c $(CXXFLAGS_DEBUG) $< -o $(DEBUGDIR)/SpellChecker.o

build_debug:
	mkdir -p $(DEBUGDIR)

_debug: CXXFLAGS+=$(CXXFLAGS_DEBUG)
_debug:    $(DEBUGDIR)/main.o $(DEBUGDIR)/Client.o $(DEBUGDIR)/Ngrams.o $(DEBUGDIR)/SpellChecker.o $(DEBUGDIR)/Application.o
	$(CXX) -o $(DEBUGDIR)/Program $^  -lstdc++ $(CXXFLAGS)

debug: build_debug _debug

clean_debug:
	rm -rf $(DEBUGDIR)/*

#sanitized
$(SANITIZERDIR)/main.o: main.cpp
	$(CXX) -c $(CXXFLAGS_SANITIZED) $< -o $(SANITIZERDIR)/main.o

$(SANITIZERDIR)/Application.o: Application.cpp
	$(CXX) -c $(CXXFLAGS_SANITIZED) $< -o $(SANITIZERDIR)/Application.o

$(SANITIZERDIR)/Client.o: Client.cpp
	$(CXX) -c $(CXXFLAGS_SANITITZED) $< -o $(SANITIZERDIR)/Client.o

$(SANITIZERDIR)/Ngrams.o: Ngrams.cpp
	$(CXX) -c $(CXXFLAGS_SANITIZED) $< -o $(SANITIZERDIR)/Ngrams.o

$(SANITIZERDIR)/SpellChecker.o: SpellChecker.cpp
	$(CXX) -c $(CXXFLAGS_SANITIZED) $< -o $(SANITIZERDIR)/SpellChecker.o

build_sanitized:
	mkdir -p $(SANITIZERDIR)

_sanitized: CXXFLAGS+=$(CXXFLAGS_SANITIZED)
_sanitized:    $(SANITIZERDIR)/main.o $(SANITIZERDIR)/Client.o $(SANITIZERDIR)/Ngrams.o $(SANITIZERDIR)/SpellChecker.o $(SANITIZERDIR)/Application.o
	$(CXX) -o $(SANITIZERDIR)/Program $^  -lstdc++ $(CXXFLAGS)

sanitized: build_sanitized _sanitized

clean_sanitized:
	rm -rf $(SANITIZERDIR)/*

clean: clean_debug clean_release clean_sanitized