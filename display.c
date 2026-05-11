#include "inv.h"

void display_db(hash_t *arr)
{
    int empty = 1;
    for(int i=0;i<27;i++)
    {
        if(arr[i].h_link != NULL)
        {
            empty = 0;
            break;
        }
    }

    if(empty)
    {
        printf(RED"Database is empty!\n"RESET);
        return;
    }

    printf(GREEN"--------------------------------------------------------------------------\n"RESET);
    printf(GREEN"%-6s %-15s %-12s %-20s %-10s\n"RESET,"Index", "Word", "FileCount", "Filename", "WordCount");
    printf(GREEN"--------------------------------------------------------------------------\n"RESET);
    for(int i=0;i<27;i++)
    {
        if(arr[i].h_link==NULL)
        {
            continue;
        }
        main_t *m_temp=arr[i].h_link;
        while(m_temp!=NULL)
        {
            printf(GREEN"%-6d %-15s %-12d %-20s %-10s\n"RESET,i,m_temp->word,m_temp->f_count,"","");
            sub *s_temp=m_temp->sub_link;
            while(s_temp!=NULL)
            {
                printf(YELLOW"%-6s %-15s %-12s %-20s %-10d\n"RESET,"", "", "",s_temp->fname,s_temp->w_count);
                s_temp=s_temp->s_link;
            }
            printf(GREEN"--------------------------------------------------------------------------\n"RESET);
            m_temp=m_temp->m_link;
        }  
    }
}
