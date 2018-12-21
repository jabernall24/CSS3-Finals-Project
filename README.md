# CSS3 Final Project

Out ISA project was made unique by using different languagues for every instruction we made.
Our ISA project contained 19 instructions.
Our ISA project has 5 bit opcodes.
Our ISA project contained 8 registers of 3 bits that can be used for any purpose.
Out ISA project was able to take any size array and allowed the user to populate the array.
Out ISA project used 32 bit instructions.

## Benchmark #1
LINE #      INSTRUCTION
1           KLAR
2           DUCAN 5 R1
3           DIZI R1 APPLE
4           IPHELA APPLE
5           MATRIXSOM APPLE R2
6           SAIDA R2
7           MUTU

### OUTPUT:
Populate [0000000]: 1 
Populate [0000000]: 2 
Populate [0000000]: 3 
Populate [0000000]: 4 
Populate [0000000]: 5 
Register 2: 15

### EXPLANATION:
1. SETS THE VALUE OF ALL REGISTERS TO 0 -> EX. R1 = 0
2. R1 = 5
3. CREATES AN ARRAY OF SIZE OF THE VALUE IN R1[5] AND IS NAMED "APPLE" 
    HOWEVER IN THE PROGRAM IT WILL BE "0000000" SINCE IT IS THE FIRST ARRAY
4. ASKS USER TO INPUT 5 VALUES BY OUTPUTTING -> "Populate [0000000]: " AND THE 
    USER PUTS IN THE VALUE IN THIS CASE WE PUT THE FOLLOWING VALUES -> 1 2 3 4 5
5. ADDS THE VALUES IN THE ARRAY "APPLE"(0000000) AND STORES IT IN R2
    1 + 2 + 3 + 4 + 5 = R2[15] -> R2 = 15
6. PRINTS OUT THE VALUE IN R2 "Register 2: 15"
7. STOPS THE PROGRAM

## Benchmark #2
LINE #      INSTRUCTION
1           KLAR
2           DUCAN 5 R1
3           DIZI R1 APPLE
4           KLAR
5           IPHELA APPLE
6           GASI 4 APPLE
7           MUTU

### OUTPUT:
Populate [0000000]: 1 
Populate [0000000]: 2
Populate [0000000]: 3 
Populate [0000000]: 4 
Populate [0000000]: 5 
[0000000]: 4, Yes

### EXPLANATION:
1. SETS THE VALUE OF ALL REGISTERS TO 0 -> EX. R1 = 0
2. R1 = 5
3. CREATES AN ARRAY OF SIZE OF THE VALUE IN R1[5] AND IN NAMED "APPLE"
    HOWEVER IN THE PROGRAM IT WILL BE "0000000" SINCE IT IS THE FIRST ARRAY
4. SETS THE VALUE OF ALL REGISTERS TO 0 -> EX. R1 = 0
5. ASKS USER TO INPUT 5 VALUES BY OUTPUTTTING -> "Populate [0000000]: " AND THE
    USER PUTS IN THE VALUE IN THIS CASE WE PUT THE FOLLOWING VALUES -> 1 2 3 4 5
6. LOOKS THROUGH THE ARRAY "APPLE"(0000000) FOR THE VALUE 4 AND IT FOUND IT
    SO IT PRINTS OUT "[0000000]: 4, YES"
7. STOPS THE PROGRAM
