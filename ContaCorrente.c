/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

#include "ContaCorrente.h"

    void SalvaConta(ContaCorrente *cont_cor, FILE *out){
        fwrite(&cont_cor->cod, sizeof(int), 1, out);
        fwrite(&cont_cor->cod_agencia, sizeof(int), 1, out);
        fwrite(&cont_cor->saldo, sizeof(int), 1, out);
    }
    
    ContaCorrente *LeConta(FILE *in){
        ContaCorrente *cont_cor = (ContaCorrente *) malloc(sizeof(ContaCorrente));
        if(0 >= fread(&cont_cor->cod, sizeof(int), 1, in)){
            free(cont_cor);
            return NULL;
        }
        fread(&cont_cor->cod_agencia, sizeof(int), 1, in);
        fread(&cont_cor->saldo, sizeof(int), 1, in);
        return cont_cor;
    }

