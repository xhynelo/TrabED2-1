/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Marcelo
 *
 * Created on 13 de Dezembro de 2015, 21:29
 */

#include <stdio.h>
#include <stdlib.h>

#include "Agencia.h"
#include "ContaCorrente.h"

#define AGENCIA "Agencia.dat"
#define CONTACORRENTE "ContaCorrente.dat"
/*
 * 
 */


int main(int argc, char** argv) {
    char opcao = 'b';
    FILE *outA, *outC, *inA, *inC;
    
    do{
        printf("a - agencia\nc - conta corrente\nOpcao: ");
        scanf(" %c", &opcao);
        if(opcao == 'a'){
            outA = fopen(AGENCIA, "ab");
            Agencia *agen = (Agencia *) malloc(sizeof(Agencia));
            
            printf("codigo da agencia: ");
            scanf(" %d", &agen->cod);
            printf("nome da agencia: ");
            scanf(" %s",agen->nome);
            printf("nome do gerente: ");
            scanf(" %s",agen->gerente);
            SalvaAgencia(agen, outA);
            free(agen);
            fclose(outA);
        }else if(opcao == 'c'){
            outC = fopen(CONTACORRENTE, "ab");
            ContaCorrente *cont_cor = (ContaCorrente *) malloc(sizeof(ContaCorrente));
            printf("codigo da conta: ");
            scanf(" %d", &cont_cor->cod);
            printf("codigo da agencia: ");
            scanf(" %d", &cont_cor->cod_agencia);
            printf("saldo: ");
            scanf(" %d", &cont_cor->saldo);
            SalvaConta(cont_cor, outC);
            free(cont_cor);
            fclose(outC);
            
        }
        
    
    }while(opcao == 'a' || opcao == 'c');
    
    
    inA = fopen(AGENCIA, "rw");
 /*   if(inA == NULL){
        return (EXIT_FAILURE);
    }*/
    Agencia *agencia;
    
    printf("codigo/-/ agencia/-/ gerente\n");
    while((agencia = LeAgencia(inA)) != NULL){
        printf("%d %s %s\n", agencia->cod, agencia->nome, agencia->gerente);
        free(agencia);
    }
    fclose(inA);
    
    inC = fopen(CONTACORRENTE, "rw");
    ContaCorrente *conta;
    printf("codigo/-/ codigo agencia/-/ saldo\n");
    while((conta = LeConta(inC)) != NULL){
        printf("%d %d %d\n", conta->cod, conta->cod_agencia, conta->saldo);
        free(conta);
    }
    fclose(inA);

    return (EXIT_SUCCESS);
}

