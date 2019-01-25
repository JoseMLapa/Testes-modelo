//
// Created by zegla on 18-Jan-19.
//

#ifndef TESTE_MODELO_STRUX_H
#define TESTE_MODELO_STRUX_H

#define MAX_REV 150
#define MAX_STR  100
#define MAX_TXT 1000

#ifdef	__cplusplus
extern "C" {
#endif

    enum tipo{FILME, SERIE, OUTRO};

    struct  utilizador{
        int id;
        char nome[MAX_STR];
    };

    struct review{
        struct utilizador* user;
        char texto[MAX_TXT + 1];
        unsigned short score;
    };

    struct item{
        int id, duracao, n_reviews;
        char titulo[MAX_TXT + 1], descricao[MAX_TXT + 1];
        enum tipo tipo;
        struct review reviews[MAX_REV];
    };

#ifdef	__cplusplus
extern "C" {
#endif

#endif //TESTE_MODELO_STRUX_H
