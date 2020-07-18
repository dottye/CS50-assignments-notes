#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
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

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // linear search: loop through the candidates array to find matching name param;
    // if found, update int votes property and return true; else return false
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)    //(candidates[i].name == name)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    /*
    1. Uses bubble sort to order array of candidates in greatest to least order
    2. Prints the name of first candidate in array (greatest)
    3. Loops through remaining array
        If the i'th candidate's votes is different from (less than) the 0'th candidate's votes,
            exit program
        else (if votes are tied)
            print name of i'th candidate
    */

    // bubble sort: FIXED
    for (int i = 0; i < candidate_count - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < candidate_count - i - 1; j++)
        {
            if (candidates[j].votes < candidates[j + 1].votes)
            {
                candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
    // visualization aid: print array of candidates
    // printf("\nAll candidates:\n");
    // for (int k = 0; k < candidate_count; k++)
    // {
    //     printf("%s %i\n", candidates[k].name, candidates[k].votes);
    // }
    // printf("\n");


    // print winner(s): print first person in array
    // if next person's vote value is different from that of the first, also print next
    // repeat until we hit a different vote value
    printf("%s\n", candidates[0].name);
    for (int a = 1; a < candidate_count; a++)
    {
        if (candidates[a].votes != candidates[0].votes)
        {
            return;
        }
        else
        {
            printf("%s\n", candidates[a].name);
        }
    }
    return;
}
