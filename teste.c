#include<stdio.h>
#include <stdio.h>
#include <conio.h>

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

int cadastra_carro(){

	Car car;
    FILE *arquivo;
    if ((arquivo = fopen("Cadastro_car.txt", "a+")) == NULL){
        printf("Ocorreu um erro na abertura do arquivo. \n");
        return false;
    }
    printf("Renavan carro:");
    fgets(car.renavan, 30, stdin);
    printf("Placa carro:");
    fgets(car.placa, 7, stdin);
    printf("Marca carro:");
    fgets(car.marca, 30, stdin);
    printf("Modelo carro:");
    fgets(car.modelo, 30, stdin);
    printf("Digite o ano: ");
    scanf("%d", &car.ano);
    printf("Cor carro:");
    fgets(car.cor, 30, stdin);
    printf("Categoria carro:");
    fgets(car.categoria, 30, stdin);
    car.disp = true;



	if(fwrite(&car, sizeof(struct Car), 1, arquivo) == 1){
       fclose(arquivo);
       return true;
	}else {
        fclose(arquivo);
        return false;
	}
}


int cadastra_cliente(){

    Client cliente;
    FILE *arquivo;
	if ((arquivo = fopen("Cadastro_cliente.txt", "a+")) == NULL){
        printf("Ocorreu um erro na abertura do arquivo. \n");
        return false;
    }
    printf("Nome: ");
    scanf("%s" , cliente.nome);
    printf("Data de Nascimento: ");
    getc(cliente.dataNasc);
    printf("CPF: ");
    scanf("%d", &cliente.cpf);
    printf("RG: ");
    scanf("%d", &cliente.rg);
    printf("CNH:");
    scanf("%d", &cliente.CNH);
    printf("Validade CNH: ");
    getc(cliente.valCNH);
    printf("Nacionalidade: ");
    getc(cliente.nacio);

	if(fwrite(&cliente, sizeof(struct Client), 1, arquivo) == 1){
		fclose(arquivo);
		return true;
	}else {
        fclose(arquivo);
        return false;
    }
}

Car consulta_carro(char placa[7]){ //consulta pela placa
	FILE *arquivo;
	Car aux, car;
    aux.disp = 2;
	if((arquivo = fopen("Cadastro_car.txt", "rb+")) == NULL)     {
        printf("\nErro ao abrir arquivo\n");
        return aux;
    }
    while(!feof(arquivo)){
        if(fread(&car, sizeof(struct Car),1, arquivo) == 1){
            if(strcmp(strupr(placa), strupr(car.placa)) == 0){
                return car;
            }
        }
    }
    return aux;
}

Client consulta_cliente(long int cpf){// consulta pelo cpf
    FILE *arquivo;
    Client cliente;
	if((arquivo = fopen("Cadastro_cliente.txt", "rb+")) == NULL) {
        printf("\nErro ao abrir arquivo\n");
        cliente.rg = -1;
        return cliente;
    }
   while(!feof(arquivo)){
		if(fread(&cpf, sizeof(struct Client),1, arquivo) == 1){
			if(cpf = cliente.cpf) return cliente;
        }
    }
    cliente.rg = -1;
    return cliente;
}
//arrumar consultar locacao, tem que retornar uma var do tipo locacao
Rent consultar_locacao(long int cpf){// pesquisa pelo cpf do locador
    FILE *arquivo;
    Rent locacao;
    if((arquivo = fopen("locar_veiculo.txt", "a+"   ))==NULL){
        printf("Ocorreu um erro na abertura do arquivo. \n");
        locacao.cpf_cliente = -1;
    }
    while(!feof(arquivo)){
        if(fread(&locacao, sizeof(struct Rent), 1 , arquivo)==1){
            if(cpf == locacao.cpf_cliente){
                return locacao;
            }
        }
    }
    locacao.cpf_cliente = -1;
}


int locar_veiculo(){
    Client cliente;
    Car carro;
    int cpf, edit;
    Rent locacao;
    Date data_loc;
    char placa[7];

    FILE *arquivo;
    if ((arquivo = fopen("locar_veiculo.txt", "a+")) == NULL){
        printf("Ocorreu um erro na abertura do arquivo. \n");
        return 0;
    }

    cliente = consulta_cliente(cpf);
    if(cliente.rg == -1){
        printf("Cliente nao encontrado");
        return 0;
    } else{
        printf("Digite a placa do carro desejado: ");
        getc(placa);
        carro = consulta_carro(placa);
        if(carro.disp == 2 ){
            printf("Carro nao encontrado!");
            return 0;

        }else if(carro.disp = true){
            printf("Digite a data de locacao**somente os numeros ;)**: ");
            scanf("%d %d %d",locacao.data_devolucao.dia,locacao.data_devolucao.mes,locacao.data_devolucao.ano);
            locacao.nome_cliente = cliente.nome;
            locacao.cpf_cliente = cliente.cpf;
            locacao.placa_locado = carro.placa;
            locacao.data_locacao = data_loc;
            locacao.finalizado = false;
            if(fwrite(&locacao, sizeof(struct Rent), 1, arquivo) == 1){
                edit = editar_carro(carro.placa);
                fclose(arquivo);
                printf("\nLocacao realizada.\n");
                return 1;
            }else{
                fclose(arquivo);
                printf("\nErro ao realizar locacao.\n");
                return 0;
            }
        }else printf("Veiculo indisponível!");
    }

}

int editar_carro(char placa[7]){
	FILE *arquivo;
	char *substring;
	int cont;
	Car carro;
	if ((arquivo = fopen("Cadastro_car","rb+")) == NULL){
        printf("Ocorreu um erro na abertura do arquivo. \n");
        return -1;
    }
	while(!feof(arquivo)){
        if(fread(&carro, sizeof(struct Car), 1, arquivo)==1){
                substring = strstr(strupr(carro.placa), strupr(placa));

        }
        cont++;
    }
        if(carro.disp == true) carro.disp = false;
        else carro.disp = true;
        fseek (arquivo, sizeof(struct Car) * cont, SEEK_SET);
        if(fwrite(&carro.disp, sizeof(struct Car), 1, arquivo) == 1) {
                fclose(arquivo);
                return 1;
        }else{
         fclose(arquivo);
         return -1;
        }
    }


void devolver_carro(){
    int valor, x;
    long int cpf;
    Date devolucao;
    char placa[7];
    printf("Digite a placa do Carro: ");
    getc(placa);
    printf("\nDigite o cpf: ");
    scanf("%d", cpf);
    printf("\nDigite a data da devolucao (somente os numeros)");
    scanf("%d %d %d",&devolucao.dia,&devolucao.mes,&devolucao.ano);
    valor = gerar_pagamento(placa, devolucao, cpf);
    printf("O valor final da locacao é de: %d", valor);
    x = editar_carro(placa); // carro colocado como disponi
}


float gerar_pagamento(char placa[7], Date devolucao, long int cpf){
    int dias, dias_atraso;
    float total;
    Rent aux;
    Car c;

    aux = consultar_locacao(cpf);
    c = consulta_carro(placa);
    dias = sbt_data(aux.data_devolucao, aux.data_locacao);
    dias_atraso = sbt_data(devolucao, aux.data_devolucao);

    if(c.categoria == 'e' || c.categoria == 'E'){
        total = (dias* 89.9) +(dias_atraso * 89.9 * 2);
    	return total;
	}
    if(c.categoria == 'i' || c.categoria == 'I'){
        total = (dias* 174.9) +(dias_atraso * 174.9 * 2);
    	return total;
	}
    if(c.categoria == 'l'|| c.categoria == 'L'){
	    total = (dias* 289.9) +(dias_atraso * 289.9 * 2);
	    return total;
    }
 }


 int sbt_data(Date devolucao, Date loc){
        int d, m, a;

        if(devolucao.dia >= loc.dia )
            d = devolucao.dia - loc.dia;
        else{
            devolucao.dia += 31; // considerando mes com 30 dias
            devolucao.mes -= 1;
            d = devolucao.dia - loc.dia;
        }

        if(devolucao.mes >= loc.mes)
            m = devolucao.mes - loc.mes;
        else{
            devolucao.mes +=12;
            devolucao.ano -= 1;
            m = devolucao.mes = loc.mes;
        }
        a = devolucao.ano - loc.ano;

        return d;
 }

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
        if(locar_veiculo() == 0) printf("Erro na Locacao!");
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












