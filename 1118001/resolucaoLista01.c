#include <stdio.h>
#include <stdlib.h>

struct elementos{
    struct elementos *rlink;
    struct elementos *llink;
    int key;
};

void mostraLista(struct elementos *H);

// Exercicio 01
struct elementos* insereElementoFim(struct elementos *H, struct elementos *x);
struct elementos* excluiElementoInicio(struct elementos *H);
struct elementos* excluiElementoFim(struct elementos *H);
struct elementos* trocaElementos(struct elementos *H, int x, int y);

// Exercicio 02
struct elementos* ordenacao(struct elementos *H);

// Exercicio 03
struct elementos* insercaoEmOrdem(struct elementos *H, struct elementos *x);

int totalElementos;

int main(){
    struct elementos *H, *x;
    int opc, temp, elementoX, elementoY;
    
    totalElementos = 0;
    
    H = malloc(sizeof (struct elementos));
    H->llink = H;
    H->rlink = H;
    
    do{
        printf("1 - Inserir elemento no fim da lista\n");
        printf("2 - Exlui elemento do início\n");
        printf("3 - Exlui elemento do fim\n");
        printf("4 - Trocar elementos\n");
        printf("5 - Mostrar dados da lista \n");
        printf("6 - Ordenacao bubblesort\n");
        printf("7 - Inserir na ordem\n");
        printf("8 - Sair\n");
        printf("Opcao?");
        scanf("%d", &opc);
        
        switch(opc){
            case 1:
                x = malloc(sizeof (struct elementos));
                
                printf("Digite o elemento para inserir:");
                scanf("%d", &x->key); 
                
                H = insereElementoFim(H, x);
                break;
            case 2:
                H = excluiElementoInicio(H);
                break;
            case 3:
                H = excluiElementoFim(H);
                break;
            case 4:
                printf("Elementos que deseja trocar de posicao:\n");
                printf("Trocar: ");
                scanf("%d", &elementoX);
                printf("Por: ");
                scanf("%d", &elementoY);
                trocaElementos(H, elementoX, elementoY);
                break;
            case 5:
                mostraLista(H);
                break;
            case 6:
                H = ordenacao(H);
                break; 
            case 7:
                x = malloc(sizeof (struct elementos));
                
                printf("Digite o elemento para inserir:");
                scanf("%d", &x->key); 
                H = insercaoEmOrdem(H, x);
                break;
        }
    } while (opc != 8);
    
    
    
    
    return 0;
}

void mostraLista(struct elementos *H){
    struct elementos *temp;
    int i = 1;
    
    
    if(H->llink == H->rlink && H->rlink == H){
        printf("Lista vazia\n");
        return;
    }
    
    temp = malloc(sizeof (struct elementos));
    
    printf("\n\n Elementos da lista\n");
    temp = H->rlink;
    do{
        printf("## Elemento %i: %d\n", i, temp->key);
        temp = temp->rlink;
        i++;
    }while (temp != H);
    printf("\n\n");
  /*  for(temp = H; temp->rlink != H; temp = temp->rlink){
        printf("Elemento: %d\n", temp->key);
    }*/
}

// 1.1
struct elementos* insereElementoFim(struct elementos *H, struct elementos *x){
    
    if(H->llink == H->rlink && H->rlink == H){
        printf("\n ## Lista vazia - primeiro elemento será inserido \n");
        // Lista vazia
        x->rlink = H->rlink;
        x->llink = H;
        H->rlink = x;
        H->llink = x;
        //H = x;
    }else {
        if (H->rlink != H){
            H->llink->rlink = x;
            x->rlink = H;
            x->llink = H->llink;
            H->llink = x;
        }                
    }
    totalElementos++;
    return H;
} 

// 1.2
struct elementos* excluiElementoInicio(struct elementos *H){

    if(H->llink == H->rlink && H->rlink == H){
        printf("Lista vazia");
    } else{
        if (H->rlink == H){
            // Um elemento na lista
            H->rlink = H;
            H->llink= H;
        }else {
            printf("\n ##Elemento que será excluido: %d\n", H->rlink->key);
            H->llink->rlink = H->rlink;
            H->rlink->llink = H->llink;
            H = H->rlink;   
        }
    }
    totalElementos--;
    return H;
}

// 1.3
struct elementos* excluiElementoFim(struct elementos *H){
    
    if(H->llink == H->rlink && H->rlink == H){
        printf("Lista vazia");
    } else{
        if (H->rlink == H){
            // Um elemento na lista
            H->rlink = H;
            H->llink= H;
        } else {
            printf("\n ##Elemento que será excluido: %d\n", H->llink->key);
            H->llink->llink->rlink = H;
            H->llink = H->llink->llink;
            //H->llink->rlink = H->rlink;
            //H->llink = H->llink->llink;            
        }
    }
    totalElementos--;
    return H;
}


// 1.4
struct elementos* trocaElementos(struct elementos *H, int x, int y){
    struct elementos *temp, *temp2;
    int aux;
    
    if(H->llink == H->rlink && H->rlink == H){
        printf("Lista vazia\n");
        return H;
    }
    
    temp = malloc(sizeof (struct elementos));
    temp2 = malloc(sizeof (struct elementos));
    
    temp = H->rlink;
    do{
        if(temp->key == x){

            // Encontrado o x
            temp2 = H->rlink;
            do{
                if(temp2->key == y){
                    // Encontrado o y
                    aux = temp->key;
                    temp->key = temp2->key;
                    temp2->key = aux;
                    printf("\n\n # Troca efetuada com sucesso \n");
                    return H;
                }
                temp2 = temp2->rlink;
            }while (temp != H);
        }
        temp = temp->rlink;
    }while (temp != H);
    printf("\n\n # Itens não encontrados para realizar a troca\n\n");
    
    free(temp);
    free(temp2);
}

struct elementos* ordenacao(struct elementos *H){
    struct elementos *temp, *temp2;
    int aux, i = 0, j = 0;
    
    if(H->llink == H->rlink && H->rlink == H){
        printf("Lista vazia\n");
        return H;
    }
    
    temp = malloc(sizeof (struct elementos));
    
    printf("totalElementos: %i\n", totalElementos);
    while (i < (totalElementos - 1)){
        temp = H->rlink;
        temp2 = temp->rlink;
        j = 0;
        while (j < (totalElementos - 1)){
            printf("temp->key: %i\n", temp->key);
            printf("temp2->key: %i\n", temp2->key);
            if(temp->key > temp2->key){
                aux = temp->key;
                temp->key = temp2->key;
                temp2->key = aux;
            }
            temp = temp->rlink;
            temp2 = temp2->rlink;
            j++;
        }
        i++;
    }
        
    mostraLista(temp->rlink);
    
    H = temp->rlink;
    
    return H;
}

struct elementos* insercaoEmOrdem(struct elementos *H, struct elementos *x){
    struct elementos *temp;
    int aux, i = 0, j = 0;
    
    if(H->llink == H->rlink && H->rlink == H){
        H->rlink = x;
        H->llink = x;
        x->llink = H;
        x->rlink = H;
        return H;
    }
    
    temp = malloc(sizeof (struct elementos));
    
    temp = H->rlink;
    
    while (temp != H){
        if(temp->key >= x->key){
            temp->rlink->llink = x;
            x->rlink = temp->rlink;
            temp->llink = x;
            x->llink = temp;
        }
        temp = temp->rlink;
    }
    
    //H = temp;
    return H; 
}
