#include "candyshop.h"

void signup()
{
    char name[50];
    char lastname[50];
    char * namestr = NULL;
    char * lastnamestr = NULL;

    printf("Input your name: ");    
    scanf(" %s", name);
    printf("Input your last name: ");    
    scanf(" %s", lastname);

    namestr = malloc(sizeof(strlen(name)));
    lastnamestr = malloc(sizeof(strlen(lastname)));

    IsAllocated(namestr);
    IsAllocated(lastnamestr);

    strcpy(namestr,name);
    strcpy(lastnamestr,lastname);

    genCustommer(namestr,lastnamestr);

}

void signedIn(Shop * store)
{
    Custommer * custo = malloc(sizeof(Custommer));
    custo->last_purchase = malloc(sizeof(Article));

    int ans = 1; int index = -1;
    int purch;
    IsAllocated(custo);
    IsAllocated(custo->last_purchase);

    // printf("Faire last items bought");
    // searchArticle(int nb_articles, Article * products);

    // free(custo->last_purchase);
    // free(custo);
    while(ans==1)
    {
        printf("Would you like to buy any product 1- yes 2- no: ");
        scanf(" %d",&ans);
        if(ans == 1)
        {
            index = searchArticle(store->nb_articles,store->products);
            printf("How many pieces woulld you like to purchase\n");
            scanf(" %d",&purch);
            if(index<0)
            {
                printf("Your article doesn't exist please try again\n");
            } else if(store->products[index].quantity <1)
            {
                printf("\nWe ran out of the chosen product, please contact the manager\n");

            }else if(store->products[index].quantity - purch <1)
            {
                printf("\nOur stock of the product isn't enough to cover your demand\n");
            }
            else
            {
                purchaseItem(custo,store,index,purch);
            }
        }
        else
        {
            printf("have a great day");
            break;
        }

    }
    
    

}
void purchaseItem(Custommer * custo,Shop * store, int index, int amountPurchased)
{
    store->products[index].quantity -= amountPurchased;
    saveArticles(store->products,store->nb_articles);
    *(custo->last_purchase) = store->products[index];//seg fault here, Igue
    custo->last_purchase->quantity = amountPurchased;
    


}

void purchase(Shop * store)
{
    int answ = 3;
    char buffer[50];
    char * name = NULL;
    
    while(answ>=3 || answ<=0)
    {
        printf("\n1-sign up, 2-Login ");
        scanf(" %d",&answ);  
    }

    cleanbuffer();

    if(answ == 1)
    {
        signup();
        signedIn(store);
    }
    else
    {
        printf("\nInput your name and lastname: ");
        fgets(buffer,50,stdin);
        int i = 0;
        while(buffer[i]!='\n')
        {
            i++;
        }
        buffer[i]='\0';
        name = malloc(sizeof(strlen(buffer)));
        strcpy(name,buffer);
        fixname(name,strlen(name),' ','_');
        if(checkCustommerInDB(name) == 1)
        {
            signedIn(store);
        }
        
    }
}