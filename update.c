#include "inv.h"

int delete_file(file **f_head,char *fname)
{
    if(*f_head==NULL)
    {
        return -1;
    }
    file *temp=*f_head;
    file *prev=NULL;
    while(temp!=NULL)
    {
        if(strcmp(fname,temp->filename)==0)
        {
            if(temp==*f_head)
            {
                *f_head=temp->f_link;
                free(temp->filename);
                free(temp);
                return 0;
            }
            prev->f_link=temp->f_link;
            free(temp->filename);
            free(temp);
            return 0;
        }
        prev=temp;
        temp=temp->f_link;
    }
    return -1;
}

int update_db(file **f_head,hash_t *arr)
{
    char file[100];
    printf(WHITE"Enter the Backup File: "RESET);
    scanf("%s",file);
    int len=strlen(file);
    if(len<5)
    {
        printf(RED"Invalid File!\n"RESET);
        return -1;
    }
    if(strcmp(file+(len-4),".txt")!=0)
    {
        printf(RED"Invalid File Type!\n"RESET);
        return -1;
    }
    FILE *fp=fopen(file, "r");
    if(fp==NULL)
    {
        printf(YELLOW"Unable to open file!\n"RESET);
        return -1;
    }
    int ch=fgetc(fp);
    if(ch==EOF || ch!='#')
    {
        printf(RED"Invalid File!\n"RESET);
        fclose(fp);
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    int ind,f_ct;
    while(fscanf(fp,"#%d;%[^;];%d;",&ind,file,&f_ct)==3)
    {
        main_t *new_m=malloc(sizeof(main_t));
        if(new_m==NULL)
        {
            fclose(fp);
            return -1;
        }
        new_m->word=strdup(file);
        new_m->f_count=f_ct;
        new_m->m_link=NULL;
        new_m->sub_link=NULL;
        for(int i=0;i<f_ct;i++)
        {
            char fname[100];
            int w_ct;
            fscanf(fp,"%[^;];%d;",fname,&w_ct);
            delete_file(f_head,fname);
            sub *new_s=malloc(sizeof(sub));
            if(new_s==NULL)
            {
                fclose(fp);
                return -1;
            }
            new_s->fname=strdup(fname);
            new_s->w_count=w_ct;
            new_s->s_link=NULL;
            if(i==0)
            {
                new_m->sub_link=new_s;
            }
            else
            {
                sub *temp=new_m->sub_link;
                while(temp->s_link!=NULL)
                {
                    temp=temp->s_link;
                }
                temp->s_link=new_s;
            }
        }
        if(arr[ind].h_link==NULL)
        {
            arr[ind].h_link=new_m;
        }
        else
        {
            main_t *m_temp=arr[ind].h_link;
            while(m_temp->m_link!=NULL)
            {
                m_temp=m_temp->m_link;
            }
            m_temp->m_link=new_m;
        }
        fscanf(fp,"#\n");
    }
    fclose(fp);
    printf(GREEN"Database updated successfully!\n"RESET);
    return 0;
}