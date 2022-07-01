#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char * nome;
    int id;
    int nivel;
    char * tipo;
    char * atk1;
    char * atk2;
    char * atk3;
    char * atk4;
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void Add_Poke(char * nome, int id, int nivel, char * tipo, char * atk1, char * atk2, char * atk3, char * atk4){

        NO * novo = malloc(sizeof(NO));
        novo->nome = nome;
        novo->id = id;
        novo->nivel = nivel;
        novo->tipo = tipo;
        novo->atk1 = atk1;
        novo->atk2 = atk2;
        novo->atk3 = atk3;
        novo->atk4 = atk4;
        
        novo->prox = NULL;
    
        if(inicio == NULL){
            inicio = novo;
            fim = novo;
           
        }else if(novo->nivel >= inicio->nivel){
            novo->prox = inicio;
            inicio = novo;
         
        }else if(novo->nivel <= fim->nivel){
            fim->prox = novo;
            fim = novo;
          
        }else{ 
            
            NO * aux = inicio;
            
            while(aux->prox->nivel > novo->nivel){
           
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            
        }
        
    tam++;

}


void visualizar(){
    NO * aux = inicio;
    printf("\nPOKEMON QUE VOCÊ POSSUI ORDENADOS POR NIVEL:\n");
    for(int i = 0; i < tam; i++){
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Nível: %d\n", aux->nivel);
        printf("Tipo: %s\n", aux-> tipo);
        printf("Ataques:\n1-%s\n2-%s\n3-%s\n4-%s\n", aux->atk1, aux-> atk2,aux-> atk3, aux-> atk4 );
        printf("\n");
        aux = aux->prox;
    }
}

NO Free_Poke(int id){
  
        NO *lixo;
        if(inicio->id == id){ 
            
            lixo = inicio;
            inicio = inicio->prox;
            if(tam == 1){
                fim = NULL;
            }
            
        }else { 
            
            NO * aux = inicio;
            while(aux->prox != NULL && aux->prox->id != id){
              
                aux = aux->prox;
            
            }
            
            if(aux->prox != NULL){
                lixo = aux->prox;
                aux->prox = aux->prox->prox;
                if(lixo->prox == NULL){
                    fim = aux;
                }
            }
          
        }
        NO dados;
        if(lixo != NULL){
            dados.nome = lixo->nome;
            dados.nivel = lixo->nivel;
            dados.tipo = lixo->tipo;
            dados.id = lixo->id;
            dados.atk1 = lixo->atk1;
            dados.atk2 = lixo->atk2;
            dados.atk3 = lixo->atk3;
            dados.atk4 = lixo->atk4;
            
            free(lixo);
            tam--;
            
        }
            return dados ;
           
        
}


void up(int id, int nivel){

    NO * aux = inicio;
    while(aux->id != id){
     
        aux = aux->prox;
    }
  
    aux->nivel = aux->nivel + nivel;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);
}

void down(int id, int nivel){
    
    NO * aux = inicio;
    while(aux->id != id){
        aux = aux->prox;
    }

    aux->nivel = aux->nivel - nivel;

    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);
}

void nome(int id, char * nome){

    NO * aux = inicio;
    while(aux->id != id){
       
        aux = aux->prox;
    }
    
    aux->nome = nome;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);

}

void atk1(int id, char * atk1){

    NO * aux = inicio;
    while(aux->id != id){
        
        aux = aux->prox;
    }

    aux->atk1 = atk1;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);

}
void atk2(int id, char * atk2){

    NO * aux = inicio;
    while(aux->id != id){

        aux = aux->prox;
    }
    
   
    aux->atk2 = atk2;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);

}
void atk3(int id, char * atk3){

    NO * aux = inicio;
    while(aux->id != id){
      
        aux = aux->prox;
    }
    
    
    aux->atk3 = atk3;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);

}

void atk4(int id, char * atk4){

    NO * aux = inicio;
    while(aux->id != id){
      
        aux = aux->prox;
    }
    
    aux->atk4 = atk4;
    
    NO dados = Free_Poke(id);
    Add_Poke(dados.nome, dados.id, dados.nivel, dados.tipo, dados.atk1, dados.atk2, dados.atk3, dados.atk4);

}
