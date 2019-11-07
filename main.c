#include "LocVeiculos.h"
#include "LocVeiculos.c"
#include <stdio.h>
#include <conio.h>
int main(){
    int opc, ret;
    long int cpf;
    char pl;
    Car x;
    Client c;
    Rent r;


    printf("-----------Cadastros-----------");
    printf("1 - Cadastrar Cliente! \n");
    printf("2 - Cadastrar Veiculos! \n");
    printf("3 - Realizar Locação \n");
    printf("-----------Consultas-----------");
    printf("4 - Consultar Cliente! \n");
    printf("5 - Consultar Veiculos! \n");
    printf("6 - Coonsultar Locacao! \n");
    printf("-----------Devolucao----------");
    printf("7 - Devolucao de Veiculo! \n");
    scanf("%d ", &opc);

    switch(opc){
    case 1:
        ret = cadastra_cliente();
        if (ret == 1) printf("Cadastro Realizado com Sucesso!");
        if (ret == 0) printf("Erro! Cadastro Nao Realizado!");
        break;
    case 2:
        ret = cadastra_carro();
        if (ret == 1) printf("Cadastro Realizado com Sucesso!");
        if (ret == 0) printf("Erro! Cadastro Nao Realizado!");
        break;

    case 3:
        if(locar_veiculo() == NULL) printf("Erro na Locacao!");
        break;

    case 4:
        printf("Digite o CPF do Cliente: ");
        scanf("%d" , cpf);
        c= consulta_cliente(cpf);
        if( c.cpf == -1) printf("Erro!");
        else {
            printf("Nome: %s", c.nome);
            printf("Data de Nascimento: %s", c.dataNasc);
            printf("CNH: %s", c.CNH);
            printf("Validade CNH: %s", c.valCNH);
            printf("Nacionalidade: %c", c.nacio);
            printf("Por questoes de seguranca, nao é possivel visualizar o RG e CPF do cliente!");
        }
    case 5:
        printf("Digite a placa do veiculo: ");
        scanf("%c ", pl);
        x = consulta_carro(pl);
        if(x.disp == 2) ("Erro!");
        else{
            printf("Modelo: %s", x.modelo);
            printf("Marca: %s", x.marca);
            printf("Ano: %d", x.ano);
            printf("Modelo: %s", x.placa);

            if(x.categoria == 'e' || x.categoria == 'E') printf("Categoria Economica.");
            if(x.categoria == 'i' || x.categoria == 'I') printf("Categoria Intermediaria.");
            if(x.categoria == 'l' || x.categoria == 'L') printf("Categoria Luxo.");

        }
    case 6:
        printf("Digite o CPF do cliente: ");
        scanf("%d ", cpf);
        r = consultar_locacao(cpf);
        if(r.cpf_cliente == -1) printf("Erro!");
        else{
            printf("Cliente: %s" , r.nome_cliente);
            printf("Placa do Carro: %s" , r.placa_locado);
            printf("Data da Locacao: %s ", r.data_locacao);
            printf("Data prevista de Devolucao: %s" , r.data_devolucao);

        }
    case 7:
        devolver_carro();
    }
return 0;
}
