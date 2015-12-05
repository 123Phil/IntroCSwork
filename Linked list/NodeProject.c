// ============================================================================
// File: Project1/NodeProject.c
// ============================================================================
// Programmer: Phillip Stewart
// Date: 30 Mar 2012
// Class: CSCI 223 ("C Programming")
// Time: TR 4-6
// Instructor: Mr. Edwards
// Project: Nodes
// Description: jumped the gun...
// ============================================================================



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



// ==== struct Nodle / Nodle ==================================================
typedef
struct Nodle {
	int tint;
	struct Nodle* next;
}Nodle;



// ==== Function Prototypes ===================================================
Nodle*	AddItemSorted(Nodle* first, int hint);
Nodle*	RemoveItem	 (Nodle* first, int hint);
int		PrintNodeInts(Nodle* traverser);
int		ReleaseNodes (Nodle* traverser);



// ==== main ==================================================================
int main(void)
{
	auto Nodle* firstNode = NULL;
	auto char	userChar;
	auto int	nodeVal;
	
	printf("== Please Enter a Char ==\n");
	printf("A - add number R - remove\n");
	printf("P - print list Q - quit\n");
	
	while ((userChar = toupper(getchar()))) 
		{
		switch(userChar) {
			case 'A':
				printf("Enter # to add: ");
				if ( 1 == scanf("%d", &nodeVal) )
					firstNode = AddItemSorted(firstNode, nodeVal);
				else{
					puts("Invalid Input.");
					exit(1);
					}
				break;
			case 'R':
				if (NULL == firstNode)
					{
					puts("No #s to remove...")
					break;
					}
				printf("Enter # to remove from list: ");
				if ( 1 == scanf("%d", &nodeVal) )
					firstNode = RemoveItem(firstNode, nodeVal);
				else{
					puts("Invalid Input.");
					exit(1);
					}
				break;
			case 'P':
				printf("There are %d nodes.\n", PrintNodeInts(firstNode));
				break;
			case 'Q':
				printf("%d nodes released.\n", ReleaseNodes(firstNode));
				puts("Goodbye");
				exit(0);
			default:
				puts("Bad selection");
			}
		getchar();//clearing scanf's junk...
		printf("Menu select (a, r, p, q): ");
		}
	
	return 0;
}// end of main




// ==== AddItemSorted =========================================================
Nodle* AddItemSorted(Nodle* first, int hint)
{
	auto Nodle* newt;
	auto Nodle* trail;
	
	if (NULL == first)
		{
		first = malloc(sizeof(Nodle));
		if (NULL == first)
			{
			puts("malloc err");
			exit(1);
			}
		else{
			first->tint = hint;
			first->next = 0;
			return first;
			}
		}
	
	newt = malloc(sizeof(Nodle));
	if (NULL == newt)
		{
		puts("Item could not be added");
		return first;
		}
	
	newt->tint = hint;
	newt->next = first;
	trail = first;
	
	if (newt->tint < first->tint) return newt;
	else newt->next = newt->next->next;
	
	while(newt)
		{
		if ( NULL == newt->next
		  || newt->next->tint >= newt->tint )
			{
			trail->next = newt;
			return first;
			}
		else{	
			trail = newt->next;
			newt->next = newt->next->next;
			}
		}
		return first;//this safeguard is not necessary
}// end of AddItemSorted



// ==== RemoveItem ============================================================
Nodle* RemoveItem(Nodle* first, int hint)
{	
	auto Nodle* tracker = first;
	auto Nodle* temp;
	
	if (first->tint == hint)
		{
		first = first->next;
		free(tracker);
		return first;
		}
	
	do  {
		if (tracker->next->tint == hint)
			{
			temp = tracker->next;
			tracker->next = tracker->next->next;
			free(temp);
			temp = NULL;
			return first;
			}
		tracker = tracker->next;	
		} while (tracker->next);
	puts("No match found.");
	return first;
}// end of RemoveItem



// ==== PrintNodeInts =========================================================
int PrintNodeInts(Nodle* traverser)
{
	auto int ctr = 0;
	
	printf("Sorted list:\n");
	while (traverser)
		{
		printf(" %5d\n", traverser->tint);
		traverser = traverser->next;
		ctr++;
		}
	
	return ctr;
}// end of PrintNodeInts



// ==== ReleaseNodes ==========================================================
int	ReleaseNodes(Nodle* traverser)
{
	auto Nodle* liberator;
	auto int	ctr = 0;
	
	while (traverser)
		{
		liberator = traverser;
		traverser = traverser->next;
		free(liberator);
		ctr++;
		}
		
	return ctr;
}// end of ReleaseNodes


