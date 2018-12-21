/*
    Assembler
    Jesus A. Bernal Lopez
    Misael Gonzalez
    Michael Avalos
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include<cstdlib>

using namespace std;

string dec_to_binary(int dec);
string reg_to_binary(string reg);

int main()
{
    ifstream fin("input.txt");
    ofstream out("output.txt");

    map<string, int> array_nums;
    int array_count = 0;

    if(fin.fail())
    {
        cout << "File opening failed.\n";
        exit(0);
    }

    string opcode;
    string reg;
    string name;

    int num;
    int endlinecounter = 0;

    while(!fin.eof())
    {
        if (endlinecounter != 0)
            out << endl;
        endlinecounter++;

        fin >> opcode;

        if (opcode == "KLAR") // clear
            out << "00000000000000000000000000000000";
        else if (opcode == "PAPA") // print registers
            out << "00001000000000000000000000000000";
        else if(opcode == "DODAJ") // add
        {
            out << "00010";
            for (int i = 0; i < 3; i++)
            {
                fin >> reg;
                out << reg_to_binary(reg);
            }
            out << "000000000000000000";
        }
        else if (opcode == "LEVON") // subtract
        {
            out << "00011";
            for (int i = 0; i < 3; i++)
            {
                fin >> reg;
                out << reg_to_binary(reg);
            }
            out << "000000000000000000";
        }
        else if (opcode == "DUCAN") // store
        {
            out << "00100";

            fin >> num;
            out << dec_to_binary(num);

            fin >> reg;
            out << reg_to_binary(reg);

            out << "00000000000000000";
        }
        else if(opcode == "PRIDAT") // add registers
            out << "00101000000000000000000000000000";
        else if (opcode == "DIZI") // array
        {
            out << "00111";

            fin >> reg;
            out << reg_to_binary(reg);

            fin >> name;
            auto search = array_nums.find(name);
            if (search == array_nums.end()) //did not find name in map
            {
                array_nums[name] = array_count;
                out << dec_to_binary(array_nums[name]);
                array_count++;
                out << "00000000000000000";
            }
            else //it found the name
            {
                out << dec_to_binary(array_nums[name]);
                out << "00000000000000000";
            }
        }
        else if (opcode == "SAIDA") //output
        {
            out << "01000";

            fin >> reg;
            out << reg_to_binary(reg);

            out << "000000000000000000000000";
        }
        else if (opcode == "DUCANAHA") // store register
        {
            out << "01011";

            fin >> reg;
            out << reg_to_binary(reg);

            fin >> reg;
            out << reg_to_binary(reg);

            out << "000000000000000000000";
        }
        else if (opcode == "TARMA") // multiply
        {
            out << "01100";
            for (int i = 0; i < 3; i++)
            {
                fin >> reg;
                out << reg_to_binary(reg);
            }
            out << "000000000000000000";
        }
        else if (opcode == "DIVIDIR") // divide
        {
            out << "01101";
            for (int i = 0; i < 3; i++)
            {
                fin >> reg;
                out << reg_to_binary(reg);
            }
            out << "000000000000000000";
        }
        else if (opcode == "MAGISTER") // exponent
        {
            out << "01110";
            for (int i = 0; i < 3; i++)
            {
                fin >> reg;
                out << reg_to_binary(reg);
            }
            out << "000000000000000000";
        }
        else if (opcode == "MUTU") // stop
            out << "01111000000000000000000000000000";
        else if (opcode == "IPHELA") // populate
        {
            out << "10000";

            fin >> name;
            auto search = array_nums.find(name);
            if (search == array_nums.end()) //did not find name in map
            {
                out << "000000000000000000000000000" << endl;
                out << "01111000000000000000000000000000"; // will stop the program
            }
            else //it found the name
            {
                out << dec_to_binary(array_nums[name]);
                out << "00000000000000000000";
            }
        }
        else if (opcode == "GRUP") //output array
        {
            out << "10001";

            fin >> name;
            auto search = array_nums.find(name);
            if (search == array_nums.end()) //did not find name in map
            {
                out << "000000000000000000000000000" << endl;
                out << "01111000000000000000000000000000"; // will stop the program
            }
            else //it found the name
            {
                out << dec_to_binary(array_nums[name]);
                out << "00000000000000000000";
            }
        }
        else if (opcode == "GASI") // FIND
        {
            out << "10010";

            fin >> num;
            out << dec_to_binary(num);

            fin >> name;
            auto search = array_nums.find(name);
            if (search == array_nums.end()) //did not find name in map
            {
                out << "000000000000000000000000000" << endl;
                out << "01111000000000000000000000000000"; // will stop the program
            }
            else //it found the name
            {
                out << dec_to_binary(array_nums[name]);
                out << "0000000000000";
            }
        }
        else if(opcode == "MATRIXSOM") // array sum
        {
            out << "10011";

            fin >> name;
            auto search = array_nums.find(name);
            if (search == array_nums.end()) //did not find name in map
            {
                out << "000000000000000000000000000" << endl;
                out << "01111000000000000000000000000000"; // will stop the program
            }
            else //it found the name
                out << dec_to_binary(array_nums[name]);

            fin >> reg;
            out << reg_to_binary(reg);
            out << "00000000000000000";
        }
        else if(opcode == "MOIDE") // plus
        {
            out << "10100";

            fin >> reg;
            out << reg_to_binary(reg);
            out << "000000000000000000000000";
        }
        else if(opcode == "MOINS") // minus
        {
            out << "10101";

            fin >> reg;
            out << reg_to_binary(reg);
            out << "000000000000000000000000";
        }
    }
    fin.close();
    out.close();
    return EXIT_SUCCESS;
}

string dec_to_binary(int dec)
{
    string bin = "";
    if(dec == 0)
        return "0000000";
    while(dec / 2 != 0)
    {
        bin = to_string(dec % 2) + bin;
        dec /= 2;
    }
    bin = "1" + bin;
    while(bin.size() < 7)
        bin = "0" + bin;
    return bin;
}
string reg_to_binary(string reg)
{
    if(reg == "R1")
        return "000";
    else if(reg == "R2")
        return "001";
    else if(reg == "R3")
        return "010";
    else if(reg == "R4")
        return "011";
    else if(reg == "R5")
        return "100";
    else if(reg == "R6")
        return "101";
    else if(reg == "R7")
        return "110";
    else if(reg == "R8")
        return "111";
    return "Error\n";
}
