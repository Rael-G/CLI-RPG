
```
 _______                                __
|   _   |.--.--..----..-----..-----..--|  |
|.   ___||  |  ||   _||__ --||  -__||  _  |
|.  |___ |_____||__|  |_____||_____||_____|
|:      |
|::.. . |
`-------'
 ___                       __        
|   |    .---.-..-----..--|  |.-----.
|.  |    |  _  ||     ||  _  ||__ --|
|.  |___ |___._||__|__||_____||_____|
|:  |   |                            
|::.. . |
`-------'
 ___                                   __
|   |.-----..----..--.--..----..-----.|__|.-----..-----.
|.  ||     ||  __||  |  ||   _||__ --||  ||  _  ||     |
|.  ||__|__||____||_____||__|  |_____||__||_____||__|__|
|:  |
|::.|
`---'
```

INSTRUCTIONS


Step 1: Prerequisites

 Git to clone.  
 Clang or Gcc to compile.  

Step 2: Clone the Repository  

 Open your terminal.  
 Navigate to the directory where you want to clone the repository.  
 Run the command:  
 `git clone https://github.com/Rael-G/CLI-RPG.git`  

Step 3: Compile the Program  

 `cd CLIRpg`  
 If you're using Clang, skip to step 4!  
 If you're using GCC, open the Makefile and:  
  Comment out line 2: `#CXX = clang++`  
  Uncomment line 3: `CXX = g++`  
  Comment out line 6: `#CXXFLAGS = -std=c++20 -fcolor-diagnostics -fansi-escape-codes -g`  
  Uncomment line 7: `CXXFLAGS = -Wall -std=c++20`  
  
Step 4: Build the Program  

 In the terminal, on the repository directory, run the command:  
 `make`  

Step 5: Enjoy  

 `./bin/clirpg`  

Notes:  
 To keep your build clean, after updating the code, execute:  
 `make clean`  
 Then recompile the program using `make`.  
