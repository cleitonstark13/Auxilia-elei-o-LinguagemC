#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>
//ALGORÍTMO CRIADO POR CLEITON ALVES E SILVA JÚNIOR E LUCAS HENRIQUE SPIES//

////////////////////////////////////////////////////////// MENUS ///////////////////////////////////////////////////////////////////

void menu()
{
	printf("\n*-------------------------MENU--------------------------*");
	printf("\n| 1 - Deputado Estadual                                 |");
	printf("\n| 2 - Deputado Federal                                  |");
	printf("\n| 3 - Senador                                           |");
	printf("\n| 4 - Governador                                        |");
	printf("\n| 5 - Presidente                                        |");
	printf("\n| 6 - Sair                                              |");
	printf("\n|_______________________________________________________|");
	printf("\nIndique a opção desejada: ");
}

void menuPrincipal()
{
	printf("\n*-------------------------MENU--------------------------*");
	printf("\n| 1 - Para inserir um candidato                         |");
    printf("\n| 2 - Para remover um candidato                         |");
	printf("\n| 3 - Para alterar um candidato                         |");
	printf("\n| 4 - Para votar                                        |");
	printf("\n| 5 - Exibir lista de todos os candidatos               |");
	printf("\n| 6 - Exibir porcentagem de votos de um candidato       |");
	printf("\n| 7 - Sair!                                             |");
	printf("\n|_______________________________________________________|");
	printf("\nIndique a opção desejada: ");
}

/////////////////////////////////////////////////////////// PRESIDENTE /////////////////////////////////////////////////////////////

typedef struct
{
	char Nome[100];
	int Numero, Votos;
	float Porcentagem;
	struct Presidente *Prox;
}Presidente;

void InserirPresidente(Presidente *lista)
{
    Presidente *novo; 
    novo=malloc(sizeof(Presidente));
    system("cls");
    printf("*************************************************************************************\n");
    printf("*                              CADASTRO PRESIDENTE                                  *\n");
    printf("*************************************************************************************\n");
    printf("* Digite o nome do candidato: ");
    fflush(stdin);
    gets(novo->Nome);
    printf("* Indique o número do candidato: ");
    scanf("%d", &novo->Numero);
    printf("*************************************************************************************\n");
	printf("*                        CANDIDATO CADASTRADO COM SUCESSO!*                         *\n");
	printf("*************************************************************************************\n");
	printf("\n");
	system("Pause");
	system("cls");
    novo->Votos=0;
	novo->Prox=lista->Prox;
	lista->Prox=novo;
}

int SomaVotosPresidente(Presidente *lista)
{     
	Presidente *P;
	int Soma=0;
	P=lista->Prox;
	while(P->Prox!=NULL)
	{
		Soma+=P->Votos;
		P=P->Prox;
	}
	Soma+=P->Votos;
	return Soma;
}

int PorcentagemVotosPresidente(Presidente *lista)
{
	Presidente *P;
	P=lista->Prox;
	int Total, Aux, Teste=0;
	if(lista->Prox==NULL)
	{
		printf("Não há nenhum candidato cadastrado para este cargo.\n");
		system("Pause");
		system("cls");
		return 0;
	}
	while(Teste!=1)
	{	
		Total = SomaVotosPresidente(lista);
		printf("Digite o número do candidato desejado: ");
		scanf("%d",&Aux);
		while(P->Prox!=NULL)
		{
			P->Porcentagem=(float)P->Votos/Total;
			P=P->Prox;
		}
		P->Porcentagem=(float)P->Votos/Total;
		P=lista->Prox;
		while(P->Numero!=Aux&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero!=Aux)
		{
			printf("Digite um número válido\n");	
		}
		else
		{
			if(P->Votos==0)
			{
				printf("O candidato não possui votos.\n");
				Teste=1;
			}
			else
			{
				if(P->Votos!=0)
				{
					printf("A porcentagem de votos do candidato %s foi de %0.f%%\n",P->Nome,P->Porcentagem*100);
					Teste=1;
				}	
			}
		}
	}
	system("Pause");
	system("cls");
	return 1;
}

void ExibirPresidente(Presidente *inicio)
{
    Presidente *Exibir;
    float Total = 0;
    Exibir=inicio->Prox;
    printf("\n\t LISTA DE CANDIDATOS A PRESIDÊNCIA:\n");
    if(Exibir==NULL)
    {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    do{
    	Total = SomaVotosPresidente(inicio);
        printf("\t Nome do Candidato: %s | Número do candidato: %05d | Quantidade de votos: %d | Porcentagem de votos: %.2f% %\n", Exibir->Nome,Exibir->Numero,Exibir->Votos,(Exibir->Votos/Total)*100);
        printf("\t-------------------------------------------------\n");
        Exibir=Exibir->Prox;
    }while(Exibir!=NULL);
    system("Pause");
	system("cls");
    }
}

void RemoverPresidente(Presidente *inicio)
{
    int Pesquisar_Numero;
    Presidente *Remover;
    Presidente *anterior;
    Remover=inicio->Prox;
    anterior=inicio;
    if(Remover==NULL)
        {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    printf("Informe o número do candidato:");
    scanf("%d", &Pesquisar_Numero);
    do{
        if(Pesquisar_Numero == Remover->Numero)
        {
            printf("\t Candidato Removido: %s ", Remover->Nome);
            anterior->Prox=Remover->Prox;
            free(Remover);
            break;
        }
        else
            Remover=Remover->Prox;
            anterior=anterior->Prox;
        if(Remover==NULL)
            printf("Candidato não encontrado:\n");
    }while(Remover!=NULL);
	}
}

void VotarPresidente(Presidente *lista)
{
	Presidente *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	printf("\nPresidente\n");
	while(Teste==0)
	{	
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja votar:");
		scanf("%i",&Candidato);
		fflush(stdin);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			P->Votos++;
			Teste=1;
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
		}
		P=lista->Prox;
	}
	system("cls");
}

void AlterarPresidente(Presidente *lista)
{
	Presidente *P;
	P=lista->Prox;
	int Candidato=-1, Teste=0;
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja alterar:");
		scanf("%d",&Candidato);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			printf("Digite o novo nome: ");
			fflush(stdin);
			gets(P->Nome);
			printf("Digite o novo número: ");
			scanf("%i",&P->Numero);
			printf("Alteração feita!\n");
			Teste = 1;
			system("Pause");
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
			system("Pause");
		}
		P=lista->Prox;
	}
}

/////////////////////////////////////////////////////////// DEPUTADO FEDERAL ///////////////////////////////////////////////////////////////

typedef struct
{
	char Nome[100];
	int Numero, Votos;
	float Porcentagem;
	struct DepFederal *Prox;
}DepFederal;

void InserirDepFederal(DepFederal *lista)
{
    DepFederal *novo; 
    novo=malloc(sizeof(DepFederal));
    system("cls");
    printf("*************************************************************************************\n");
    printf("*                          CADASTRO DEPUTADO FEDERAL                                *\n");
    printf("*************************************************************************************\n");
    printf("* Digite o nome do candidato: ");
    fflush(stdin);
    gets(novo->Nome);
    printf("* Indique o número do candidato: ");
    scanf("%d", &novo->Numero);
    printf("*************************************************************************************\n");
	printf("*                        CANDIDATO CADASTRADO COM SUCESSO!*                         *\n");
	printf("*************************************************************************************\n");
	printf("\n");
    system("Pause");
	system("cls");
    novo->Votos=0;
	novo->Prox=lista->Prox;
	lista->Prox=novo;
}

int SomaVotosDepFederal(DepFederal *lista)
{     
	DepFederal *P;
	int Soma=0;
	P=lista->Prox;
	while(P->Prox!=NULL)
	{
		Soma+=P->Votos;
		P=P->Prox;
	}
	Soma+=P->Votos;
	return Soma;
}

int PorcentagemVotosDepFederal(DepFederal *lista)
{
	DepFederal *P;
	P=lista->Prox;
	int Total, Aux, Teste=0;
	if(lista->Prox==NULL)
	{
		printf("Não há nenhum candidato cadastrado para este cargo.\n");
		system("Pause");
		system("cls");
		return 0;
	}
	while(Teste!=1)
	{	
		Total = SomaVotosDepFederal(lista);
		printf("Digite o número do candidato desejado: ");
		scanf("%d",&Aux);
		while(P->Prox!=NULL)
		{
			P->Porcentagem=(float)P->Votos/Total;
			P=P->Prox;
		}
		P->Porcentagem=(float)P->Votos/Total;
		P=lista->Prox;
		while(P->Numero!=Aux&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero!=Aux)
		{
			printf("Digite um número válido\n");	
		}
		else
		{
			if(P->Votos==0)
			{
				printf("O candidato não possui votos.\n");
				Teste=1;
			}
			else
			{
				if(P->Votos!=0)
				{
					printf("A porcentagem de votos do candidato %s foi de %0.f%%\n",P->Nome,P->Porcentagem*100);
					Teste=1;
				}	
			}
		}
	}
	system("Pause");
	system("cls");
	return 1;
}

void ExibirDepFederal(DepFederal *inicio)
{
    DepFederal *Exibir;
    float Total = 0;
    Exibir=inicio->Prox;
    printf("\n\n\t LISTA DE CANDIDATOS A DEPUTADO FEDERAL:\n");
    if(Exibir==NULL)
    {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
    	system("Pause");
		system("cls");
    }
    else{
    do{
    	Total = SomaVotosDepFederal(inicio);
        printf("\t Nome do Candidato: %s | Número do candidato: %05d | Quantidade de votos: %d | Porcentagem de votos: %.2f% %\n", Exibir->Nome,Exibir->Numero,Exibir->Votos,(Exibir->Votos/Total)*100);
        printf("\t-------------------------------------------------\n");
        Exibir=Exibir->Prox;
    }while(Exibir!=NULL);
    system("Pause");
	system("cls");
    }
}

void RemoverDepFederal(DepFederal *inicio)
{
    int Pesquisar_Numero;
    DepFederal *Remover;
    DepFederal *anterior;
    Remover=inicio->Prox;
    anterior=inicio;
    if(Remover==NULL)
        {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    printf("Informe o número do candidato:");
    scanf("%d", &Pesquisar_Numero);
    do{
        if(Pesquisar_Numero == Remover->Numero)
        {
            printf("\t Candidato Removido: %s ", Remover->Nome);
            anterior->Prox=Remover->Prox;
            free(Remover);
            break;
        }
        else
            Remover=Remover->Prox;
            anterior=anterior->Prox;
        if(Remover==NULL)
            printf("Candidato não encontrado:\n");
    }while(Remover!=NULL);
	}
}

void VotarDepFederal(DepFederal *lista)
{
	DepFederal *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	printf("\nDeputado Federal\n");
	
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja votar:");
		scanf("%i",&Candidato);
		fflush(stdin);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			P->Votos++;
			Teste=1;
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
		}
		P=lista->Prox;
	}
	system("cls");
}

void AlterarDepFederal(DepFederal *lista)
{
	DepFederal *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
		while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja alterar:");
		scanf("%d",&Candidato);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			printf("Digite o novo nome: ");
			fflush(stdin);
			gets(P->Nome);
			printf("Digite o novo número: ");
			scanf("%i",&P->Numero);
			printf("Alteração feita!\n");
			Teste = 1;
			system("Pause");
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
			system("Pause");
		}
		P=lista->Prox;
	}
}

/////////////////////////////////////////////////////////// DEPUTADO ESTADUAL ///////////////////////////////////////////////////////////////

typedef struct
{
	char Nome[100];
	int Numero, Votos;
	float Porcentagem;
	struct DepEstadual *Prox;
}DepEstadual;

void InserirDepEstadual(DepEstadual *lista)
{
    DepEstadual *novo; 
    novo=malloc(sizeof(DepEstadual));
    system("cls");
    printf("*************************************************************************************\n");
    printf("*                          CADASTRO DEPUTADO ESTADUAL                               *\n");
    printf("*************************************************************************************\n");
    printf("* Digite o nome do candidato: ");
    fflush(stdin);
    gets(novo->Nome);
    printf("* Indique o número do candidato: ");
    scanf("%d", &novo->Numero);
    printf("*************************************************************************************\n");
	printf("*                        CANDIDATO CADASTRADO COM SUCESSO!*                         *\n");
	printf("*************************************************************************************\n");
	printf("\n");
    system("Pause");
	system("cls");
    novo->Votos=0;
	novo->Prox=lista->Prox;
	lista->Prox=novo;
}

int SomaVotosDepEstadual(DepEstadual *lista)
{     
	DepEstadual *P;
	int Soma=0;
	P=lista->Prox;
	while(P->Prox!=NULL)
	{
		Soma+=P->Votos;
		P=P->Prox;
	}
	Soma+=P->Votos;
	return Soma;
}

int PorcentagemVotosDepEstadual(DepEstadual *lista)
{
	DepEstadual *P;
	P=lista->Prox;
	int Total, Aux, Teste=0;
	if(lista->Prox==NULL)
	{
		printf("Não há nenhum candidato cadastrado para este cargo.\n");
		system("Pause");
		system("cls");
		return 0;
	}
	while(Teste!=1)
	{	
		Total = SomaVotosDepEstadual(lista);
		printf("Digite o número do candidato desejado: ");
		scanf("%d",&Aux);
		while(P->Prox!=NULL)
		{
			P->Porcentagem=(float)P->Votos/Total;
			P=P->Prox;
		}
		P->Porcentagem=(float)P->Votos/Total;
		P=lista->Prox;
		while(P->Numero!=Aux&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero!=Aux)
		{
			printf("Digite um número válido\n");	
		}
		else
		{
			if(P->Votos==0)
			{
				printf("O candidato não possui votos.\n");
				Teste=1;
			}
			else
			{
				if(P->Votos!=0)
				{
					printf("A porcentagem de votos do candidato %s foi de %0.f%%\n",P->Nome,P->Porcentagem*100);
					Teste=1;
				}	
			}
		}
	}
	system("Pause");
	system("cls");
	return 1;
}

void ExibirDepEstadual(DepEstadual *inicio)
{
    DepEstadual *Exibir;
    float Total = 0;
    Exibir=inicio->Prox;
    printf("\n\n\t LISTA DE CANDIDATOS A DEPUTADO ESTADUAL:\n");
    if(Exibir==NULL)
    {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    do{
    	Total = SomaVotosDepEstadual(inicio);
        printf("\t Nome do Candidato: %s | Número do candidato: %05d | Quantidade de votos: %d | Porcentagem de votos: %.2f% %\n", Exibir->Nome,Exibir->Numero,Exibir->Votos,(Exibir->Votos/Total)*100);
        printf("\t-------------------------------------------------\n");
        Exibir=Exibir->Prox;
    }while(Exibir!=NULL);
    system("Pause");
	system("cls");
    }
}

void RemoverDepEstadual(DepEstadual *inicio)
{
    int Pesquisar_Numero;
    DepEstadual *Remover;
    DepEstadual *anterior;
    Remover=inicio->Prox;
    anterior=inicio;
    if(Remover==NULL)
        {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    printf("Informe o número do candidato:");
    scanf("%d", &Pesquisar_Numero);
    do{
        if(Pesquisar_Numero == Remover->Numero)
        {
            printf("\t Candidato Removido: %s ", Remover->Nome);
            anterior->Prox=Remover->Prox;
            free(Remover);
            break;
        }
        else
            Remover=Remover->Prox;
            anterior=anterior->Prox;
        if(Remover==NULL)
            printf("Candidato não encontrado:\n");
    }while(Remover!=NULL);
	}
}

void VotarDepEstadual(DepEstadual *lista)
{
	DepEstadual *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	printf("\nDeputado Estadual\n");
	
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja votar:");
		scanf("%i",&Candidato);
		fflush(stdin);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			P->Votos++;
			Teste=1;
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
		}
		P=lista->Prox;
	}
	system("cls");
}

void AlterarDepEstadual(DepEstadual *lista)
{
	DepEstadual *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
		while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja alterar:");
		scanf("%i",&Candidato);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			printf("Digite o novo nome: ");
			fflush(stdin);
			gets(P->Nome);
			printf("Digite o novo número: ");
			scanf("%i",&P->Numero);
			printf("Alteração feita!\n");
			Teste = 1;
			system("Pause");
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
			system("Pause");
		}
		P=lista->Prox;
	}
}

/////////////////////////////////////////////////////////// GOVERNADOR //////////////////////////////////////////////////////////////////////

typedef struct
{
	char Nome[100];
	int Numero, Votos;
	float Porcentagem;
	struct Governador *Prox;
}Governador;

void InserirGovernador(Governador *lista)
{
    Governador *novo; 
    novo=malloc(sizeof(Governador));
    system("cls");
    printf("*************************************************************************************\n");
    printf("*                              CADASTRO GOVERNADOR                                  *\n");
    printf("*************************************************************************************\n");
    printf("* Digite o nome do candidato: ");
    fflush(stdin);
    gets(novo->Nome);
    printf("* Indique o número do candidato: ");
    scanf("%d", &novo->Numero);
    printf("*************************************************************************************\n");
	printf("*                        CANDIDATO CADASTRADO COM SUCESSO!*                         *\n");
	printf("*************************************************************************************\n");
	printf("\n");
    system("Pause");
	system("cls");
    novo->Votos=0;
	novo->Prox=lista->Prox;
	lista->Prox=novo;
}

int SomaVotosGovernador(Governador *lista)
{     
	Governador *P;
	int Soma=0;
	P=lista->Prox;
	while(P->Prox!=NULL)
	{
		Soma+=P->Votos;
		P=P->Prox;
	}
	Soma+=P->Votos;
	return Soma;
}

int PorcentagemVotosGovernador(Governador *lista)
{
	Governador *P;
	P=lista->Prox;
	int Total, Aux, Teste=0;
	if(lista->Prox==NULL)
	{
		printf("Não há nenhum candidato cadastrado para este cargo.\n");
		system("Pause");
		system("cls");
		return 0;
	}
	while(Teste!=1)
	{	
		Total = SomaVotosGovernador(lista);
		printf("Digite o número do candidato desejado: ");
		scanf("%d",&Aux);
		while(P->Prox!=NULL)
		{
			P->Porcentagem=(float)P->Votos/Total;
			P=P->Prox;
		}
		P->Porcentagem=(float)P->Votos/Total;
		P=lista->Prox;
		while(P->Numero!=Aux&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero!=Aux)
		{
			printf("Digite um número válido\n");	
		}
		else
		{
			if(P->Votos==0)
			{
				printf("O candidato não possui votos.\n");
				Teste=1;
			}
			else
			{
				if(P->Votos!=0)
				{
					printf("A porcentagem de votos do candidato %s foi de %0.f%%\n",P->Nome,P->Porcentagem*100);
					Teste=1;
				}	
			}
		}
	}
	system("Pause");
	system("cls");
	return 1;
}

void ExibirGovernador(Governador *inicio)
{
    Governador *Exibir;
    float Total = 0;
    Exibir=inicio->Prox;
    printf("\n\n\t LISTA DE CANDIDATOS A GOVERNADOR:\n");
    if(Exibir==NULL)
    {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    do{
		Total = SomaVotosGovernador(inicio);
        printf("\t Nome do Candidato: %s | Número do candidato: %05d | Quantidade de votos: %d | Porcentagem de votos: %.2f% %\n", Exibir->Nome,Exibir->Numero,Exibir->Votos,(Exibir->Votos/Total)*100);
        printf("\t-------------------------------------------------\n");
        Exibir=Exibir->Prox;
    }while(Exibir!=NULL);
    system("Pause");
	system("cls");
    }
}

void RemoverGovernador(Governador *inicio)
{
    int Pesquisar_Numero;
    Governador *Remover;
    Governador *anterior;
    Remover=inicio->Prox;
    anterior=inicio;
    if(Remover==NULL)
        {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    printf("Informe o número do candidato:");
    scanf("%d", &Pesquisar_Numero);
    do{
        if(Pesquisar_Numero == Remover->Numero)
        {
            printf("\t Candidato Removido: %s ", Remover->Nome);
            anterior->Prox=Remover->Prox;
            free(Remover);
            break;
        }
        else
            Remover=Remover->Prox;
            anterior=anterior->Prox;
        if(Remover==NULL)
            printf("Candidato não encontrado:\n");
    }while(Remover!=NULL);
	}
}

void VotarGovernador(Governador *lista)
{
	Governador *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	printf("\nGovernador\n");
	
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja votar:");
		scanf("%i",&Candidato);
		fflush(stdin);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			P->Votos++;
			Teste=1;
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
		}
		P=lista->Prox;
	}
	system("cls");
}

void AlterarGovernador(Governador *lista)
{
	Governador *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
		while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja alterar:");
		scanf("%i",&Candidato);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			printf("Digite o novo nome: ");
			fflush(stdin);
			gets(P->Nome);
			printf("Digite o novo número: ");
			scanf("%i",&P->Numero);
			printf("Alteração feita!\n");
			Teste = 1;
			system("Pause");
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
			system("Pause");
		}
		P=lista->Prox;
	}
}

/////////////////////////////////////////////////////////// SENADOR ////////////////////////////////////////////////////////////////////////

typedef struct
{
	char Nome[100];
	int Numero, Votos;
	float Porcentagem;
	struct Senador *Prox;
}Senador;

void InserirSenador(Senador *lista)
{
    Senador *novo; 
    novo=malloc(sizeof(Senador));
    system("cls");
    printf("*************************************************************************************\n");
    printf("*                                CADASTRO SENADOR                                   *\n");
    printf("*************************************************************************************\n");
    printf("* Digite o nome do candidato: ");
    fflush(stdin);
    gets(novo->Nome);
    printf("* Indique o número do candidato: ");
    scanf("%d", &novo->Numero);
    printf("*************************************************************************************\n");
	printf("*                        CANDIDATO CADASTRADO COM SUCESSO!*                         *\n");
	printf("*************************************************************************************\n");
	printf("\n");
  	system("Pause");
	system("cls");
    novo->Votos=0;
	novo->Prox=lista->Prox;
	lista->Prox=novo;
}

int SomaVotosSenador(Senador *lista)
{     
	Senador *P;
	int Soma=0;
	P=lista->Prox;
	while(P->Prox!=NULL)
	{
		Soma+=P->Votos;
		P=P->Prox;
	}
	Soma+=P->Votos;
	return Soma;
}

int PorcentagemVotosSenador(Senador *lista)
{
	Senador *P;
	P=lista->Prox;
	int Total, Aux, Teste=0;
	if(lista->Prox==NULL)
	{
		printf("Não há nenhum candidato cadastrado para este cargo.\n");
		system("Pause");
		system("cls");
		return 0;
	}
	while(Teste!=1)
	{	
		Total = SomaVotosSenador(lista);
		printf("Digite o número do candidato desejado: ");
		scanf("%d",&Aux);
		while(P->Prox!=NULL)
		{
			P->Porcentagem=(float)P->Votos/Total;
			P=P->Prox;
		}
		P->Porcentagem=(float)P->Votos/Total;
		P=lista->Prox;
		while(P->Numero!=Aux&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero!=Aux)
		{
			printf("Digite um número válido\n");	
		}
		else
		{
			if(P->Votos==0)
			{
				printf("O candidato não possui votos.\n");
				Teste=1;
			}
			else
			{
				if(P->Votos!=0)
				{
					printf("A porcentagem de votos do candidato %s foi de %0.f%%\n",P->Nome,P->Porcentagem*100);
					Teste=1;
				}	
			}
		}
	}
	system("Pause");
	system("cls");
	return 1;
}

void ExibirSenador(Senador *inicio)
{
    Senador *Exibir;
    float Total = 0.0;
    Exibir=inicio->Prox;
    printf("\n\n\t LISTA DE CANDIDATOS A SENADOR:\n");
    if(Exibir==NULL)
    {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{	
    do{	
		Total = SomaVotosSenador(inicio);
        printf("\t Nome do Candidato: %s | Número do candidato: %05d | Quantidade de votos: %d | Porcentagem de votos: %.2f% %\n", Exibir->Nome,Exibir->Numero,Exibir->Votos,(Exibir->Votos/Total)*100);       
        printf("\t-------------------------------------------------\n");
        Exibir=Exibir->Prox;
    }while(Exibir!=NULL);
    system("Pause");
	system("cls");
    }
}

void RemoverSenador(Senador *inicio)
{
    int Pesquisar_Numero;
    Senador *Remover;
    Senador *anterior;
    Remover=inicio->Prox;
    anterior=inicio;
    if(Remover==NULL)
        {
        printf("\t-------------------------------------------------\n");
        printf("\tRegistro Vazio\n");
        printf("\t-------------------------------------------------\n");
        system("Pause");
		system("cls");
    }
    else{
    printf("Informe o número do candidato:");
    scanf("%d", &Pesquisar_Numero);
    do{
        if(Pesquisar_Numero == Remover->Numero)
        {
            printf("\t Candidato Removido: %s ", Remover->Nome);
            anterior->Prox=Remover->Prox;
            free(Remover);
            break;
        }
        else
            Remover=Remover->Prox;
            anterior=anterior->Prox;
        if(Remover==NULL)
            printf("Candidato não encontrado:\n");
    }while(Remover!=NULL);
	}
}

void VotarSenador(Senador *lista)
{
	Senador *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	printf("\nSenador\n");
	
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja votar:");
		scanf("%i",&Candidato);
		fflush(stdin);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			P->Votos++;
			Teste=1;
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
		}
		P=lista->Prox;
	}
	system("cls");
}

void AlterarSenador(Senador *lista)
{
	Senador *P;
	int Candidato=-1, Teste=0;
	P=lista->Prox;
	while(Teste==0)
	{
		if(lista->Prox==NULL)
		{
			printf("\nNenhum candidato cadastrado para este cargo.\n");
			system("Pause");
			system("cls");
			break;
		}
		printf("\nDigite o número do candidato que deseja alterar:");
		scanf("%i",&Candidato);
		while(P->Numero!=Candidato&&P->Prox!=NULL)
		{
			P=P->Prox;
		}
		if(P->Numero==Candidato)
		{
			printf("Digite o novo nome: ");
			fflush(stdin);
			gets(P->Nome);
			printf("Digite o novo número: ");
			scanf("%i",&P->Numero);
			printf("Alteração feita!\n");
			Teste = 1;
			system("Pause");
		}
		else
		{
			printf("\nDigite um número de candidato válido!\n");
			system("Pause");
		}
		P=lista->Prox;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL,"Portuguese");
	printf("*----------------UNIVERSIDADE ESTADUAL DE GOIÁS--------------*\n");
	printf("|Profª: Hellen Matos                                         |\n");
	printf("|Disciplina: Estrutura de Dados I                            |\n");
	printf("|Alunos: Cleiton Alves e Silva Júnior e Lucas Henrique Spies |\n");
	printf("|____________________________________________________________|\n");
	
	Presidente *listaPresidente;
	DepFederal *listaDepFederal;
	DepEstadual *listaDepEstadual;
	Governador *listaGovernador;
	Senador *listaSenador;
    listaPresidente=malloc(sizeof(Presidente));
    listaPresidente->Prox=NULL;
    listaDepFederal=malloc(sizeof(DepFederal));
    listaDepFederal->Prox=NULL;
    listaDepEstadual=malloc(sizeof(DepEstadual));
    listaDepEstadual->Prox=NULL;
    listaGovernador=malloc(sizeof(Governador));
    listaGovernador->Prox=NULL;
    listaSenador=malloc(sizeof(Senador));
    listaSenador->Prox=NULL;
    
	int NumeroCandidato;
	int sair=1, Cont=0, TestePorcentagem=0;
    int posvalida;
    int op, opInserir, opRemover, opAlterar, opPorcentagemVotos, iniciar;
    printf("\nBEM VINDO AO PROGRAMA AUXILIAR ELEITORAL.\n");
    printf("\nDeseja Iniciar o programa de cadastro e pesquisa?");
    printf("\nDigite 1 para iniciar ou 0 para sair: ");
    char strIniciar[0];
    scanf("%d", &iniciar);
    fflush(stdin);
    while(iniciar == 1){
    system("cls");
	while(sair!=0)
	{
		menuPrincipal();
    	scanf("%d", &op);
    	fflush(stdin);
        switch(op)
        {
            case 1:{
            	system("cls");
            	int sairInserir = 1;
            	while(sairInserir != 0){
            	system("cls");
            	menu();
			    scanf("%d",&opInserir);
			    fflush(stdin);
			    switch(opInserir)
			    {

			    	case 1:
			    	{
			    		InserirDepEstadual(listaDepEstadual);
						break;
					}
					case 2:
					{
						InserirDepFederal(listaDepFederal);
						break;
					}
					case 3:
					{					
						InserirSenador(listaSenador);
						break;
					}
					case 4:
					{
						InserirGovernador(listaGovernador);
						break;
					}
					case 5:
					{
						InserirPresidente(listaPresidente);
						break;
					}
					case 6:
					{
						sairInserir = 0;
						break;
					}
				}
			}
			system("Pause");
    		system("cls");
    		break;
        }
            case 2:{
            	system("cls");
            	int sairRemover = 1;
            	while(sairRemover != 0){
            	system("cls");
                menu();
			    scanf("%d",&opRemover);
			    fflush(stdin);
			    switch(opRemover)
			    {
			    	case 1:
			    	{
			    		RemoverDepEstadual(listaDepEstadual);
						break;
					}
					case 2:
					{
						RemoverDepFederal(listaDepFederal);
						break;
					}
					case 3:
					{
						RemoverSenador(listaSenador);
						break;
					}
					case 4:
					{
						RemoverGovernador(listaGovernador);
						break;
					}
					case 5:
					{							
		    			RemoverPresidente(listaPresidente);
						break;
					}
					case 6:
					{
						sairRemover = 0;
						break;
					}
				}
			}
                system("Pause");
                system("cls");
                break;
            }
            case 3:{
            	system("cls");
            	int sairAlterar = 1;
            	while(sairAlterar != 0){
            	system("cls");
            	menu();
			    scanf("%d",&opAlterar);
			    fflush(stdin);
			    switch(opAlterar)
			    {
			    	case 1:
			    	{
			    		AlterarDepEstadual(listaDepEstadual);
			    		break;
					}
					case 2:
					{
						AlterarDepFederal(listaDepFederal);
						break;
					}
					case 3:
					{						
						AlterarSenador(listaSenador);
						break;
					}
					case 4:
					{
						AlterarGovernador(listaGovernador);
						break;
					}
					case 5:
					{	
						AlterarPresidente(listaPresidente);
						break;
					}
					case 6:
					{
						sairAlterar = 0;
						break;
					}
				}
			}
				system("Pause");
                system("cls");
                break;
            }
            case 4:{
            	system("cls");
            	printf("----------------------VOTAÇÃO------------------------\n");
            	VotarDepEstadual(listaDepEstadual);
            	fflush(stdin);
            	VotarDepFederal(listaDepFederal);
            	fflush(stdin);
            	VotarSenador(listaSenador);
            	fflush(stdin);
            	VotarGovernador(listaGovernador);
            	fflush(stdin);
                VotarPresidente(listaPresidente);
                fflush(stdin);
                printf("\nVOTAÇÃO FINALIZADA!\n");
                system("Pause");
                system("cls");
				break;
			}
            case 5:{
            	system("cls");
                ExibirDepEstadual(listaDepEstadual);
                ExibirDepFederal(listaDepFederal);
                ExibirSenador(listaSenador);
                ExibirGovernador(listaGovernador);                
                ExibirPresidente(listaPresidente);
                system("Pause");
                system("cls");
                break;
            }
            case 6:{
            	system("cls");
            	while(TestePorcentagem!=1)
				{
					system("cls");
					menu();
					char strP[0], opPorcentagemVotos;
				    scanf("%s",&strP[0]);
				    opPorcentagemVotos = strP[0];
				    fflush(stdin);
				    switch(opPorcentagemVotos)
				    {
				    	case '1':
				    	{
				    		TestePorcentagem=PorcentagemVotosDepEstadual(listaDepEstadual);
							break;
						}
						case '2':
						{						
							TestePorcentagem=PorcentagemVotosDepFederal(listaDepFederal);
							break;
						}
						case '3':
						{							
							TestePorcentagem=PorcentagemVotosSenador(listaSenador);
							break;
						}
						case'4':
						{						
							TestePorcentagem=PorcentagemVotosGovernador(listaGovernador);
							break;
						}
						case '5':
						{							
							TestePorcentagem=PorcentagemVotosPresidente(listaPresidente);
							break;
						}
						case '6':
						{
							TestePorcentagem=1;
							fflush(stdin);
							break;
						}
					}
				}
				TestePorcentagem=0;
				break;
            }
            case 7:{
                sair=0;
                iniciar = 0;
                break;
            }
        }
        system("cls");
    }
	}
	printf("\nPROGRAMA FINALIZADO COM SUCESSO!");
	return 0;
}
