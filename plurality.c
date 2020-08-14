#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9


typedef struct
{
    string name;
    int votes;
}
candidate;


candidate candidates[MAX];
int candidate_count;


bool vote(string name);
void print_winner(void);


int main(int argc, string argv[])
{

    if (argc < 2)           // Check for invalid usage
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }


    candidate_count = argc - 1;     // Populate array of candidates


    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }


    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }


    int voter_count = get_int("Number of voters: ");


    for (int i = 0; i < voter_count; i++)           // Loop over all voters
    {

        string name = get_string("Vote: ");

        if (!vote(name))                // Check for invalid vote
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();     // Display winner of election
}



bool vote(string name)      // Update vote totals given a new vote
{
    for (int i = 0; i < candidate_count; i++)
    {

        if (strcmp(name, candidates[i].name) == 0)
        {

            candidates[i].votes++;
            return true;

        }
    }
    return false;
}



void print_winner(void)     // Print the winner of the election
{

    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)       // Find winner
    {

        if (candidates[i].votes >= max_votes)
        {

            max_votes = candidates[i].votes;

        }
    }

    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[i].votes == max_votes)
        {

            printf("%s\n", candidates[i].name);

        }
    }
    return;
}


