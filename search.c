#include "inv.h"

int search_db(hash_t *arr)
{
    char word[100];
    printf(WHITE"Enter the Word to be found: "RESET);
    scanf("%s",word);
    int ind=get_index(word[0]);
    if(arr[ind].h_link==NULL)
    {
        printf(YELLOW"Word not found!!\n"RESET);
        return -1;
    }
    main_t *m_temp=arr[ind].h_link;
    while(m_temp!=NULL)
    {
        if(strcmp(m_temp->word,word)==0)
        {
            printf(GREEN"%s"RESET" is present in" YELLOW" %d"RESET" files!\n",m_temp->word,m_temp->f_count);
            sub *s_temp=m_temp->sub_link;
            while(s_temp!=NULL)
            {
                printf("->"GREEN" %s" RESET" has "YELLOW"%d"RESET" occurences\n",s_temp->fname,s_temp->w_count);
                s_temp=s_temp->s_link;
            }
            return 0;
        }
        m_temp=m_temp->m_link;
    }
    printf(RED"Word not found!!\n"RESET);
    return -1;
}
