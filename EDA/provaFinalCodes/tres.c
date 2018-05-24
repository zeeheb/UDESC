#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // bool no C

struct NO_struct
  {
    int *pt_nome; // para prova simplesmente int conteudo;
    struct NO_struct *next;
  };

typedef struct NO_struct  NOH_tipo_LSE;

NOH_tipo_LSE * cria_no(void);
void imp_lista(NOH_tipo_LSE *L);
void  ins_fim_lista  (int *pt_ENTRADA, NOH_tipo_LSE **L);
void ins_inic_lista (int *pt_ENTRADA, NOH_tipo_LSE **L);
void ins_fim_lista_2(int *pt_ENTRADA, NOH_tipo_LSE **L);
void destroi_lista( NOH_tipo_LSE **L );
int comprimento_lista( NOH_tipo_LSE **L );
int exclui_n_esimo_lista( int n, NOH_tipo_LSE **L );
void inclui_n_esima_lista( int n, int *pt_DADO, NOH_tipo_LSE **L );
int exclui_o_ultimo_lista(  NOH_tipo_LSE **header_L );
bool esta_vazia( NOH_tipo_LSE **L );
int recurs_comp_lista_1( NOH_tipo_LSE *L );
int recurs_comp_lista_2( NOH_tipo_LSE **L );



int main(void) {
int entrada[100];
int i, j, temp, count=0;
int countpar, countimp;
NOH_tipo_LSE * L;
L = NULL;
NOH_tipo_LSE * LC;
LC = NULL;
for(i=0;i<100;i++) {
  scanf("%d", entrada+i);
    switch (entrada[i]) {
      case -1: i = 99;
               break;
      default : if(entrada[i]%2 == 0){
                    countpar++; break;
                }  else {
        countimp++; break; }

    }
    count++;
}
  int pares[countpar], impar[countimp];
  for(i=0;i<count;i++) {
    if(entrada[i] % 2 == 0) {
      pares[i] = entrada[i];
    } else {
      impar[i] = entrada[i];
    }

      // ordenando os pares
        for(i=0;i<count;i++){
          for(j=0;j<count;j++){
            if(pares[i] < pares[j]) {
              temp = pares[i];
              pares[i] = pares[j];
              pares[j] = temp;
            }
          }
        }

        // ordenando os impares

        for(i=0;i<count;i++){
          for(j=0;j<count;j++){
            if(impar[i] > impar[j]) {
              temp = impar[i];
              impar[i] = impar[j];
              impar[j] = temp;
            }
          }
        }

  }

  for(i=0;i<countpar;i++) {
    ins_fim_lista_2(&(pares[i]), &L);
  }
  for(i=countpar;i<countpar+countimp;i++) {
    ins_fim_lista_2(&(impar[i]), &L);
  }



  imp_lista(LC);


  return 0;
}


NOH_tipo_LSE * cria_no(void)
{
 NOH_tipo_LSE  *new_node;
 new_node = (NOH_tipo_LSE *) malloc(sizeof(NOH_tipo_LSE)) ;

 if( new_node == NULL)
	{
		printf("\n Erro de alocacao .... falta memoria!");
		getchar();
		exit(1);
	}
	return(new_node);
}




void imp_lista(NOH_tipo_LSE *L)
{
  int i=1;
  do {
	  printf("%d ", *( L -> pt_nome));
	   // cuidar aqui ...
	  //printf("distancia entre nos: %X \n", p->lista - p->lista->prox);
	  L = L -> next;
      i++;
	} while( L != NULL );

	return;
}

void ins_inic_lista(int *pt_DADO, NOH_tipo_LSE ** head)
{
    NOH_tipo_LSE * new_node;
    new_node = (NOH_tipo_LSE *) malloc(sizeof(NOH_tipo_LSE));

    new_node  -> pt_nome = pt_DADO;
    new_node -> next = (*head);// para o lugar onde head estava
    (*head) = new_node ;
}

void ins_fim_lista(int *pt_DADO, NOH_tipo_LSE ** L)
 { // insere ao final da lista

    if( (*L) == NULL ) // caso L nao esteja enderecado a lugar algum
    {
		NOH_tipo_LSE * novo_no = cria_no ();
		(*L) = novo_no;
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
	}
    else
    {
    	NOH_tipo_LSE * novo_no , * aux ;
	    aux = (*L); // inicio da lista
		for( ; aux -> next != NULL ; )
			aux = aux -> next ;

		novo_no = cria_no ();   /* CRIA ==> ALOCA */
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente como ultimo */
		aux -> next = novo_no; // atualiza o ultimo em L
	}
}
void ins_fim_lista_2(int *pt_DADO,  NOH_tipo_LSE **L )
 {
  if( (*L) == NULL ) // caso L nao esteja enderecado a lugar algum
    {
		NOH_tipo_LSE * novo_no = cria_no ();
		(*L) = novo_no;
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
		return ;
	}
    else
    {
    	NOH_tipo_LSE * novo_no , * aux ;
	    aux = (*L); // inicio da lista
		for( ; aux -> next != NULL ; )
			aux = aux -> next ;

		novo_no = cria_no ();   /* CRIA ==> ALOCA */
		novo_no  -> pt_nome = pt_DADO;
		novo_no -> next = NULL; /* INSTANCIA  inicialmente o ultimo */
		aux -> next = novo_no; // modifica em L
		return ;
	}
}

bool esta_vazia( NOH_tipo_LSE **L )
	{
		return(  (*L) == NULL  );
	}

int is_last( NOH_tipo_LSE *L )
{
	return( L->next == NULL );
}

void destroi_lista( NOH_tipo_LSE **L )
  {
   if( (*L) != NULL )
  	 { int i=1;
  	   NOH_tipo_LSE  * aux , *prox;
  	   aux =(*L);
	  	  while( aux -> next != NULL )
	  	  {
		  	prox = aux -> next;
		  	free(aux); // AQUI LIBERA aux
		  	aux = prox;
	      	i++;
		  } ;

       free( aux ); // PARA O ULTIMO NO
       printf("\n Total de nosh liberados: %d ", i );
       printf("\n LISTA LIBERADA OK\n " );

       return;
       }

     else
     {
        printf("\n LISTA VAZIA ... NADA a LIBERAR \n" );
        return;
     }

  }


//
int comprimento_lista( NOH_tipo_LSE **L )
  {
   if( (*L) == NULL )
   return 0;

    int i=1; // UM NO
  	   NOH_tipo_LSE  * aux ;
  	   aux =(*L);
       for(aux =(*L) , i=1;
            ( aux -> next != NULL ) ;
            aux = aux -> next, i++);

       return i;

  }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int recurs_comp_lista_1( NOH_tipo_LSE *L )
  {
   if( L == NULL )
   return 0;
   else
   return ( 1 + recurs_comp_lista_1( L-> next )  );
  }

int recurs_comp_lista_2( NOH_tipo_LSE **L )
  {
   if( (*L) == NULL )
   return 0;
   else
   {
    (*L) = (*L)-> next;
    return ( 1 + recurs_comp_lista_2( &(*L) ));
   }
 }

int exclui_n_esimo_lista( int n, NOH_tipo_LSE **L )
  {
   if( n > comprimento_lista( L ) || n < 1)
   {
	  printf("\n Erro na exclusao da n-esima posicao ... INVALIDA=>  %d", n);
	  getchar();
	}
    int aux;
    int i=1; // UM NO
  	NOH_tipo_LSE  * corrente , *anterior;
  	corrente = anterior = (*L);

	if( n == 1) // caso do 1o. da lista
   	{
      aux = *(corrente->pt_nome);
      (*L) = corrente -> next;
      free(corrente);
      return aux;
	}
    while( i < n ) // avancar ate o noh em questao
	 {
	   anterior = corrente;
	   corrente = corrente -> next ; // avanca
	    i++;
	 } ;

    anterior -> next = corrente -> next ;
    aux = *(corrente->pt_nome);

    free(corrente);
    return aux;

  }

int exclui_o_ultimo_lista(  NOH_tipo_LSE **header_L )
 {
   int posicao_ultimo = comprimento_lista( &(*header_L) );
   return ( exclui_n_esimo_lista( posicao_ultimo , &(*header_L) ));
 }



void inclui_n_esima_lista( int n, int *pt_DADO, NOH_tipo_LSE **head_L )
  {

   if( n > comprimento_lista( head_L ) || n < 1)
   {
	  printf("\n Erro na inclusao .... posicao INVALIDA!");
	  getchar();

	}

    int i=1; // UM NO
    NOH_tipo_LSE * new_node;
    new_node = (NOH_tipo_LSE *) malloc(sizeof(NOH_tipo_LSE));

  	NOH_tipo_LSE  * corrente , *anterior;
  	corrente = anterior = (*head_L);

	if( n == 1) // caso do 1o. da lista
   	{
     new_node  -> pt_nome = pt_DADO;
     new_node -> next = (*head_L);
     (*head_L) = new_node ; // atualiza head
	}
    while( i < n ) // avancar ate o no em questao
	 {
	   anterior = corrente;
	   corrente = corrente -> next ; // avanca
       i++;
	 } ;

    new_node  -> pt_nome = pt_DADO;
    anterior -> next = new_node ;
    new_node -> next = corrente ;


}
