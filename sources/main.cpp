/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jordi
 *
 * Created on August 22, 2017, 11:59 AM
 */

#include <stdio.h>
#include <cstdlib>
#include <iostream>
//#include <sstream>
#include <string>
#include <vector>
#include "zutil.h"
#include "zindex.h"
#include "CStringTools.h"
#include "CTFasta.h"
#include "File.h"

void help(std::string name) {
    std::cerr << "Merge_tFastas\n"
            << "Usage: ./merge_tfastas -i list_tFastas.txt -o outputname\n"
            << "Options:\n"
            << "\t-h\t\tHelp and exit\n"
            << "\t-i\t\tList with the name of all tFasta to merge (with the path to each file if they were not in the same directory of program)\n"
            << "\t-o\t\tOutput compressed tFasta filename (without extension)\n"
            << std::endl;
}

int main(int argc, char** argv) {

    /////////////////////////////
    // Argumentos del programa //
    /////////////////////////////

    std::string tfastalist;
    std::string outtfastaname;
    std::string outtfasta;

    char tmp;
    if (argc == 1) {
        help(argv[0]);
        exit(1);
    }

    while ((tmp = getopt(argc, argv, "hi:o:")) != -1) {
        switch (tmp) {
            case 'h':
                help(argv[0]);
                break;
            case 'i':
                tfastalist = std::string(optarg);
                break;
            case 'o':
                outtfastaname = std::string(optarg);
                break;
        }
    }

    if (tfastalist == "") {
        // Si no se da ninguna lista de tFastas en el comando
        std::cout << std::endl;
        std::cout << "Error:" << std::endl;
        std::cout << "\tList of tFastas not defined" << std::endl;
        std::cout << std::endl;
        return 1;
    }
    if (outtfastaname == "") {
        // Si no se da ningun nombre para el output en el comando
        std::cout << std::endl;
        std::cout << "Error:" << std::endl;
        std::cout << "\tOutput tFasta file name not defined" << std::endl;
        std::cout << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "List of tFastas: " << tfastalist << std::endl;
    outtfasta = outtfastaname + ".tfa.gz";
    std::cout << "Output tFasta file: " << outtfasta << std::endl;
    std::cout << std::endl;

    File list(tfastalist);

    char c;
    std::string l = "";
    std::vector<std::string> tfastas_vector;

    // Obtaining all tFasta to merge from the input list
    if (list.openReadFile()) {
        while (!list.endFile()) {
            c = list.getFileChar();
            if (c == '\n') {
                tfastas_vector.push_back(l);
                l = "";
            } else {
                l += c;
            }
        }
        list.closeFile();
    }

    std::vector<CTFasta> tfastatype_vector;
    std::vector<CTFasta> t_fasta_group;
    std::vector<std::string> line;
    std::vector<std::string> linetfa;
    std::vector<std::string> linetfa_pos;
    std::vector<std::string> typeline;
    
    CTFasta tfasta_group_0(tfastas_vector[0]);
    CTFasta tfasta_group_1(tfastas_vector[1]);
    CTFasta out_tfasta(outtfasta);

    std::string line1;
    std::string line2;

    // Abrir el tFasta output para escribir en él
    if (out_tfasta.openWriteFile()) {
        // Abrir los 2 tFasta que queremos unir
        if ((tfasta_group_0.openReadFile()) && (tfasta_group_1.openReadFile())) {
            // Siempre que no lleguemos al final de ambos archivos:
            while ((!tfasta_group_0.endFile()) && (!tfasta_group_1.endFile())) {
                line1 = tfasta_group_0.readLine();
                line2 = tfasta_group_1.readLine();
                if (line1[0] == '#' && line2[0] == '#') {
                    // Si ambas lineas corresponden al header
                    if (line1[1] == 'v' && line2[1] == 'v' && line1[2] == 'c' && line2[2] == 'c') {
                        // Si las 2 lineas son la primera del header de los tfastas
                        out_tfasta.writeFile("#merge_tfastas -i list_tFastas.txt -o outputname\n");
                    } else if (line1[1] == 'N' && line2[1] == 'N' && line1[2] == 'A' && line2[2] == 'A') {
                        // Si las 2 lineas son la segunda del header de los tfastas
                        std::vector<std::string> linetfa2_vector = CStringTools::split(line2, ' ');
                        out_tfasta.writeFile(line1 + "\t" + linetfa2_vector[1] + "\n");
                    } else if (line1[1] == 'C' && line2[1] == 'C' && line1[2] == 'H' && line2[2] == 'H') {
                        // Si las 2 lineas son la tercera del header de los tfastas
                        out_tfasta.writeFile(line1 + "\n");
                    }
                } else if (line1[0] != '#' && line2[0] != '#') {
                    // Si ambas lineas corresponden a secuencia (no a header)
                    std::vector<std::string> linetfa1_vector = CStringTools::split(line1, '\t');
                    std::vector<std::string> linetfa2_vector = CStringTools::split(line2, '\t');
                    if (linetfa1_vector[0] == linetfa2_vector[0]) {
                        // Si las 2 lineas corresponden al mismo cromosoma y posicion
                        out_tfasta.writeFile(linetfa1_vector[0] + "\t" + linetfa1_vector[1] + linetfa2_vector[1] + "\n");
                    } else {
                        // Si las 2 lineas son diferentes (una es header y la otra secuencia)
                        std::cout << std::endl;
                        std::cout << "Error:" << std::endl;
                        std::cout << "\tDiferent chromosome and/or position in tFasta files" << std::endl;
                        std::cout << std::endl;
                        return 1;
                    }
                } else {
                    // Si las 2 lineas son diferentes (una es header y la otra secuencia)
                    std::cout << std::endl;
                    std::cout << "Error:" << std::endl;
                    std::cout << "\tWrong number of lines in the header of some of the tFasta files" << std::endl;
                    std::cout << std::endl;
                    return 1;
                }
            }
            tfasta_group_0.closeFile();
            tfasta_group_1.closeFile();
        }
        out_tfasta.closeFile();
    }

    return 0;
}
