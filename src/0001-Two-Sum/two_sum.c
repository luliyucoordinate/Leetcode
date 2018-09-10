/* Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100;
struct hashtable_item 
{
    int key;
    int value;
    struct hashtable_item *next;
};

int get_hashindex(int key)
{
    key = abs(key);
    return ((key%100));
}

void insert(struct hashtable_item *hashmap[], int num, int loc)
{
    int hash_index;
    struct hashtable_item *temp, *current;
    hash_index = get_hashindex(num);
    
    temp = malloc(sizeof(struct hashtable_item));
    temp->key = num;
    temp->value = loc;
    temp->next = NULL;
    
    if (hashmap[hash_index] == NULL)
    {
        hashmap[hash_index] = temp;
    }        
    else
    {
        current = hashmap[hash_index];
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
}

int get_value(struct hashtable_item *hashmap[], int num)
{
    int hash_index, value;
    struct hashtable_item *current;
    value = INT_MAX;
    //found = 0;
    hash_index = get_hashindex(num);
    current = hashmap[hash_index];
    
    while (current != NULL)
    {
        if (current->key == num)
        {
            //found=1;
            value = current->value;
            break;
        }
        current = current->next;
    }
    return value;
}
int* twoSum(int* nums, int numsSize, int target)
{
    int found;
    //int SIZE = 100;
    struct hashtable_item *hashmap[100];
    int *sum;
    sum = malloc(2*sizeof(int));
    sum[0] = -1;
    sum[1] = -1;
    for (int i = 0; i < 100; ++i)
        hashmap[i] = NULL;

	for (int i = 0; i < numsSize; ++i)
	{
			if (get_value(hashmap, nums[i]) == INT_MAX) //if doesnt exist
            {
                insert(hashmap, target-nums[i], i);
            }					
			else
			{
                found = 1;
                sum[0] = i;
                sum[1] = get_value(hashmap, nums[i]);
                break;
			}
	}
	return sum;
}