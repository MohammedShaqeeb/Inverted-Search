/*DOCUMENTATION:
  NAME: N.MOHAMMED SHAQEEB
  REG_NO: 25031_124
  START_DATE: 27-04-2026
  END_DATE: 07-05-2026
  DESC: This is the Inverted Search Project using Hashtable to store and retrieve the details of specifc words in the files. Linked list is used along with hashtable to optimize the search.  
*/
#include "inv.h"

int validate(file **head,char *fname)
{
    int len=strlen(fname);
    if(len<5)
    {
        return 0;
    }
    if(strcmp(fname+(len-4),".txt")!=0)
    {
        return 0;
    }
    FILE *fp = fopen(fname, "r");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,0,SEEK_END);
    long size=ftell(fp);
    if(size==-1L)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    if (size==0)
    {
        return 0;
    }
    file *temp=*head;
    while(temp!=NULL)
    {
        if(strcmp(temp->filename,fname)==0)
        {
            return 0;
        }
        temp=temp->f_link;
    }
    file *new=malloc(sizeof(file));
    if (new == NULL)
    {
        return 0;
    }
    new->filename = strdup(fname);
    new->f_link=NULL;
    if(*head==NULL)
    {
        *head=new;
        return 1;
    }
    temp=*head;
    while(temp->f_link!=NULL)
    {
        temp=temp->f_link;
    }
    temp->f_link=new;
    return 1;
}

void create_HT(hash_t *HT, int size)
{
    for(int i=0;i<size;i++)
    {
        HT[i].index=i;
        HT[i].h_link=NULL;
    }
}

int main(int argc,char *argv[])
{
    if(argc<=1)
    {
        printf(YELLOW"INVALID INPUT!\n"RESET);
        printf(YELLOW"Usage: ./a.out <filename.txt> ... \n"RESET);
        return 0;
    }

    file *f_head=NULL;

    for(int i=1;i<argc;i++)
    {
        validate(&f_head,argv[i]);
    }

    hash_t arr[27];
	create_HT(arr, 27);

    int ch,create=0,update=0;
    while(1)
    {
        printf(BLUE"----------\nMAIN MENU:\n----------\n1. Create Database\n2. Search Database\n3. Display Database\n4. Save Database\n5. Update Database\n6. Exit\n----------\n"RESET);
        printf(WHITE"Choose the Option:"RESET);
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                if(create==0)
                {
                    if(update==1)
                    {
                        if(f_head==NULL)
                        {
                            printf(YELLOW"NO file to create!!!\n"RESET);
                        }
                        else
                        {
                            create_db(&f_head,arr);
                            create=1;
                            printf(GREEN"Database created successfully!\n"RESET);
                        }
                    }
                    else
                    {
                        create_db(&f_head,arr);
                        create=1;
                        printf(GREEN"Database created successfully!\n"RESET);
                    }
                }
                else
                {
                    printf(YELLOW"Create cannot be done again!!!\n"RESET);
                }
                break;
            }
            case 2:
            {
                search_db(arr);
                break;
            }
            case 3:
            {
                display_db(arr);
                break;
            }
            case 4:
            {
                save_db(arr);
                break;
            }
            case 5:
            {
                if(create==1)
                {
                    printf(YELLOW"Update cannot be done after create!!!\n"RESET);
                }
                else if(update==1)
                {
                    printf(YELLOW"Update cannot be done again!!!\n"RESET);
                }
                else
                {
                    update_db(&f_head,arr);
                    update=1;
                }
                break;
            }
            case 6:
            {
                delete_db(arr,&f_head);
                printf(GREEN"Exiting.....\n"RESET);
                exit(0);
            }
            default:
            {
                printf(RED"Invalid Choice! Choose a valid Operation!\n"RESET);
            }
        }
    }
}