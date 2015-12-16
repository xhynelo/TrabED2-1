/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContaCorrente.h
 * Author: Marcelo
 *
 * Created on 13 de Dezembro de 2015, 22:34
 */

#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ContaCorrente{
        int cod;
        int cod_agencia;
        int saldo;
    }ContaCorrente;
    
    void SalvaConta(ContaCorrente *cont_cor, FILE *out);
    
    ContaCorrente *LeConta(FILE *in);


#ifdef __cplusplus
}
#endif

#endif /* CONTACORRENTE_H */

