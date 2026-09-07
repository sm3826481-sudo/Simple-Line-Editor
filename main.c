#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Function declarations */
void insertLine();
void deleteLine();
void displayDocument();

int main()
{
    char command;

    while (1)
    {
        printf("\n===== SIMPLE LINE EDITOR =====\n");
        printf("i - Insert line\n");
        printf("d - Delete line\n");
        printf("p - Display document\n");
        printf("q - Quit\n");

        printf("Enter command: ");
        scanf(" %c", &command);
        getchar();

        if (command == 'i')
        {
            insertLine();
        }
        else if (command == 'd')
        {
            deleteLine();
        }
        else if (command == 'p')
        {
            displayDocument();
        }
        else if (command == 'q')
        {
            printf("Exiting editor...\n");
            break;
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

/* Insert a new line */
void insertLine()
{
    int position;

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &position);
    getchar();

    /* Valid positions are 1 to lineCount + 1 */
    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines down */
    for (int i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[position - 1], MAX_LENGTH, stdin);

    /* Remove newline from fgets */
    lines[position - 1][strcspn(lines[position - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine()
{
    int position;

    if (lineCount == 0)
    {
        printf("Document is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines up */
    for (int i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Display the document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n===== DOCUMENT =====\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("====================\n");
}