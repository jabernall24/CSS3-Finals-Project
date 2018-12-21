/*
    Simulator
    Jesus A. Bernal Lopez
    Misael Gonzalez
    Michael Avalos
*/
#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

string registernum(string reg);
int binary_to_decimal(string bin);

int main()
{
    fstream fin("output.txt");

    if(fin.fail())
    {
        cout << "File opening failed.\n";
        exit(1);
    }

    map<string, int> reg_map;
    map<string, vector<int>> vector_map;

    reg_map["R1"] = 0;
    reg_map["R2"] = 0;
    reg_map["R3"] = 0;
    reg_map["R4"] = 0;
    reg_map["R5"] = 0;
    reg_map["R6"] = 0;
    reg_map["R7"] = 0;
    reg_map["R8"] = 0;

    string opcode;
    string instruction;

    while(!fin.eof())
    {
        fin >> instruction;
        opcode = instruction.substr(0, 5);
        if(opcode == "00000") // klar : clear
        {
            reg_map["R1"] = 0;
            reg_map["R2"] = 0;
            reg_map["R3"] = 0;
            reg_map["R4"] = 0;
            reg_map["R5"] = 0;
            reg_map["R6"] = 0;
            reg_map["R7"] = 0;
            reg_map["R8"] = 0;
        }
        else if(opcode == "00001") // PAPA : print registers
        {
            cout << "Register 1:" << reg_map["R1"] << endl;
            cout << "Register 2:" << reg_map["R2"] << endl;
            cout << "Register 3:" << reg_map["R3"] << endl;
            cout << "Register 4:" << reg_map["R4"] << endl;
            cout << "Register 5:" << reg_map["R5"] << endl;
            cout << "Register 6:" << reg_map["R6"] << endl;
            cout << "Register 7:" << reg_map["R7"] << endl;
            cout << "Register 8:" << reg_map["R8"] << endl;
        }
        else if(opcode == "00010") // dodaj : add
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            string regisC = registernum(instruction.substr(11,3));
            reg_map[regisC] = reg_map[regisA] + reg_map[regisB];
        }
        else if(opcode == "00011") // levon : subtract
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            string regisC = registernum(instruction.substr(11,3));
            reg_map[regisC] = reg_map[regisA] - reg_map[regisB];
        }
        else if(opcode == "00100") // ducan : store
        {
            int num = binary_to_decimal(instruction.substr(5,7));
            string regisA = registernum(instruction.substr(12,3));
            reg_map[regisA] = num;
        }
        else if(opcode == "00101")
        {
            int sum = reg_map["R1"] + reg_map["R2"] + reg_map["R3"] + reg_map["R4"] + reg_map["R5"]
                      + reg_map["R6"] + reg_map["R7"] + reg_map["R8"];
            cout << "Sum: " << sum << endl;
        }
        else if(opcode == "00111") // dizi: array
        {
            string ary_name = instruction.substr(8,7);
            string reg_name = registernum(instruction.substr(5,3));
            vector_map[ary_name].resize(reg_map[reg_name]);
        }
        else if(opcode == "01000") // saida: output
        {
            string regisA = registernum(instruction.substr(5,3));
            cout << "Register " << regisA.substr(1,1) << ": " << reg_map[regisA] << endl;
        }
        else if(opcode == "01011") // Ducanaha : store register
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            reg_map[regisB] = reg_map[regisA];
        }
        else if(opcode == "01100") // Tarma : multiply
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            string regisC = registernum(instruction.substr(11,3));
            reg_map[regisC] = reg_map[regisA] * reg_map[regisB];
        }
        else if(opcode == "01101") // dividir : divide
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            string regisC = registernum(instruction.substr(11,3));
            reg_map[regisC] = reg_map[regisA] / reg_map[regisB];
        }
        else if(opcode == "01110") // magister : exponent
        {
            string regisA = registernum(instruction.substr(5,3));
            string regisB = registernum(instruction.substr(8,3));
            string regisC = registernum(instruction.substr(11,3));
            reg_map[regisC] = pow(reg_map[regisA], reg_map[regisB]);
        }
        else if(opcode == "01111") // Mutu : stop
            exit(1);
        else if(opcode == "10000") // iphela : populate
        {
            vector<int> populate;
            int value;
            string ary_name = instruction.substr(5,7);
            int size = vector_map[ary_name].size();
            for(int i = 0; i < size; i++)
            {
                cout << "Populate [" << ary_name << "]: ";
                cin >> value;
                populate.push_back(value);
            }
            vector_map[ary_name] = populate;
        }
        else if(opcode == "10001") // GRUP : output array
        {
            string ary_name = instruction.substr(5,7);
            cout << "[" << ary_name << "]: ";
            for(int i = 0; i < vector_map[ary_name].size(); i++)
            {
                if(i+1 == vector_map[ary_name].size())
                    cout << vector_map[ary_name][i] << endl;
                else
                    cout << vector_map[ary_name][i] << ", ";
            }
        }
        else if(opcode == "10010") // GASI : find
        {
            int val = binary_to_decimal(instruction.substr(5,7));
            string ary_name = instruction.substr(12,7);
            for(auto i : vector_map)
            {
                for(int j = 0; j < vector_map[ary_name].size(); j++)
                {
                    if(i.second[j] == val)
                    {
                        cout << "[" << i.first << "]: " << val << ", Yes\n";
                        break;
                    }
                    else if(j+1 == vector_map[ary_name].size())
                        cout << "[" << i.first << "]: " << val << ", No\n";
                }
            }
        }
        else if(opcode == "10011") // MATRIXSOM : array sum
        {
            string ary_name = instruction.substr(5,7);
            string regis = registernum(instruction.substr(12,3));
            int sum = 0;
            for(auto i : vector_map)
            {
                for(int j = 0; j < vector_map[ary_name].size(); j++)
                {
                    sum = sum + i.second[j];
                }
            }
            reg_map[regis] = sum;
        }
        else if(opcode == "10100") // MOIDE : plus
        {
            string reg = registernum(instruction.substr(5,3));
            reg_map[reg]++;

        }
        else if(opcode == "10101") // MOINS : minus
        {
            string reg = registernum(instruction.substr(5,3));
            reg_map[reg]--;
        }
        else
        {
            cout << "Program ran into an error\n";
            exit(0);
        }
    }
    fin.close();
    return EXIT_SUCCESS;
}

string registernum(string reg)
{
    if(reg == "000")
        return "R1";
    else if(reg == "001")
        return "R2";
    else if(reg == "010")
        return "R3";
    else if(reg == "011")
        return "R4";
    else if(reg == "100")
        return "R5";
    else if(reg == "101")
        return "R6";
    else if(reg == "110")
        return "R7";
    else if(reg == "111")
        return "R8";
    return "incorrect entry";
}

int binary_to_decimal(string bin)
{
    int decimal = 0;
    if(bin[0] == '1')
        decimal = decimal + 64;
    if(bin[1] == '1')
        decimal = decimal + 32;
    if(bin[2] == '1')
        decimal = decimal + 16;
    if(bin[3] == '1')
        decimal = decimal + 8;
    if(bin[4] == '1')
        decimal = decimal + 4;
    if(bin[5] == '1')
        decimal = decimal + 2;
    if(bin[6] == '1')
        decimal = decimal + 1;
    return decimal;
}
