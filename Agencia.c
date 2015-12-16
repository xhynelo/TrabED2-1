/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

#include "Agencia.h"


void SalvaAgencia(Agencia *agen, FILE *out){
    fwrite(&agen->cod, sizeof(int), 1, out);
    fwrite(agen->nome, sizeof(char), sizeof(agen->nome), out);
    fwrite(agen->gerente, sizeof(char), sizeof(agen->gerente), out);
    
}

Agencia *LeAgencia(FILE *in){
    Agencia *agen = (Agencia *) malloc(sizeof(Agencia));
    if(0 >= fread(&agen->cod, sizeof(int), 1, in)){
        free(agen);
        return NULL;
    }
    fread(agen->nome, sizeof(char), sizeof(agen->nome), in);
    fread(agen->gerente, sizeof(char), sizeof(agen->gerente), in);
    return agen;
}


