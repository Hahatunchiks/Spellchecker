**SpellChecker**

Program that show's you unusual words in the text

**Installation**

1. Clone the repository

    `git clone ssh://git@gitlab.se.ifmo.ru:`
   
2. Enter the directory

    `cd ...`
   
3. Run `make`. Default build is release, other available builds are `make debug` and `make sanitized`

4. Enter build directory. The name of the directory is the same as the build name
    
    `cd build` for release version
    
    `cd ddir` for debug version

    `sdir` for sanitized version

**Usage**

1. Run code
   
    `./Program [RELATIVE FILEPATH]`
   
2. Commands
    
    `help` - write it to look commands description
