#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <list>

using namespace std;


int main () {

    char valor;
    char valor2;

    string compresion;
    string compreso;
    string temp;
    string compressedValue;
    string decompressedValue;

    vector<string> vec;
    vector<string> result1;
    vector<string> result2;
    vector<string> result3;
    vector<string> compresionResult;
    vector<int>  tval;
    vector<int>  tval2;


    FILE* dictionary = fopen("dictionary.txt", "r");
    FILE* compressor = fopen("compressor.txt", "r");
    FILE* compressed = fopen("compressed.txt", "w");
    FILE* descompreso = fopen("descompreso.txt", "w");

    if(!compressor){
        cout << "Archivo no pudo ser abierto" << endl;
    }
    else {
        //Leemos cada char del archivo y lo asignamos a un valor string
        while(!feof(compressor)){
            fread(&valor, sizeof(char), 1, compressor);
            compresion += valor;
        }

        cout << "Default Value: "<<compresion<<endl;

        while(!feof(dictionary)){
            fread(&valor2, sizeof(char), 1, dictionary);
            compreso += valor2;
        }

        cout << "Dictionary: "<<compreso<<endl;
        cout << "\n";
        cout << "------------------------------- COMPRESSION ---------------------------------" <<endl;
        cout << "\n";

        stringstream ss1(compreso);

        while( ss1.good() )
        {
            string substr;
            getline( ss1, substr, ',' );
            result1.push_back( substr );
        }

        for (std::size_t i = 0; i < result1.size(); i++) {
            std::cout << result1[i] << std::endl;
        }


        for (std::size_t i = 0; i < result1.size(); i++) {
            string temp = result1[i];
            string temp2;
            temp2 += temp.back();
            result2.push_back( temp2 );
        }

        for(int i=0 ; i < result1.size() ; i++){
            string substr;
            stringstream ss3(result1[i]);
            getline( ss3, substr, '=' );
            result3.push_back( substr );
        }

        for (std::size_t i = 0; i < result3.size(); i++) {
            std::cout << result3[i] << std::endl;
        }

        //Por cada posicion del archivo de dictionario, se sustituye por el caracter del archivo compressor
        for(int i=0; i < compresion.length(); ++i){
            if(compresion.length() > i){
                temp += compresion[i];
                temp += compresion[i+1];
                bool compressedVerification = find(tval.begin(), tval.end(), i) != tval.end();
                bool decompressedVerification = find(tval2.begin(), tval2.end(), i) != tval2.end();

                //comprimir
                if(temp == result3[0]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[0];
                }else if(temp == result3[1]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[1];
                }else if(temp == result3[2]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[2];
                }else if(temp == result3[3]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[3];
                }else if(temp == result3[4]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[4];
                }else if(temp == result3[5]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[5];
                }else if(temp == result3[6]){
                    tval.push_back(i);
                    tval.push_back(i+1);
                    compressedValue +=result2[6];
                }else if(!compressedVerification){
                    compressedValue +=compresion[i];
                }

                //descomprimir
                if(temp == result2[0]){
//                    cout<<result3[0];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[0];
                }else if(temp == result2[1]){
//                   cout<<result3[1];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[1];
                }else if(temp == result2[2]){
//                    cout<<result3[2];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[2];
                }else if(temp == result2[3]){
//                    cout<<result3[3];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[3];
                }else if(temp == result2[4]){
//                    cout<<result3[4];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[4];
                }else if(temp == result2[5]){
//                    cout<<result3[5];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[5];
                }else if(temp == result2[6]){
//                    cout<<result3[6];
                    tval2.push_back(i);
                    tval2.push_back(i+1);
                    decompressedValue +=result3[6];
                }else if(!decompressedVerification){
                    //cout<< compresion[i];
                    decompressedValue +=compresion[i];
                }


            }
            temp="";
        }

        cout<<"Compressed Value: "<<compressedValue<<endl;
        cout<<"Decompressed Value: "<<decompressedValue<<endl;

        for(int i=0; i<compressedValue.length(); i++){
            fwrite(&compressedValue[i], sizeof(char), 1, compressed);
        }

        for(int i=0; i<decompressedValue.length(); i++){
            fwrite(&decompressedValue[i], sizeof(char), 1, descompreso);
        }




    }

    return 0;
}

