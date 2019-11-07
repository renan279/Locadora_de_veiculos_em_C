#include<stdio.h>
#define true 1
#define false 0

// DECLARAÇÃO DAS ESTRUTURAS//

struct Car{
    char renavan[30];
    char placa[7];
    char marca[30];
    char modelo[30];
    int ano;
    char cor[25];
 	char categoria;
	int disp; //1 true 0 false
};
typedef struct Car Car;

struct Client{
    char nome[50];
    char dataNasc[10];
    long int cpf;
	long int rg;
    char CNH[11];
    char valCNH;
    char nacio[2];
};
typedef struct Client Client;

struct Date{
    int dia;
    int mes;
    int ano;
};
typedef struct Date Date;

struct Rent{
    long int cpf_cliente;
    char nome_cliente;
    char placa_locado;
    Date data_locacao;
    Date data_devolucao;
    int finalizado; //TRUE = FINALIZADO; FALSE = AINDA NAO FINALIZADO
};
typedef struct Rent Rent;


int cadastra_carro();
int cadastra_cliente();
Car consulta_carro(char placa[]);
Client consulta_cliente(long int cpf);
Rent consultar_locacao(long int cpf);
void locar_veiculo();
int editar_carro(char placa[]);
int sbt_data(Date devolucao, Date loc);
float gerar_pagamento(char placa[], Date devolucao, long int cpf);
void devolver_carro();

