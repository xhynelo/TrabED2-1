/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Agencia.h
 * Author: Marcelo
 *
 * Created on 13 de Dezembro de 2015, 21:54
 */

#ifndef AGENCIA_H
#define AGENCIA_H

#define TAN_NOME 50

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Agencia{
    int cod;
    char nome[TAN_NOME];
    char gerente[TAN_NOME];
}Agencia;

void SalvaAgencia(Agencia *agen, FILE *out);

Agencia *LeAgencia(FILE *in);


    


#ifdef __cplusplus
}
#endif

#endif /* AGENCIA_H */

