#include "inv.h"

int get_index(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch-'a';
    }
    else if(ch>='A' && ch<='Z')5
    {
        return ch-'A';
    }
    return 26;
}

int create_db(file **f_head,hash_t *arr)
{
    if(*f_head==NULL)
    {
        return 0;
    }
    file *ftemp=*f_head;
    while(ftemp!=NULL)
    {
        FILE *fp=fopen(ftemp->filename,"r");
        if(fp==NULL)
        {
            ftemp=ftemp->f_link;
            continue;
        }
        while(1)
        {
            char word[100];
            if(fscanf(fp,"%s",word)!= 1)
            {
                fclose(fp);
                break;
            }
            int ind=get_index(word[0]);
            if(arr[ind].h_link==NULL)
            {
                main_t *new_m=malloc(sizeof(main_t));
                if(new_m==NULL)
                {
                    return 0;
                }
                new_m->word=strdup(word);
                new_m->f_count=1;
                new_m->m_link=NULL;
                sub *new_s=malloc(sizeof(sub));
                if(new_s==NULL)
                {
                    return 0;
                }
                new_s->fname=strdup(ftemp->filename);
                new_s->w_count=1;
                new_s->s_link=NULL;
                new_m->sub_link=new_s;
                arr[ind].h_link=new_m;
            }
            else
            {
                main_t *m_temp=arr[ind].h_link;
                main_t *m_prev=NULL;
                int found=0;
                while(m_temp!=NULL)
                {
                    if(strcmp(m_temp->word,word)==0)
                    {
                        found=1;
                        sub *s_temp=m_temp->sub_link;
                        sub *s_prev=NULL;
                        int sub_found=0;
                        while(s_temp!=NULL)
                        {
                            if(strcmp(s_temp->fname,ftemp->filename)==0)
                            {
                                s_temp->w_count++;
                                sub_found=1;
                                break;
                            }
                            s_prev=s_temp;
                            s_temp=s_temp->s_link;
                        }
                        if(sub_found==0)
                        {
                            sub *new_s=malloc(sizeof(sub));
                            if(new_s==NULL)
                            {
                                return 0;
                            }
                            new_s->fname=strdup(ftemp->filename);
                            new_s->w_count=1;
                            new_s->s_link=NULL;
                            s_prev->s_link=new_s;
                            m_temp->f_count++;
                        }
                        break;
                    }
                    m_prev=m_temp;
                    m_temp=m_temp->m_link;
                }
                if(found==0)
                {
                    main_t *new_m=malloc(sizeof(main_t));
                    if(new_m==NULL)
                    {
                        return 0;
                    }
                    new_m->word=strdup(word);
                    new_m->f_count=1;
                    new_m->m_link=NULL;
                    sub *new_s=malloc(sizeof(sub));
                    if(new_s==NULL)
                    {
                        return 0;
                    }
                    new_s->fname=strdup(ftemp->filename);
                    new_s->w_count=1;
                    new_s->s_link=NULL;
                    new_m->sub_link=new_s;
                    m_prev->m_link=new_m;
                }
            }
        }
        ftemp=ftemp->f_link;
    }
    return 1;
}