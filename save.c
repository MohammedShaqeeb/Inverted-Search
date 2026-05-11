#include "inv.h"

void save_db(hash_t *arr)
{
    char file[100];
    printf(WHITE"Enter the Backup File: "RESET);
    scanf("%s",file);
    int len=strlen(file);
    if(len<5)
    {
        printf(RED"Invalid File!\n"RESET);
        return ;
    }
    if(strcmp(file+(len-4),".txt")!=0)
    {
        printf(RED"Invalid File Type!\n"RESET);
        return ;
    }
    FILE *fptr=fopen(file,"w");
    if(fptr==NULL)
    {
        printf(YELLOW"Unable to create file!\n"RESET);
        return;
    }
    for(int i=0;i<27;i++)
    {
        if(arr[i].h_link==NULL)
        {
            continue;
        }
        main_t *m_temp=arr[i].h_link;
        while(m_temp!=NULL)
        {
            fprintf(fptr,"#%d;%s;%d;",i,m_temp->word,m_temp->f_count);
            sub *s_temp=m_temp->sub_link;
            while(s_temp!=NULL)
            {
                fprintf(fptr,"%s;%d;",s_temp->fname,s_temp->w_count);
                s_temp=s_temp->s_link;
            }
            fprintf(fptr,"#\n");
            m_temp=m_temp->m_link;
        }  
    }
    printf(GREEN"Backup saved successfully!\n"RESET);
    fclose(fptr);
}