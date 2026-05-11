#include "inv.h"

void delete_db(hash_t *arr,file **head)
{
    file *f_temp=*head;
    file *f_next=NULL;
    while(f_temp!=NULL)
    {
        f_next=f_temp->f_link;
        free(f_temp->filename);
        free(f_temp);
        f_temp=f_next;
    }
    *head=NULL;

    for(int i=0;i<27;i++)
    {
        main_t *m_temp=arr[i].h_link;
        main_t *m_next=NULL;
        while(m_temp!=NULL)
        {
            sub *s_temp=m_temp->sub_link;
            sub *s_next=NULL;
            while(s_temp!=NULL)
            {
                free(s_temp->fname);
                s_next=s_temp->s_link;
                free(s_temp);
                s_temp=s_next;
            }
            free(m_temp->word);
            m_next=m_temp->m_link;
            free(m_temp);
            m_temp=m_next;
        }
        arr[i].h_link=NULL;
    }

    printf(GREEN"Database deleted successfully\n"RESET);
}