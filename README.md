**SpellChecker**

Program that show's you unusual words in the text:

**Installation**

1. Clone the repository:

    `git clone ssh://git@gitlab.se.ifmo.ru:4815/MikeSan/01-spellchecker.git`
   

2. Enter the directory:

    `cd 01-spellchecker`
   

3. Run `make`. Default build is release, other available builds are `make debug` and `make sanitized`


4. Make directories and executable files:
    
    `build` for release version, command `make / make all / make build`
    
    `ddir` for debug version, command `make debug`

    `dir` for sanitized version, command `make sanitized`

**Usage**

1. Run code:
   
   run release version: `.build/Program [RELATIVE FILEPATH]`
   
   run debug version: `.ddir/Program [RELATIVE FILEPATH]`
   
   run sanitized version: `.sdir/Program [RELATIVE FILEPATH]`
   
   Program - executable file.


2. Clean:
   use `make clean` - delete all executable files 
   

2. Commands
   
   `help` - print commands description
   
   `check` - print words with indexes not less than 'N' and not more words then 'word count'

   `set N` - set N indexes

   `set word count` - set count of words that program will print

   `print digrams / print trigrams` - print words and their N-grams

   `exit` - exit the program